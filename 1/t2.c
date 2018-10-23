#include <stdio.h>

int main(void) {
  //printf("8 8 16 16 32 32 64 128\n");
  printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n",sizeof(char)*8,sizeof(unsigned char)*8,sizeof(int)*8,sizeof(unsigned int)*8,sizeof(long)*8,sizeof(unsigned long)*8,sizeof(float)*8,sizeof(double)*8,sizeof(long double)*8);
  //note to self: read instructions
  return 0;
}
