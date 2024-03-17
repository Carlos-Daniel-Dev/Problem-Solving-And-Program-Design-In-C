typedef struct Node {
    int frequency;
    unsigned char character;
    struct Node* left;
    struct Node* right;
} Node;

FILE *get_file(const char *filename);
char *get_file_text(const char *filename);
int **get_characters_frequency_list(const char *filename);
void print_frequency_list(int **pairs);
int **sort_characters_frequency_list(int **list);

Node *create_node(int frequency, unsigned char character);
Node *build_huffman_tree(int **frequency_list);
void print_huffman_tree(Node *root);