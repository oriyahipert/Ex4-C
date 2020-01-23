#include "Trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* check_letter(char* words) // convert upper case to lower case
{
    int i = 0;
    char    *str = strdup(words);

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
 //   printf("create_node\n");
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


void insert(node **head, char* str) //insert new node to trie
{
	// start from root node
    node* curr = *head;
	char* copy =check_letter(str);
	while (*copy)
	{
		// create a new node if path doesn't exists
		if (curr->children[*copy - 'a'] == NULL)
			curr->children[*copy - 'a'] = create_node(str);

		// go to next node
		curr = curr->children[*copy - 'a'];

		// move to next character
		copy++;
	}

	curr->end_word = true;
    curr->count++;
}

int getword(char w[]){
    int j = 0;
    char ch = getchar();
    //w[0]=ch;
    while(ch != ' ' && ch != '\t' && ch != '\n' && ch != EOF){
        w[j] = ch;
        j++;
        ch = getchar();
    }
    w[j] = '\0';
    if(ch == EOF){
        return -1;
    }else{
        return j;
    }
}

void print_words(node** root, char word[], int temp) //print trie
{
 node* head = *root;
   if(root == NULL)
      return;
   
   if(head->end_word == true)
   {
        word[temp]='\0';
        printf("%s \t %d \n",word,head->count);
   }
   for(int i=0; i<NUM_LETTERS; i++)
   {
      if(head->children[i] != NULL)
      {
         word[temp] = i+'a';
         print_words(&(head->children[i]), word, temp+1);
      }
   }
}

void print_words_R(node** root, char word[], int temp) //print trie in revers 
{
 node* head = *root;
   if(root == NULL)
      return;
   
   if(head->end_word == true)
   {
        word[temp]='\0';
        printf("%s \t %d \n",word,head->count);
   }
   for(int i=NUM_LETTERS-1 ; i>= 0; i--)
   {
      if(head->children[i] != NULL)
      {
         word[temp] = i+'a';
         print_words(&(head->children[i]), word, temp+1);
      }
   }
}

void freeTree (node** head){
	node* temp= *head;
	for(int i=0; i<NUM_LETTERS; i++){
		if(temp->children == NULL){
			free(temp);
		}
		else{
			freeTree((&temp->children[i]));
		}
	}
	free(temp);
}

