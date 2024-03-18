#include <stdio.h>

int main() {
    unsigned char data = 0; // Inicialmente, nenhum bit está definido

    // Definindo o bit menos significativo
    data |= (1 << 0);

    FILE *file = fopen("file.bin", "wb"); // Abre o arquivo para escrita binária

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(&data, sizeof(data), 1, file); // Escreve o byte no arquivo

    fclose(file);

    return 0;
}
