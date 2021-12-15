#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* filename = NULL;
    size_t filename_len;
    
    FILE *file = NULL;
    do {
        printf("Enter filename:\n");
        int result = getline(&filename, &filename_len, stdin);
        if (result < 2)
            continue;
        file = fopen(filename, "w");
        if (!file)
            perror("Couldn't create file");
    } while (!file);
    
    printf("Just type (ESC to exit):\n");
    int c;
    while ((c = fgetc(stdin)) != 27) {
        fputc (c, file);
    }
    fclose(file);
    free(filename);
    
    return 0;
}
