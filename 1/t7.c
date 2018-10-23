#include <stdio.h>
#include <math.h>

int main(void) {
  int i = 0;
  int flag = 1;
  
  while(flag == 1){
  flag = scanf("%d", &i);
  
  if (flag != EOF){
    for (int x = 0; x < i; x++){
      printf("#");
    }
    printf("\n");
  }
}
  return 0;
}
