#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("usage: tabs2spaces [FILE]\n");
    } else {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("error: file not found\n");
        } else {
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
                    for (i = 0; i < 4; i++) {
                        putc(' ', fp);
                    }    
                } else {
                    putc(c, fp);
                }
            }
            fclose(fp);
            fclose(tmp);
            remove(tmpstr);
        }
    }
    return 0;
}
