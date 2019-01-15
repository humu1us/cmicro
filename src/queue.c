#include <micro/util/queue.h>

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    size_t size;
    size_t used;
    void **data;
};

queue_t *queue_new(size_t size)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

    if (!queue)
    {
        printf("Error allocating memory for the queue, queue not created\n");
        return NULL;
    }

    queue->size = size;
    queue->used = 0;
    queue->data = (void **)malloc(sizeof(void *) * size);

    if (!queue->data)
    {
        printf("Error allocating memory for the data, queue not created\n");
        free(queue);
        return NULL;
    }

    return queue;
}

void queue_free(queue_t *queue)
{
    if (!queue)
        return;

    free(queue->data);
    free(queue);
}
