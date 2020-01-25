#include "Trie.h"
#include <string.h>
int main(int argc, char *argv[]){
    node* root = create_head();
    int start = 0;
    int index = 0;
    char* word = (char*)malloc(sizeof(char)*2); 
    if (word == NULL){
        printf("Error");
    }
    *word = 0;
    *(word+ 1) = 0;  
    char letter;
        while ((letter = getc(stdin) )!= EOF){
        if(letter != '\0' && letter != '\t' && letter != '\n' && letter != ',' &&letter != ' '){
            if(!((letter >= 'A' && letter<= 'Z') || (letter>='a' && letter<='z'))){

                continue;
            }
            word[start] = letter;
            start++;   
            word = (char*)realloc(word,start + 2);  
              if (word == NULL){
                printf("Error");
                 }
            for (int i = start; i < start + 2; i++){
                *(word + i) = 0;
            }       
        }
        else{
            insert(root,word);
            free(word);
            word = (char*)malloc(sizeof(char)*2);
              if (word == NULL){
                  printf("Error");
                 }
                *word = 0;
             *(word+ 1) = 0; 
            if (start >= index){
                index = start;
            }
            start = 0;
        } 
      }
        if (start > 0){
            insert(root,word);
            free(word);
        }
        if (start == 0){
            free(word);
        }
        char* length = (char*) malloc(sizeof(char) * index);
    if (argc == 1){
        print_words(root,length,0);
    }else if(argc == 2){
         if (strcmp(argv[1],"r")==0){
         print_words_R(root,length,0);
         }
    }
    free(length);
         freeTree(root);
    return 0;
}