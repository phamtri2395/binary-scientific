/**
 * CS3443.G21.CTTT.1
 * main.c
 * Assigment 2
 *
 * @author Pham Minh Tri
 * @id 14520999
 * @email phamtri2395@gmail.com
 */

#include <stdio.h>
#include "libs/processFile.h"
#include "libs/convertLib.h"

int main (int argc, char* argv) {
  const char *fileIn = "data/Input.txt";
  const char *fileOut = "data/Output.txt";

  // input array
  float elements[64];
  // use as an array of boolean
  long options = 0;
  // output buffer
  char *buffer[64];

  int n = read(fileIn, elements, &options);
  if ((n > 0) && (n < 64)) {
    for (int i = 0; i < n; i++) {
      if ((options >> i) & 1)
        buffer[i] = toScientific(elements[i]);
      else
        buffer[i] = toBinary(elements[i]);

      printf("%s\n", buffer[i]);
    }

    write(fileOut, buffer, n);
  }
  else if (n >= 64)
    printf("Too many data!");
  else
    printf("Error while reading file!");

  return 0;
}
