#include "bst.h"
#include "readFile.h"

int main(int argc, char*argv[]){
    struct BSTNode *bstArr[26];
    char deLimiter[50] = " *'.?!,:;\n\t1234567890${}[]<>+-=@#%`~'\"";
    char buffer[2000];
    int check = 1;
    int fd;
    int file;
    int fdError;
    int fileError;
    char *word_freak;
    int findMax[2];

    //Initialize the BST array
    for(int i = 0; i < 26; i++){
	bstArr[i] = NULL;
    }
    //Enviornmental Variable handling
    word_freak = getenv("WORD_FREAK");
    if(word_freak != NULL){
	//opens the txt file stored in WORD_FREAK
        fd = open(word_freak, O_RDONLY);
	//opens output.txt
        file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	//checks if the txt file or output.txt opened successfully
	if(!handleError(fd) || !handleError(file)){
	    check = read(fd, buffer, 1999);
            buffer[check] = '\0';
	    //loops through the number of bytes read
            while(check > 0){
		//sets the last index in the buffer to a null terminating character
                if(check <= 1999 && check >= 0){
                    buffer[check] = '\0';
                }
                to_Lowercase(buffer);
                parse(buffer, bstArr, deLimiter, findMax);
                check = read(fd, buffer, 1999);
            }
	    buffer[0] = '\0'; 
	}
    }

    //Command Line handling
    else if(argc > 1){
	//to loop through the arguments passed into the command line
	for(int i = 1; argv[i] != NULL; i++){
	    fd = open(argv[i], O_RDONLY);
            file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	    //checks if the txt file or output.txt opened successfully
	    if(handleError(fd) || handleError(file)){
		continue;
	    }
            check = read(fd,buffer,1999);
	    //loops through the number of bytes read
            while(check > 0) {
	 	//sets the last index in the buffer to a null terminating character
                if(check <= 1999 && check >= 0){
                    buffer[check] = '\0';
                }
                to_Lowercase(buffer);  
                parse(buffer, bstArr, deLimiter, findMax);
                check = read(fd,buffer, 1999);
            }
	    buffer[0] = '\0';
	}
    }
        
    //Terminal/Piping handle
    check = read(STDIN_FILENO, buffer, 1999);
    //checks if the file was read successfully 
    if(check > 0){
	file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	handleError(file);
	//loops through the number of bytes read
        while(check > 0){
	    //sets the last index in the buffer to a null terminating character
            if(check <= 1999 && check >= 0){
                buffer[check] = '\0';
            }
            to_Lowercase(buffer);
            parse(buffer, bstArr, deLimiter, findMax);
            check = read(STDIN_FILENO, buffer, 1999);
        }
	buffer[0] = '\0';
    }

    //prints the bst array to output.txt
    printToOutput(bstArr, file, findMax);
    //closes output.txt and the txt file passed in
    close(fd);
    close(file);
    return 0;
}
