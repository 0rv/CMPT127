#include <stdio.h>
#include <math.h>

int main(void) {
  float i = 0;
  int flag = 0;
  flag = scanf("%f", &i);
  
  if (flag == 0){
    printf("scanf error: (%d)\n",flag);
    return 0;
  }
  int i1 = floorf(i);
  int i2 = roundf(i);
  int i3 = ceilf(i);
  printf("%d %d %d\n",i1,i2,i3);
  return 0;
}
