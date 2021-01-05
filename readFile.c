
#include "readFile.h" 

//convert the first letter of every parsed word to a number corresponding to a specific index in the BST array (hash function)
int letterToIndex(char letter){
    //takes the letter passed in and subtracts it by 97(which is the ascii number for a) to form an index
    int temp = letter - 'a';
    return temp;
}
void to_Lowercase(char *buffer){
    for(int i = 0; i < strlen(buffer); i++){
	//checks if the letter is uppercase
        if(buffer[i] >= 65 && buffer[i] <= 90)
	     //adds 32 to change it to lowercase
             buffer[i] = buffer[i] + 32;
    }
}

//find the largest digit and longest word in the BST
void findLargest(int findMax[2], int wordIndex, int counter){
    int digit = 0;
    //checks if the length of the word stored in index 0 is less than the new length of word passed into the function
    if(findMax[0] < wordIndex){
        findMax[0] = wordIndex;
    }
    //converts the word count to digits for formatting purposes
    while(counter != 0){
        counter = counter/10;
        digit++;
    }
    //checks if the number stored in index 1 is less than the new number formed
    if(findMax[1] < digit){
        findMax[1] = digit;
    }
} 

//parse a word in the buffer array and insert that word into the correct tree as well as increment count if the word is the same as the root
void parse(char buffer[2000], struct BSTNode *BSThead[26], char deLimiter[50], int findMax[2]){
    static char currentWord[100];
    static int wordIndex = 0;
    static int counter = 0;
    static int index;
    static int returnValue;
    //loops through the buffer array
    for(int i = 0; i < 2000 && buffer[i] != '\0'; i++){
	bool isDelimiter = false;
	for(int j = 0; j < strlen(deLimiter); j++){
	    //checks if the buffer at the index is equal to a delimiter or if it is not an alphabetic character
            if(buffer[i] == deLimiter[j] || isalpha(buffer[i]) == 0){
		isDelimiter = true;
                break;
            }
        }
	if(isDelimiter){
	    //adds a null character to signify the end of a word
            currentWord[wordIndex] = '\0';
	    //calls findLargest to keep track of the longest word
	    findLargest(findMax, wordIndex, counter);
	    //checks if the current word is just a null character to it won't try and insert a delimiter as a word
	    if(currentWord[0] == '\0'){
		continue;
	    }
	    //converts the first letter of the current word to an index(hash function)
            index = letterToIndex(currentWord[0]);
	    //checks to see if the root is not empty
            if(BSThead[index] != NULL){
		//returns a negative or positive value depending on which word comes first
                returnValue = strcmp(BSThead[index]->name, currentWord);
                if(returnValue > 0){
		    //inserts the parsed word into the left sub tree
                    BSThead[index]->left = insert(BSThead[index]->left, currentWord);
                    wordIndex = 0;
                }
                if(returnValue < 0){
		    //inserts the parsed word into the right sub tree
                    BSThead[index]->right = insert(BSThead[index]->right, currentWord);
                    wordIndex = 0;
                }
                if(returnValue == 0){
		    //increments the count if the parsed word is equal to the root word
                    counter = BSThead[index]->count++;
		    //to keep track of the word that appears the most in the txt file
		    findLargest(findMax, wordIndex, counter);
                    wordIndex = 0;
                }
            }
            else{
		//adds the word to the head of the BST
                BSThead[index] = insert(BSThead[index], currentWord);
                wordIndex = 0;
            }
        }
        else{
	    //adds the letter in buffer to the current word array
            currentWord[wordIndex] = buffer[i];
            wordIndex++;
	    
        }
    }
}
