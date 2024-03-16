#include <stdio.h>

FILE *getfiletext(const char *filename) 
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
	return 1;
}