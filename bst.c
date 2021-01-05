#include "bst.h"

//Initialize the struct BSTNode
struct BSTNode *bstnode(struct BSTNode *left, struct BSTNode *right, int count, char *name){
    struct BSTNode *newbst = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newbst->left = NULL;
    newbst->right = NULL;
    newbst->count = count;
    strcpy(newbst->name, name);
    return newbst;
};

//handle errors for open, close, write, and read
int handleError(int fileDescriptor){
    //checks if file descriptor is -1
    if(fileDescriptor < 0){
	write(STDERR_FILENO, "There is an error opening up a file", 35);
        write(STDERR_FILENO, "\n", 1);
	return 1;
    }
    return 0;       
}

//insert the parsed word alphabetically into the binary search tree and increment count if
//already a part of the tree
struct BSTNode *insert(struct BSTNode *node, char *word){
    int returnValue;
    //checks if root is null
    if(node == NULL){
	node = bstnode(NULL, NULL, 1, word);
	return node;
    }
    //checks if the parsed word is the same as the root's word
    if(node != NULL && strcmp(node->name, word) == 0){
        node->count++;
	return node;
    }
    //returns a negative or positive value depending on which word comes first
    returnValue = strcmp(node->name, word);
    if(returnValue > 0){
	//checks if left child is empty
	if(node->left == NULL){
	    node->left = bstnode(NULL, NULL, 1, word);
	    return node;
	}
	else{
	   //recurse down the left sub tree
	   insert(node->left, word);
	}
    }
    if(returnValue < 0){
	//checks if right child is empty
	if(node->right == NULL){
	    node->right = bstnode(NULL, NULL, 1, word);
	    return node;
	}
	else{
	    //recurse down the right subtree
	    insert(node->right, word);
	}
    }
    return node;

}

//to free the binary search tree
void freeBST(struct BSTNode *node){
    if(node == NULL){
	return;
    }
    //frees the left and right sub trees as well as the root
    freeBST(node->left);
    freeBST(node->right);
    free(node);

}

//write the words and their occurences to output.txt as well as format the output
void printInorder(struct BSTNode *node, char buffer[2000], int file, int findMax[2]){
    static int write_num;
    if(node == NULL){
	return;
    } 
    //recursive call to loop through the left sub tree
    printInorder(node->left, buffer, file, findMax);
    //helps format the words and the number of times they appear in the txt file for ouput.txt
    sprintf(buffer, "%-*s : %*i\n", findMax[0], node->name, findMax[1], node->count);
    //writes the contents of the buffer to output.txt
    write(file, buffer, findMax[0] + findMax[1] + 5);
    //recursive call to loop through the right sub tree
    printInorder(node->right, buffer, file, findMax);
}

//loops through the BST array in order to print the tree at every index
void printToOutput(struct BSTNode *bstArr[26], int file, int findMax[2]){
    char tempBuffer[2000];
    //for loop to loop through the BST array
    for(int i = 0; i < 26; i++){
	printInorder(bstArr[i], tempBuffer, file, findMax);
	freeBST(bstArr[i]);

    }

}
