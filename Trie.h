#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM_LETTERS ((int)26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// #define CHAR_TO_INDEX(c) ((int)c - (int)'a')
typedef struct node
{
    char letter; //node key
     long unsigned int count; //count the words
    bool end_word; // 1 when node is a end of word
    int tag; // help for print_word
    struct node* children[NUM_LETTERS]; //arr for 26 letters
}node;
char* check_letter(char* words);
int noChilds(node* n);
node* create_node(char *letter);
node* create_head();
void print_words(node* root, char word[], int temp);
void print_words_R(node* root, char word[], int temp);
void insert(node *head, char* str);
void freeTree (node* head);