# t9

The t9 passes exactly one argument and read the words in the file. For each work in it, it is translated into numbers and stored in a trie.
Then the user could enter a sequence of numbers and get the corresponding words in the trie.

To run the program, run the "makefile" file in the terminal first, it will compile all the files needed.

run ./t9 "filename" in the terminal and it will pass the file in and the trie will be build.

Enter a number sequence and the program will show the word that stores in the corresponding position. If no words corresponds to the sequence, the program will show "Not found in current dictionary". You could also enter # to show different words stored in the same position.

The number translater:

2 ABC

3 DEF

4 GHI

5 JKL

6 MNO

7 PQRS

8 TUV

9 WXYZ
