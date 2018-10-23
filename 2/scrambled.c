#include <stdio.h>
#include <stdlib.h>

int scrambled(unsigned int a[], unsigned int b[],unsigned int len) {
  //should be O(n) time
  if (len < 1) {
    return 1;
  }
  int freq[100] = {0};
  for (int x = 0; x < len; x++) {
    (freq[a[x]])++;
    (freq[b[x]])--;
  }
  for (int x = 0; x < 100; x++) {
    if (freq[x] != 0) {
      return 0;
    }
  }
  return 1;
}