#include "Trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* check_letter(char* words) // convert upper case to lower case
{
    int i = 0;
    char *str = strdup(words);

    while (str[i])
    {
        if(str[i] < 65 || str[i] > 123) //delet if
        {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
        }

        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return (str);
}


node* create_node(char *letter) // make new node
{
    node* new_node = (node*)malloc(sizeof(node));
    int i = 0;
    new_node->letter = *letter;
    new_node->count = 0;
    new_node->end_word = false;
    new_node->tag = 0;
    for(i = 0; i < NUM_LETTERS; i++)
    {
        new_node->children[i] = NULL;
    }
    return new_node;
}

node* create_head()
{

    node* n = (node*)malloc(sizeof(node));
    n->count = 0;
    n->end_word = 0;
    for(int i = 0; i < NUM_LETTERS; i++)
    {
        n->children[i] = NULL;
    }
    return n;
}


void insert(node *head, char* str) //insert new node to trie
{

    if (!*str)
        return;
    //char* copy =check_letter(str);
    while (*str)
    {
        // create a new node if path doesn't exists
        if (head->children[*str - 'a'] == NULL)
            head->children[*str - 'a'] = create_node(str);

        // go to next node
        head = head->children[*str - 'a'];

        // move to next character
        str++;
    }
    head->end_word = true;
    head->count++;
}


void print_words(node* root, char word[], int temp){
       
    if (root -> end_word){
        word[temp] ='\0';
        printf("%s", word);
        printf(" %lu\n", root -> count);
    }
    int i;
    for(i = 0; i < NUM_LETTERS; i++){
        if (root -> children[i]){
            word[temp] = i + 'a';
            print_words((root -> children[i]),word,temp + 1);
        }
    }
}



void print_words_R(node* root, char word[], int temp) //print trie in revers
{

    //node* head = *root;
    if(root == NULL)
        return;

    if(root->end_word == true)
    {
        word[temp]='\0';
        printf("%s \t %ld \n",word,root->count);
    }
    for(int i=NUM_LETTERS-1 ; i>= 0; i--)
    {
        if(root->children[i] != NULL)
        {
            word[temp] = i+'a';
            print_words_R((root->children[i]), word, temp+1);
        }
    }
}

void freeTree (node* head){
    for (int i = 0; i < NUM_LETTERS; i++ ){
        if(head -> children[i] != NULL){
            freeTree(head -> children[i]);
        }
    }
    if (head != NULL){
        free(head);
    }
}
