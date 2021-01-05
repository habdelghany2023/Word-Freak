#ifndef BST_H
#define BST_H
#include <stdio.h>
#include "errno.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
//Creation of BSTNode struct
struct BSTNode {
    struct BSTNode* left;
    struct BSTNode* right;
    int count;
    char name[100];
};

//Initialization of struct BSTNode
struct BSTNode *bstnode(struct BSTNode *left, struct BSTNode *right, int count, char *name);

//goal: handle errors for open, close, write, and read
//param fileDescriptor: the integer returned from the open, close, read, and write functions after completion
//return: 0  if the file was sucessfully read, openned, closed, and written. 1 if the file was not
int handleError(int fileDescriptor);

//goal: insert the parsed word alphabetically into the binary search tree and increment count if
//already a part of the tree
//param node: a BSTNode* representing the root of the binary search tree
//param word: a char* representing the parsed word
//return: the root of the binary search tree
struct BSTNode *insert(struct BSTNode *node, char *word);

//goal: write the words and the number of times the appear in the txt files to output.txt as well as format the output
//param node: a BSTNode* representing the root of a binary search tree
//param buffer: an empty buffer to store the words and their counts found in the BST for printing
//param file: a file descriptor for output.txt
//param findMax: an integer array to store the largest digit and the longest word in the binary search tree
//return: Nothing
void printInorder(struct BSTNode *node, char buffer[2000], int file, int findMax[2]);

//goal: loops through the BST array in order to print the tree at every index
//param bstArr: array of BST's for every letter in the alphabet 
//param file: a file descriptor for ouput.txt
//param findMax: an integer array to store the largest digit and the longest word in the binary search tree
//return: Nothing
void printToOutput(struct BSTNode *bsrArr[26], int file, int findMax[2]);

//goal: to free the binary search tree
//param node: BSTNode* representing the root of a binary search tree
//return: Nothing
void freeBST(struct BSTNode *node);

#endif // bst
