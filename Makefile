SRC = main.c bst.c readFile.c
OBJ = main.o bst.o readFile.o
PROG = wordfreak

$(PROG): $(OBJ)
	gcc -std=c99 $(OBJ) -o $(PROG)
$(OBJ):$(SRC)
	gcc -c $(SRC)
