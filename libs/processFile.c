/**
 * CS3443.G21.CTTT.1
 * processFile.c
 * Assigment 2
 *
 * @author Pham Minh Tri
 * @id 14520999
 * @email phamtri2395@gmail.com
 */

#include <stdio.h>
#include "processFile.h"

int read(const char *fileName, float *elements, long *options) {
  FILE *fr = fopen(fileName, "r");
  int n = 0;

  if (fr) {
    while (ungetc(fgetc(fr), fr) != EOF) {
      fscanf(fr, "%f", &elements[n]); fgetc(fr);
      int temp;
      fscanf(fr, "%d", &temp); fgetc(fr);
      if (temp == 2) *options |= (1 << n);
      n++;
    }
  }
  else
    return -1;

  fclose(fr);

  return n;
}

void write(const char* fileName, char **buffer, int n) {
  FILE *fw = fopen(fileName, "w");

  for (int i = 0; i < n; i++) {
    fprintf(fw, "%s\n", *(buffer + i));
  }

  fclose(fw);
}
