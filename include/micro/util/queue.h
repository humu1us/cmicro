#ifndef MICRO_QUEUE_H
#define MICRO_QUEUE_H

#include <stdlib.h>

struct queue;
typedef struct queue queue_t;

queue_t *queue_new(size_t size);
void queue_free(queue_t *queue);

#endif
