/*
 * test.cc - functions, arrays, pointers, image representation
 * Richard Vaughan 2014
 */


#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h> 

#include "intarr.h"
//#include "t1.h"
#include "t2.h"



int main() {
  intarr_t* array = intarr_create(10);
  intarr_t* arr2 = intarr_create(0);


  //printf("%d\n", arr2->len);
  
  int ints[10] = {5, 30, 7, 2, 10, 0, 6, 12, 3, 2147483647};
  //int ints[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  printf("\nold array: ");
  for (int x = 0; x < array->len; x++) {
    intarr_set(array, x, ints[x]);
    printf("%d ", array->data[x]);
  }
  
  
  int ret1 = intarr_save_json(array, "test.json");
  int ret2 = intarr_save_json(arr2, "empty.json");
  
  intarr_t* newarr = intarr_load_json("test.json");
  intarr_t* newarr2 = intarr_load_json("empty.json");
 
  
  printf("\nnew array: ");
  for (int x = 0; x < newarr->len; x++) {
    printf("%d ", newarr->data[x]);
  }
  
  
  printf("\nemp array: ");
  for (int x = 0; x < newarr2->len; x++) {
    printf("%d ", newarr2->data[x]);
  }

  
  return 0;
}

