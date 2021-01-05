# Word-Freak
For this project, I split the program into 3 .c files. The first is main.c where the different ways of reading files are handled. The second is bst.c where the BST to
store words is created and features methods such as insert and inOrderTraversal. The final is readFile.c where the parsing as well as the “hash function” takes place.

Main.c is split into 2 “if” statements to determine which input method has been chosen by the user. The third block of code refers to terminal/piping which is another form of 
input. From there each “if” statement (as well as terminal/piping) has its own block of code that loops through the text file turning it all to lowercase. From there it is passed into a parse method where the text file is split into words and added to the appropriate BST based on the “hash function”(letterToIndex) found in the parse method. This hash 
function turns the first letter of the word into an index that is then mapped to the appropriate tree in the array of BST's. The tree is an array of BST’s that has a size of 26, 
one for each letter of the alphabet. From there, the parse method completes the splitting of the text file and adding the words as well as the number of times they appeared in thetext file to the appropriate BST. Afterward, the contents of the 26 BST’s are printed to output.txt signifying the end of the program.



Video Demonstration:
https://www.youtube.com/watch?v=9Tj_qwoa9oE&feature=youtu.be
