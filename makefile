all: main.o Trie.o frequency
frequency: Trie.o main.o
		gcc -Wall -g -fPIC -o frequency Trie.o main.o -lm
Trie.o: Trie.c Trie.h
		gcc -Wall -g -fPIC -c Trie.c
main.o: main.c Trie.c Trie.h
		gcc -Wall -g -fPIC -c main.c

.PHONY: clean all

clean:	
		rm -f *.o frequency
