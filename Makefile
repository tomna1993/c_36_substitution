CC := gcc
#CFLAGS := 
DEST := ./build/

substitution: substitution.c
	$(CC) substitution.c -lcs50 -o $(DEST)/substitution 