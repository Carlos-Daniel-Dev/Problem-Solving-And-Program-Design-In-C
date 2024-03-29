#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SPACE 128

#define LOWER_MEMORY_ADRESS 0
#define HIGHER_MEMORY_ADRESS MEMORY_SPACE - 1

// DATA TYPES
#define INT 0
#define CHAR 1
#define FLOAT 2

char memory[MEMORY_SPACE];


void print_memory() 
{
    for (int i = 0; i <= HIGHER_MEMORY_ADRESS; i++) 
    {
        printf("%c", memory[i]);
    }
    printf("\n");
}

void set_byte_on_memory(int pos, const char *byte) 
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

unsigned char get_byte_on_memory(int pos)
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
    set_byte_on_memory(0, "1111");
    
    unsigned char byte = get_byte_on_memory(0);
    int num = (int)byte;
    
    printf("%d\n", num);
    return 0;
}