#include <stdio.h>
#include <stdlib.h>

#include "huffman.h"
#include "json.c"

#define ASCII_CHARACTERS 256


// ================== FILE FUNCTIONS 
FILE *get_file(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error while opening the file");
    }
    return file;
}

char *get_file_text(const char *filename) 
{
    FILE *file = get_file(filename);
    if (file == NULL) return NULL;

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);
    if (content == NULL) {
        fclose(file);
        return NULL;
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0';

    fclose(file);
    return content;
}

// ================= FREQUENCY LIST FUNCTIONS

int **get_characters_frequency_list(const char *filename) 
{
    char *text = get_file_text(filename);
    if (text == NULL) return NULL;

    int **pairs = malloc(sizeof(int *) * ASCII_CHARACTERS);
    if (pairs == NULL) {
        free(text);
        return NULL;
    }

    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        pairs[i] = malloc(sizeof(int) * 2);
        if (pairs[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(pairs[j]);
            }
            free(pairs);
            free(text);
            return NULL;
        }
        pairs[i][0] = i;
        pairs[i][1] = 0;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        pairs[(unsigned char)text[i]][1]++;
    }

    free(text);
    return pairs;
}

int **sort_characters_frequency_list(int **list) 
{
    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        for (int j = 0; j < ASCII_CHARACTERS - 1; j++) {
            if (list[j][1] > list[j + 1][1]) {
                int temp = list[j][1];
                list[j][1] = list[j + 1][1];
                list[j + 1][1] = temp;

                temp = list[j][0];
                list[j][0] = list[j + 1][0];
                list[j + 1][0] = temp;
            }
        }
    }
    return list;
}

// ========================= HUFFMAN TREE FUNCTIONS

Node *create_node(int frequency, unsigned char character, Node *left, Node *right) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error allocating memory for Huffman tree node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->frequency = frequency;
    new_node->character = character;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void free_huffman_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    free_huffman_tree(root->left);
    free_huffman_tree(root->right);
    free(root);
}

Node *build_static_english_huffman_tree()
{
    int frequencies[ASCII_CHARACTERS] = {
        8167, 1492, 2782, 4253, 12702, 2228, 2015, 6094, 6966, 153, 772,
        4025, 2406, 6749, 7507, 1929, 95, 5987, 6327, 9056, 2758, 978,
        2360, 150, 1974, 74, 74, 927, 5051, 3816, 2321, 225, 105,
        236, 4969, 507, 2782, 6423, 2015, 2285, 6023, 6287, 18315, 619,
        596, 5024, 3301, 5545, 775, 1647, 151, 4969, 4688, 5422, 3709,
        1529, 1962, 2722, 12939, 961, 16671, 8167, 3524, 4507, 3042, 3424,
        630, 672, 913, 2536, 162, 1097, 132, 431, 2248, 151,
        812, 4003, 2414, 2602, 1316, 1319, 361, 106, 2722, 42, 272,
        3513, 3816, 3146, 384, 42, 2069, 272, 680, 2015, 193,
        4, 793, 191, 28, 612, 5, 3322, 632, 24, 150,
        24, 1962, 405, 225, 6
    };

    Node *nodes[ASCII_CHARACTERS];
    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        nodes[i] = create_node(frequencies[i], i, NULL, NULL);
    }

    // Building the tree
    while (1) {

        // find the less frequency nodes
        int min1_index = -1, min2_index = -1;
        for (int i = 0; i < ASCII_CHARACTERS; i++) {
            if (nodes[i] != NULL) {
                if (min1_index == -1 || nodes[i]->frequency < nodes[min1_index]->frequency) {
                    min2_index = min1_index;
                    min1_index = i;
                } else if (min2_index == -1 || nodes[i]->frequency < nodes[min2_index]->frequency) {
                    min2_index = i;
                }
            }
        }

        // if just have one node its the root
        if (min2_index == -1) {
            break;
        }

        // create a node with the sum of the smallers nodes
        Node *new_node = create_node(nodes[min1_index]->frequency + nodes[min2_index]->frequency, '\0', nodes[min1_index], nodes[min2_index]);

        // now the nodes are null to do not be considerateds anymore
        nodes[min1_index] = NULL;
        nodes[min2_index] = NULL;

        // replacing one of the nodes with the new node
        for (int i = 0; i < ASCII_CHARACTERS; i++) {
            if (nodes[i] == NULL) {
                nodes[i] = new_node;
                break;
            }
        }
    }

    // Finding and returning the node
    Node *root = NULL;
    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        if (nodes[i] != NULL) {
            root = nodes[i];
            break;
        }
    }

    return root;

}

void find_min_frequencies(Node **nodes, int size, int *min1, int *min2) 
{
    *min1 = -1;
    *min2 = -1;
    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            if (*min1 == -1 || nodes[i]->frequency < nodes[*min1]->frequency) {
                *min2 = *min1;
                *min1 = i;
            } else if (*min2 == -1 || nodes[i]->frequency < nodes[*min2]->frequency) {
                *min2 = i;
            }
        }
    }
}



// Node *build_huffman_tree(int **frequency_list) 
// {
//     Node **nodes = (Node **)malloc(ASCII_CHARACTERS * sizeof(Node *));
//     if (nodes == NULL) {
//         fprintf(stderr, "Error allocating memory for node list.\n");
//         exit(EXIT_FAILURE);
//     }

//     for (int i = 0; i < ASCII_CHARACTERS; i++) {
//         if (frequency_list[i][1] > 0) {
//             nodes[i] = create_node(frequency_list[i][1], (unsigned char)frequency_list[i][0]);
//         } else {
//             nodes[i] = NULL;
//         }
//     }

//     while (1) {
//         int min1, min2;
//         find_min_frequencies(nodes, ASCII_CHARACTERS, &min1, &min2);
//         if (min2 == -1) break;
//         Node *new_node = create_node(nodes[min1]->frequency + nodes[min2]->frequency, '\0');
//         new_node->left = nodes[min1];
//         new_node->right = nodes[min2];
//         nodes[min1] = NULL;
//         nodes[min2] = new_node;
//     }

//     Node *root = NULL;
//     for (int i = 0; i < ASCII_CHARACTERS; i++) {
//         if (nodes[i] != NULL) {
//             root = nodes[i];
//             break;
//         }
//     }

//     free(nodes);
//     return root;
// }


// ====================== FUNCTIONS TO SAVE COMPRESSED TEXTS



int main() 
{
    // int **frequency_list = get_characters_frequency_list("text.txt");
    // frequency_list = sort_characters_frequency_list(frequency_list);

    // Node *root = build_huffman_tree(frequency_list);
    // write_huffman_tree_to_json_file(root);

    Node *root_english_huffman_tree = build_static_english_huffman_tree();
    write_huffman_tree_to_json_file(root_english_huffman_tree); 


    free_huffman_tree(root_english_huffman_tree);
    return 0;
}
