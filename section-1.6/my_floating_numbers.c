#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SPACE 128

// DATA TYPES
#define INT 0
#define CHAR 1
#define FLOAT 2

void print_memory(char *memory) 
{
    for (int i = 0; i < MEMORY_SPACE; i++) 
    {
        printf("%c", memory[i]);
    }
    printf("\n");
}

void set_byte_on_memory(char *memory, int pos, char *byte) 
{
    int index = pos * 8;
    for (int i = 0; i < 8; i++) 
    {
        memory[index + i] = byte[i];
    }
}

unsigned char binaryToByte(const char *binaryString) {
    unsigned char byte = 0;
    while (*binaryString) {
        byte <<= 1;
        if (*binaryString++ == '1') {
            byte |= 1;
        }
    }
    return byte;
}

unsigned char get_byte_on_memory(char *memory, int pos)
{
    int index = pos * 8;
    char byte[8];
    for (int i = 0; i < 8; i++) 
    {
        byte[i] = memory[index + i];
    }

    return binaryToByte(byte);
}

int main() 
{
    char *memory = (char *) malloc(MEMORY_SPACE * sizeof(char));
    set_byte_on_memory(memory, 0, "01010101");
    
    unsigned char byte = get_byte_on_memory(memory, 0);
    int num = (int)byte;
    
    printf("%d\n", num);
    
    free(memory);
    return 0;
}