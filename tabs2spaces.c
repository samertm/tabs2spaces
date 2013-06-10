#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int expandtab = 4;
    char * filestr;
    if (argc == 1) {
        printf("usage: tabs2spaces [OPTIONS] [FILE]\n");
        printf("options:\n");
        printf("  -t [NUMBER], --tabs [NUMBER]        The number of spaces you want\n");
        printf("                                      tabs to expand to.");
        exit(1);
    } 
    int argp = 1;
    while (argp < argc) {
        if (strcmp(argv[argp], "-t") == 0 ||
                strcmp(argv[argp], "--tabs") == 0) {
            expandtab = atoi(argv[argp + 1]);
            argp += 2;
        } else {
            filestr = argv[argp];
            argp++;
        }
    }

    FILE *fp = fopen(filestr, "r");
    if (fp == NULL) {
        printf("error: file not found\n");
        exit(1);
    } 
    char *tmpstr = malloc(strlen(argv[1]) + 5);
    strcat(tmpstr, argv[1]);
    strcat(tmpstr, ".tmp");
    FILE *tmp = fopen(tmpstr, "w");
    char c;
    while ((c = getc(fp)) && c != EOF) {
        putc(c, tmp);
    }

    freopen(NULL, "w", fp);
    freopen(NULL, "r", tmp);

    int i;
    while ((c = getc(tmp)) && c != EOF) {
        if (c == '\t') {
            for (i = 0; i < expandtab; i++) {
                putc(' ', fp);
            }    
        } else {
            putc(c, fp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove(tmpstr);

    return 0;
}
