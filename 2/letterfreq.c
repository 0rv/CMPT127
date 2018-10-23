#include <stdio.h>
#include <string.h>

int main () {
  int tot = 0;
  char temp;
  int ascii = 0;
  int next;
  float cnt[26] = {};
    
  
  //printf("%c\n",tolower(A));
  while (1) {
    next = getchar();
    
    if (next == EOF) {
      
      for (int x = 0; x < 26; x++) {
        ascii = x + 97;
        temp = ascii;
        if (cnt[x] > 0) {
          printf( "%c %.4f\n", temp, cnt[x]/tot);
        }
      }
      return 0;
    }
    ascii = next;
    if (ascii > 64 & ascii < 91) {
      cnt[ascii-65]++;
      tot++;
    }
    if (ascii > 96 & ascii < 123) {
      cnt[ascii-97]++;
      tot++;
    }
    
    
  }
  
  
  return 1;
}