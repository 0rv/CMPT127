#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  //we use word detection from count.c because they are defined the same
  char temp[128] = {};
  char next;
  int ascii = 0;
  int wordlen = 0;
  int flag = 0;
  
  //no arg case case
  
  if (argc < 2) {
    while (1) {
      next = getchar();
      if (next == EOF) {
        return 0;
      }
      printf("%c",next);
    }
  }
  
  //arg case
  while(1) {
    next = getchar();
    ascii = next;
    //printf("%c",next);
    //debug line
    if (next == EOF) {
      return 0;
    }
    if ((ascii > 64 & ascii < 91) | (ascii > 96 & ascii < 123) | (ascii == 39)) {
      //word-like characters
      temp[wordlen] = next;
      wordlen++;
    }else{
      
      
      for (int x = 0; x < (argc-1);x++) {
        //for loop; checking by each word replacement
        for (int j = 0; j < wordlen; j++) {
          //this is our word
          if (argv[x+1][j] != temp[j]) {
            break;
          }
          if (j == (wordlen - 1)) {
            flag = 1;
          } 
        }  
      }
      
      if (flag == 0) {
        for (int x = 0; x < wordlen; x++) {
          printf("%c",temp[x]);
        }
      } else {
        printf("CENSORED");
      }
      
      printf("%c",next);
      wordlen = 0;
      flag = 0;
      
    }
  }
  return 1;
}