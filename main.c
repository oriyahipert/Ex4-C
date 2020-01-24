
#include "Trie.h"
#include <string.h>
int main(int argc, char *argv[]){
    node* root = create_head();
    int index = 0;
    int max = 0;
    char* word = (char*)malloc(sizeof(char)*2); 
    if (word == NULL){
        perror("malloc error");
    }
    *word = 0;
    *(word+ 1) = 0;  
    char letter;
        while (scanf("%c",&letter) == 1 ){
        if(letter != '\0' && letter != '\t' && letter != '\n' && letter != ',' && letter != ' '){
            word[index] = letter;
            index++;   
            word = (char*)realloc(word,index + 2);  
              if (word == NULL){
                  perror("malloc error");
                 }
            for (int i = index; i < index + 2; i++){
                *(word + i) = 0;
            }       
        }else{
            insert(root,word);
            printf("in\n");
            free(word);
            printf("f/n");
            word = (char*)malloc(sizeof(char)*2);
              if (word == NULL){
                  perror("malloc error");
                 }
                *word = 0;
             *(word+ 1) = 0; 
            if (index >= max){
                max = index;
            }
            index = 0;
        } 
      }
        if (index > 0){
            insert(root,word);
            free(word);
        }
        if (index == 0){
            free(word);
        }
        char length[max];
    if (argc == 1){
        print_words(root,length,0);
        printf("pppp/n");
    }else if(argc == 2){
         if (strcmp(argv[1],"r")==0){
         print_words_R(root,length,0);
         printf("rrrrr/n");
         }
    }
         freeTree(root);
    return 0;
}


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "Trie.h"
// #define MAX 35

// int main(int argc, char* argv[]){

//    int print_R=0;
//    int size = 256;
//    int count = 0;
//    int test = 0;
//    char* word = (char*)malloc(sizeof(char)*256);
//    char* temp = NULL;
//    char c = getchar();
//    node* head = create_head();
   
//      if(argc == 2 && strcmp(argv[1],"r")==0)
//      print_R = 1;

//      while(c!=EOF || (c==EOF && test!= 1)){
//          if(c>=65 && c<=90){
//              c=c+32;
//              }
//          //  check_letter(c);
//          if( c!=' ' && c!= '\n' && c!='\0' && c!='\t'){
//              if(count==size){
//                  temp=(char*)realloc(word,(size+MAX)*sizeof(char));
//                  size+=MAX;
//                  if(temp==NULL&& word!=NULL){
//                      free(word);
//                      return -1;
//              } 
//                 word=(char*)calloc(size,sizeof(char));
//                 strcpy(word,temp);
//                 free(temp);
//              }
        
//              word[count]=c;
//              count++;
            
             
//          }
//          if((c==' ' || c=='\n' || c=='\t' || c=='\0') && c!=EOF){
//              word[count]='\0';
//              if(word[0]!=' ' && count>=1){
//              insert(&head,word);
//              }
//              count=0;
//          }
//         if(c==EOF)
//          test=1;
//        c=getchar();
//      }

    
//    if(print_R == 1) {
//        print_words_R(&head,word,0);
//    }
//    else {
//        print_words(&head,word,0);
//    }
//     freeTree(&head);
//     free(word);
   

// return 0;
// }