#include <stdio.h>
#include <math.h>

int main(void) {
  float i = 0;
  scanf("%f", &i);
  int i1 = floorf(i);
  int i2 = roundf(i);
  int i3 = ceilf(i);
  printf("%d %d %d\n",i1,i2,i3);
  return 0;
}
