#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SPACE 128

void print_memory(char *memory) {
    for (int i = 0; i < MEMORY_SPACE; i++) {
        printf("%c", memory[i]);
    }
    printf("\n");
}

void set_byte_on_memory(char *memory, int pos, char byte[]) {
    // Calcula o índice onde os bytes devem ser definidos
    int index = pos * 8;
    for (int i = 0; i < 8; i++) {
        memory[index + i] = byte[i];
    }
}

int main() {
    char *memory = (char *) malloc(MEMORY_SPACE * sizeof(char));
    set_byte_on_memory(memory, 0, "01010101");
    print_memory(memory);
    return 0;
}
