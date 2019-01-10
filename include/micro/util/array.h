#ifndef MICRO_ARRAY_H
#define MICRO_ARRAY_H

#include <stdlib.h>

struct array;
typedef struct array array_t;

array_t *array_new(size_t size);
void array_free(array_t *array);

#endif
