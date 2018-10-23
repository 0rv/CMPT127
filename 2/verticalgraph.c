#include <stdio.h>
#include <math.h>

int main() {
  int cnt, input = 0;
  int data[80] = {};
  
  int flag = scanf("%d", &data[cnt]);
  int max = data[0];
  while (flag != EOF) {
    cnt++;
    flag = scanf("%d", &data[cnt]);
    
    if (data[cnt] > max) {
      max = data[cnt];
    }
  }//input
  
  for (int y = max; y > 0; y--) {
    for (int x = 0; x < cnt; x++) {
      
      if (data[x] >= y) {
        //MAY CHANGE > TO >=
        printf("#");
      }else {
        printf(" ");
      }
      
    }
    printf("\n");
  }
  
  return 0;
}
