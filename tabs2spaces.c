#include <stdio.h>

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("error: file not given\n");
	} else {
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("error: file not found\n");
		} else {
			char c;
			while ((c = getc(fp)) && c != EOF) {
				if (c == '\t') {
					printf("    ");
				} else {
					printf("%c",c);
				}
			}
			fclose(fp);
		}
	}
	return 0;
}
