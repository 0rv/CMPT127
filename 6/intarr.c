//intarr.c
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ){
  /*
  if (len <= 0) {
    intarr_t* new = NULL;
    return new;
  }
  */
  
  intarr_t* new = malloc(sizeof(intarr_t));
  new->len = len;
  new->data = malloc(sizeof(int)*(len));

  //new->data[0] = 3;
  
  return new;
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {

  if (ia == NULL) {
    return;
  }
  free(ia->data);
  free(ia);
  
  return;
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (index >= ia->len) {
    return INTARR_BADINDEX;
  }
  ia->data[index] = val;
  return INTARR_OK;
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  if (index >= ia->len) {
    return INTARR_BADINDEX;
  }
  
  *i = ia->data[index];
  return INTARR_OK;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){
  
  intarr_t* new = NULL;
  //intarr_t* new = ia;
  if (ia != NULL) {
    new = intarr_create(ia->len);
    
    for (unsigned int x = 0; x < ia->len; x++) {
      intarr_get(ia, x, &(new->data[x]));
    }
  }
  
  return new;
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  int temp = 0;
  
  for (int x = 0; x < ia->len; x++) {
    for (int y = 0; y < ia->len; y++) {
      if (ia->data[y] > ia->data[x]) {
        temp = ia->data[y];
        ia->data[y] = ia->data[x];
        ia->data[x] = temp;
      }
    }
  }
  
  return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  for (int x = 0; x < ia->len; x++) {
    if (ia->data[x] == target) {
      
      if (i != NULL) {
        *i = x;
      }
      return INTARR_OK;
    }
  }
  
  return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  int* temp = ia->data; //in case we fail to allocate
  
  temp = realloc(temp, (ia->len + 1) * sizeof(int));
  
  if (temp == NULL) {
    return INTARR_BADALLOC;
  }
  
  temp[ia->len] = val;
  
  ia->len ++;
  ia->data = temp;
  
  return INTARR_OK;
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  
  if (ia->len == 0 || ia->data == NULL) {
    return INTARR_BADINDEX;
  }
  
  if (i != NULL) {
    *i = ia->data[ia->len - 1];
  }
  /*
  ia->len--;
  int* temp = realloc(ia->data, ia->len * sizeof(int));
  
  for (int x = 0; x < ia->len; x++) {
    temp[x] = ia->data[x];
  }
  */
  
  ia->len--;
  return INTARR_OK;
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }
  
  int* temp = NULL;
  
  if (newlen <= ia->len) {
    ia->len = newlen;
    
    if (newlen == 0) {
      ia->data = temp;
    }
    
    return INTARR_OK;
  }
  

  temp = realloc(ia->data, newlen * sizeof(int));
  
  for (int x = 0; x < ia->len; x++) {
    temp[x] = ia->data[x];
  }
  
  ia->data = temp;  

  for (int x = ia->len; x < newlen; x++) {
    ia->data[x] = 0;
  }
  
  ia->len = newlen;
  
  return INTARR_OK;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
  intarr_t* new = NULL;
  
  if ((last < first) || (ia == NULL) || (last + 1 > ia->len)) {
    return new;
  }
  new = intarr_create(last-first + 1);
  
  int* temp;
  temp = malloc((last-first + 1) * sizeof(int));
  
  for (int x = first; x < last + 1; x++) {
    temp[x-first] = ia->data[x];
  }
  
  new->data = temp;
  
  return new;
}