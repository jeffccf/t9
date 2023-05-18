
// Copyright 2023 Jeff Chu

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include "trienode.h"

int main(int argc, char** argv) {
    FILE * fin;
    int BUFFERSIZE = 32;
    char line[BUFFERSIZE];

    if (argc<=1) {
        fprintf(stderr, "There should be at least one input file.\n");
        exit(1);
    }
    if ((fin = fopen(argv[1], "r"))==NULL) {
        fprintf(stderr, "%s will not open.\n", argv[1]);
        exit(1);
    }

    if (ferror(fin)) {
        fprintf(stderr, "fopen failed\n");
        fclose(fin);
        exit(1);
    }

    trie * root = newNode();

    while (fgets(line, BUFFERSIZE, fin)) {
        //line[strcspn(line, "\n")] = '\0';
        addNode(root, line);
    }

    fclose(fin);
    trie * cur = newNode();
    while (1) {
        printf("Enter Key Sequence (or \"#\" for next word):");
        scanf("%s", line);
        if (strcmp(line, "exit")==0) {
            freeTrie(root);
            return 0;
        } else if (line[0]=='#') {
            cur = findWord(cur, line);
        } else {
            cur = findWord(root, line);
        }
    }
    return 0;
}
