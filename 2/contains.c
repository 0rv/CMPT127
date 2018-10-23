//#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  //we use argv[1] and argv[2]
  
  char test[] = {};
  
  char *str1 = argv[1];
  char *str2 = argv[2];
  int flag = 0;
  
  int len1 = strlen(argv[1]);
  int len2 = strlen(argv[2]);
  
  //printf("%s\n%s",str1,str2);
  
  for (int x = 0; x < len1; x++) {
    if (str1[x] == str2[0]) {
      int j = 1;
      if (len2 < 2) {
        printf("true\n");
        return 0;
      }
      while (x+j <= len1 & str1[x+j] == str2[j]) {
        if (j == len2) {
          printf("true\n");
          return 0;
        }
        j++;
      }
    }
  }
  printf("false\n");
  return 0;
}