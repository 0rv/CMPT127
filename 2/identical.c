#include <stdio.h>
#include <stdlib.h>

int identical(int a[], int b[], unsigned int len) {
  int flag = 1;
  if (len < 1) {
    return flag;
  }
  for (int x = 0; x < len; x++) {
    if (a[x] != b[x]) {
      flag = 0;
    }
  }
  return flag;
}