#include <stdio.h>
#include <string.h>

int main() {
  //use getchar()
  char next;
  int flag = 0;//tried bool, it didn't like it
  unsigned long lines = 0;
  unsigned long words = 0;
  unsigned long chars = 0;
  int ascii = 0;
  
  
  while (1) {
    next = getchar();
    
    //printf("%c",next);
    //debug line
    
    if (next == EOF) {
      
      printf("%lu %lu %lu\n",chars,words,lines);
      
      return 0;
    }
    chars++;

    
    if (next == '\n') {
      lines++; // detects lines, bit harder - we assume at least one line
    }
    //word detection
    ascii = next;
    
    if ((ascii > 64 & ascii < 91) | (ascii > 96 & ascii < 123) | (ascii == 39)) {
      
      //catches word-like strings (A-Z, a-z, .)
      if (flag == 0) {
        words++; // increment words
      }
      flag = 1;
    } else {
      flag = 0;
    }
    
    //printf("%c",next);
  }
  return 1;//if we don't hit EOF
}