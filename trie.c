// Copyright 2023 Jeff Chu

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include "trienode.h"

// This is the definition of a trie node, consist of a word and its child
// The 0th index of the children array is the linked list that stores the words with same digits
typedef struct trienode {
    char * word;
    struct trienode * children[10];
}trie;


// This method converts the letter into digits
// Input is the letter 
// Outputs the digit
int letToNum(char c) {
    if (c<='c') {
        return 2;
    } else if (c<='f') {
        return 3;
    } else if (c<='i') {
        return 4;
    } else if (c<='l') {
        return 5;
    } else if (c<='o') {
        return 6;
    } else if (c<='s') {
        return 7;
    } else if (c<='v') {
        return 8;
    } else {
        return 9;
    }
}

// This method initializes a new trie node
// Returns the initialized trie node
trie * newNode() {
    trie * cur = (trie*) malloc(sizeof(trie));
    cur -> word = NULL;
    for (int i=0 ; i<10 ; i++) {
        cur -> children[i] = NULL;
    }
    return cur;
}

// This method adds a new word to the trie
// Input "root" is the root of the trie
// Input "s" is the new added word
void addNode(trie * root, char * s) {
    int len = strlen(s);
    for ( int i=0 ; i<len-1 ; i++ ) {
        int tmp = letToNum(s[i]);
        if (root -> children[tmp] == NULL) {
            root -> children[tmp] = newNode();
        }
        root = root -> children[tmp];
    }
    while ( root -> word ) {
        if (!root -> children[0]) {
            root -> children[0] = newNode();
        }
        root = root -> children[0];
    }
    root -> word = (char *) malloc(len+1);
    strncpy(root->word, s, len);
    root->word[len]='\0';
}

// This method finds a word given the digit
// Input "root" is the root of the trie
// Input "str" is the digits the user enters
trie * findWord(trie * root, char * str) {
    for (int i=0; i<strlen(str); i++) {
        char c = str[i];
        if (isdigit(c)) {
            int cur = c-'0';
            if (root -> children[cur]) {
                root = root -> children[cur];
            } else {
                printf("Not found in current dictionary\n");
                return root;
            }
        } else if (c=='#') {
            if (root  -> children[0]) {
                root  = root -> children[0];
            } else {
                printf("There are no more T9onyms\n");
                return root;
            }
        } else {
            printf("invalid input\n");
            return root;
        }
    }
    if (root -> word != NULL) {
        printf("%s", root -> word);
    } else {
        printf("Not found in current dictionary\n");
    }
    return root;
}

// This method frees the trie
// Input is the root of the trie
void freeTrie(trie * root) {
    if (root) {
        for (int i=0; i<10; i++){
            if (root -> children[i]){
                freeTrie(root -> children[i]);
            }
        }
        free(root -> word);
        free(root);
    }
}
