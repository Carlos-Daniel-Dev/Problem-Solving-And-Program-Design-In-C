#include <stdio.h>
#include <stdlib.h>

#define ASCII_CHARACTERS 256

FILE *get_file(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error while open the file");
        return NULL;
    }
    return file;
}

char *get_file_text(const char *filename)
{
	FILE *file = get_file(filename); 

	fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);
    if (content == NULL) return NULL;

    fread(content, 1, file_size, file);
    content[file_size] = '\0';

    fclose(file);
    return content;
}

int *get_characters_frequency_list(char const *filename)
{
	char* text = get_file_text(filename);
	int static list[ASCII_CHARACTERS];

	for (int i = 0; i != '\0'; i++)
	{
		list[text[i]]++;
	}

	return list;
}

void print_frequency_list(int list[])
{
    for (int i = 0; i < ASCII_CHARACTERS; i++) 
    {
        if (list[i] != 0) {
            printf("[%c | %d]\n", (char)i, list[i]);
        }
    }
}


int main ()
{
	int *list = get_characters_frequency_list("text.txt");
	print_frequency_list(list);
	return 1;
}