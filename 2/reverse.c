#include <stdio.h>
#include <stdlib.h>

void reverse( int arr[], unsigned int len ) {
  int new[len];
  
  for (int x = 0; x < len; x++) {
    new[len-x-1] = arr[x];
  }
  for (int x = 0; x < len; x++) {
    arr[x] = new[x];
  }
  return;
}