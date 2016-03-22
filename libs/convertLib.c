/**
 * CS3443.G21.CTTT.1
 * convertLib.c
 * Assigment 2
 *
 * @author Pham Minh Tri
 * @id 14520999
 * @email phamtri2395@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "convertLib.h"

union intfloat {
  float f;
  unsigned i;
};

void binary(char *buffer, unsigned n, char times) {
  if (n || times) binary(buffer, n >> 1, times - 1);
  else return;

  if (n & 1)
    buffer[times - 1] = '1';
  else
    buffer[times - 1] = '0';
}

char* toBinary(float number) {
  char *buffer = (char*)malloc(sizeof(char) * 40);

  union intfloat u;
  u.f = number;
  binary(buffer, u.i, 32);

  int curr = 31;
  for (int i = 4; i < 40; i+=4) {
    for (int j = ++curr; j > i; j--) {
      buffer[j] = buffer[j - 1];
    }

    buffer[i] = ' ';
    i++;
  }
  buffer[39] = '\0';

  return buffer;
}

char *toScientific(float number) {
  char *buffer = (char*)malloc(sizeof(char) * 100);
  sprintf(buffer, "%e", number);

  return buffer;
}
