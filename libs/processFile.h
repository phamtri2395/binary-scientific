/**
 * CS3443.G21.CTTT.1
 * processFile.h
 * Assigment 2
 *
 * @author Pham Minh Tri
 * @id 14520999
 * @email phamtri2395@gmail.com
 */

#ifndef _PROCESSFILE_H_
#define _PROCESSFILE_H_

/**
 * Read arguments into elements array & use a long variable as a boolean array of options
 * @param  fileName Name (directory included) of input file
 * @param  elements Array, which contains arguments from input
 * @param  options  Long variable, used as a boolean array
 * @return          int
 */
int read(const char* fileName, float* elements, long* options);

/**
 * Write result to output file
 * @param fileName Name (directory included) of output file
 * @param buffer Ouput buffer as array of strings
 * @param n Number of element from buffer to be written
 */
void write(const char* fileName, char** buffer, int n);

#endif
