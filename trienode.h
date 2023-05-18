// Copyright 2023 Jeff Chu

#ifndef TRIENODE_H
#define TRIENODE_H

typedef struct trienode trie;
int letToNum(char c);
trie * newNode();
void addNode(trie * root, char * s);
trie * findWord(trie * root, char * str);
void freeTrie(trie * root);

#endif  // TRIENODE_H
