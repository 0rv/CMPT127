#include <stdio.h>
#include <math.h>

int main() {
  int x = 0,y = 0, z = 0;
  int left, right = 0;
  scanf("%d %d %d", &x, &y, &z);
  
  //printf("%d %d %d\n",x,y,z);
    

  //base
  /*for (int i = 0; i < y; i++) {
    printf("#");
  }
  printf("\n");
  */
  //base
  //Used the hint for this because I'm, frankly, quite terrible at problem solving

  if (x == 0| y == 0| z == 0) {
    printf("\n");
    return 0;
  }
  
  if (z == 1) {
    for (int j = 0; j < x; j++) {
      printf("#\n"); //still requires the line break?
    }
    return 0;
  }//end case 2
  
  for (int i = z - 1; i != -1; i--) {
    
    left = floor( i * (x/(2.0 * z)));
    right = ceil( (x - 1) + -i * (x/(2.0 * z))); 
  
  
  
    for (int j = 0; j < left; j++) {
      printf(" ");
    }
    printf("#");
    for (int j = left + 1; j < right; j++) {
      if (i == 0 | i == (z - 1)){
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("#\n");
  }
  return 0;
}
