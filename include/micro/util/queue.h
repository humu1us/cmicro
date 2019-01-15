#ifndef MICRO_QUEUE_H
#define MICRO_QUEUE_H

#include <stdlib.h>

struct queue;
typedef struct queue queue_t;

queue_t *queue_new(size_t size);
void queue_free(queue_t *queue);
int queue_push(queue_t *queue, void *item);
void *queue_pop(queue_t *queue);

#endif
