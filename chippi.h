/* With .h file we are able to define 
 * all the function prototyping and 
 * libraries to use in a single file.
 * Also this file can be used by other 
 * c files too */

/* whenever we load this file it checks
* if CHIPPI_H is defined, if its the 
* first load CHIPPI_H would not be loaded
* and we can load it using #define CHIPPI_H 
* with all other details in this file. 
* Next time this file is loaded CHIPPI_H 
* would be already loaded and no other 
* data would be loaded because of the 
* derivative #ifndef and #endif */

#ifndef CHIPPI_H
#define CHIPPI_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chippi(void);
char *read_input(void);
void chippi_hello(char *);
void chippi_bye(char *);


#endif
