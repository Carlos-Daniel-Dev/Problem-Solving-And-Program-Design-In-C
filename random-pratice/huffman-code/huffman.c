#include <stdio.h>

FILE *getfile(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error while open the file");
        return NULL;
    }
    return file;
}

int main ()
{
	getfile("text.txt");
	return 1;
}