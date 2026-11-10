#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE *fp) {
    int count;
    char character;

    

    while(fread(&count, sizeof(count), 1, fp) == 1)  {
        
        if (fread(&character, sizeof(character), 1, fp) != 1) {
            fprintf(stderr, "my-unzip: invalid file\n");
            exit(1);
        }
        // printf("%d", count);
        for (int i = 0; i < count; i++)   {
            // printf("Testprint");
            printf("%c", character);
        }
    };
    return;
}

int main (int argc, char *argv[]) {
    FILE *fp;
    if (argc == 1)  {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
    for (int i = 1; i < argc; i++)  {
        fp = fopen(argv[i], "r");
        if (fp == NULL)  {
            fprintf(stderr, "my-unzip: cannot open file\n");
            exit(1);
        };
        readFile(fp);
        fclose(fp);
    }
    
    return 0;
}