#include <stdio.h>
#include <stdlib.h>

#define ASCII_CHARACTERS 256

// Definition of a Huffman tree node
typedef struct Node {
    int frequency;
    unsigned char character;
    struct Node* left;
    struct Node* right;
} Node;

// Prototypes

FILE *get_file(const char *filename);
char *get_file_text(const char *filename);
int **get_characters_frequency_list(const char *filename);
void print_frequency_list(int **pairs);
int **sort_characters_frequency_list(int **list);

Node *create_node(int frequency, unsigned char character);
Node *build_huffman_tree(int **frequency_list);
void print_huffman_tree(Node *root);



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

void print_frequency_list(int **pairs) 
{
    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        if (pairs[i][1] != 0) {
            printf("[%c | %d]\n", (char)pairs[i][0], pairs[i][1]);
        }
    }
}

int **sort_characters_frequency_list(int **list) 
{
    int min = -1;
    for (int i = 0; i < ASCII_CHARACTERS; i++)
    {
        for (int j = 0; j < ASCII_CHARACTERS - 1; j++)
        {
            if (list[j][1] > list[j + 1][1])
            {
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

int main() 
{
    int **pairs = get_characters_frequency_list("text.txt");

    pairs = sort_characters_frequency_list(pairs);

    print_frequency_list(pairs);




    // memory free
    for (int i = 0; i < ASCII_CHARACTERS; i++) {
        free(pairs[i]);
    }
    free(pairs);

    return 0;
}
