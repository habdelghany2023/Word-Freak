#ifndef READFILE_H
#define READFILE_H
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//goal: to convert the first letter of every parsed word to a number corresponding to a specific index in the BST array (hash function)
//param letter: a char letter representing the first letter of the parsed word
//return: a number representing an index in the array of BST's
int letterToIndex(char letter);

//goal: to find the largest digit and longest word in the BST
//param findMax: an integer array to store the largest digit and the longest word in the BST
//param wordIndex: the length of the current word being parsed
//param counter: to store the number of times a word has appeared in the BST
//return: Nothing 
void findLargest(int findMax[2], int wordIndex, int counter);

//goal: to turn the entire .txt file to lowercase for easier parsing
//param buffer: a char * representing the buffer array that stores the contents of the .txt file
//return: Nothing
void to_Lowercase(char *buffer);

//goal: to parse a word in the buffer array and insert that word into the correct tree as well as increment count if the word is the same as the root
//param buffer: a character array containing the contents of the whole text file
//param bstArr: array of BST's for every letter in the alphabet 
//param deLimiter: a char array containing the common delimiters seen in a text file
//param findMax: an integer array to store the largest digit and the longest word in the binary search tree
//return Nothing 
void parse(char buffer[2000], struct BSTNode *bstArr[26], char deLimiter[50], int findMax[2]);


#endif // readFile
