#include <stdio.h>
#include <math.h>

int main(void) {
  float i = 0;
  float max = 0;
  float min = 0;
  float tot = 0;
  int cnt = 0;
  
  while (1){
  int flag = scanf("%f", &i);
  
  if (flag == EOF){
    printf("%.2f %.2f %.2f\n",min,max,tot/cnt);
    return 0;
  }
  if (max < i | max == 0){
    max = i;
  }
  if (min > i | min == 0){
    min = i;
  }
  cnt++;
  tot += i;
}
}
