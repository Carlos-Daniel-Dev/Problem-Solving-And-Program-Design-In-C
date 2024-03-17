#include <stdio.h>
#include <stdlib.h>

void write_node_to_json(FILE *file, Node *node, int indent_level) {
    if (node == NULL) {
        fprintf(file, "null");
        return;
    }

    fprintf(file, "{\n");
    fprintf(file, "%*s\"frequency\": %d,\n", indent_level * 2, "", node->frequency);
    fprintf(file, "%*s\"character\": \"%c\",\n", indent_level * 2, "", node->character);
    fprintf(file, "%*s\"left\": ", indent_level * 2, "");
    write_node_to_json(file, node->left, indent_level + 1);
    fprintf(file, ",\n");
    fprintf(file, "%*s\"right\": ", indent_level * 2, "");
    write_node_to_json(file, node->right, indent_level + 1);
    fprintf(file, "\n%*s}", (indent_level - 1) * 2, "");
}

void write_huffman_tree_to_json_file(Node *root) {

    FILE *file = fopen("huffman.json", "w");
    if (file == NULL) {
        fprintf(stderr, "Error to open the file huffman.json\n");
        return;
    }

    fprintf(file, "{\n");
    fprintf(file, "  \"root\": ");
    write_node_to_json(file, root, 2);
    fprintf(file, "\n}\n");

    fclose(file);
}