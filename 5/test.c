/*
 * test.cc - functions, arrays, pointers, image representation
 * Richard Vaughan 2014
 */
/*
gcc -std=c99 -g -Wall -O3 -I/usr/X11/include  -o dia test.c imgops.c draw.c png.c -lm -lpng -L/usr/X11/lib -lX11 
*/

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h> 

#include "intarr.c"


int main() {
  
  intarr_t* array = intarr_create(10);

  int ints[10] = {5, 3, 7, 2, 10, 0, 6, 12, 3, 1};
  
  for (int x = 0; x < array->len; x++) {
    intarr_set(array, x, ints[x]);
    printf("%d ", array->data[x]);
  }
  printf("\n");
  
  intarr_resize(array, 14);
  
  for (int x = 0; x < array->len; x++) {
    printf("%d ", array->data[x]);
  }
  printf("\n");
  
  return 0;
}

