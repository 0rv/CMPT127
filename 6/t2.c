#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
  if (filename == NULL) {
    return 1;
  }
  
  FILE* f = fopen(filename, "w");
  
  if (ia == NULL) {
    return 1;
  }
  
    
  fprintf(f, "[");
  
  for (int x = 0; x < ia->len; x++) {
    if (x != 0) {
      fprintf(f, ", ");
    }
    fprintf(f, "\n %d", ia->data[x]);
  }
  
  fprintf(f, "\n]");
  fclose(f);
  

  return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){
  if (filename == NULL) {
    return NULL;
  }
  
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    return NULL;
  }
  

  intarr_t* new = NULL;
  new = intarr_create(0);
  
  int flag = 1;
  int temp;
  char bleh;
  
  
  fscanf(f, "[ ");
  

  
  while (1) {
    flag = fscanf(f, " %d ", &temp);
    //printf("%d %d ", flag, temp);
    
    fscanf(f, " %c ", &bleh);
    //printf("%c \n", bleh);

        
    if (bleh == ']') {
      if (new->len != 0) {
        intarr_push(new,temp);
      }
      break;
    }
    intarr_push(new,temp);
  }
  
  fclose(f);
  
  return new;
}




