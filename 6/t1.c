#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
  if (filename == NULL) {
    return 1;
  }
  
  FILE* f = fopen(filename, "w");
    
  if (ia == NULL) {
    int temp = -1;
    fwrite(&temp, sizeof(int), 1, f);
    return 1; //INTARR_BADARRAY
  }
  

  
  int length = ia->len;
  int* ptr = &length;
  
  fwrite(ptr, sizeof(int), 1, f);
  
  if (ia->len > 0) {
    fwrite(ia->data, sizeof(int), ia->len, f);
  }

  fclose(f);
  
  return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){
  if (filename == NULL) {
    return NULL;
  }
  
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    return NULL;
  }
  

  intarr_t* new = NULL;
  
  int temp;
  int len = 0;
  fread(&len, sizeof(int), 1, f);
  
  if (len < 0) {
    return new; //if we got passed a NULL to begin with
  }
  
  new = intarr_create(len);
  
  for (int x = 0; x < len; x++) {
    fread(&temp, sizeof(int), 1, f);
    
    new->data[x] = temp;
  }

  
  fclose(f);
  
  return new;
}

