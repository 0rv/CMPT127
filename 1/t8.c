#include <stdio.h>
#include <math.h>

int main(void) {
  int x = 0;
  int y = 0;
  int z = 0; //do we even use this?
  
  scanf("%d %d %d", &x, &y, &z);
  
  //printf("%d %d %d\n",x,y,z);
  
  for (int i = 0; i < x; i++) {
    printf("#");
  }
  if (x > 1 && y > 1) {
    printf("\n");
  }
    
  if (y > 1) {
    for (int i = 2; i < y; i++) {
     if (x > 1) {
       printf("#");
       for (int j = 2; j < x; j++) {
         printf(".");
       }
       printf("#\n");  
     } 
      
    }
    for (int i = 0; i < x; i++) {
      printf("#");
    }
  }
  printf("\n");
  
  return 0;
}
