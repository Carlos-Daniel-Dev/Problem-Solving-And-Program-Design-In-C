#include <stdio.h>
#include <stdlib.h>
FILE *getfile(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error while open the file");
        return NULL;
    }
    return file;
}

char *getfiletext(const char *filename)
{
	FILE *file = getfile(filename); 

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

int main ()
{
	printf("%s\n", getfiletext("text.txt"));
	return 1;
}