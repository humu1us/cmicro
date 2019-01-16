#include <micro/util/queue.h>

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    size_t size;
    size_t used;
    size_t head;
    size_t tail;
    void **data;
};

queue_t *queue_new(size_t size)
{
    queue_t *queue = (queue_t *) malloc(sizeof(queue_t));

    if (!queue)
    {
        printf("Error allocating memory for the queue, queue not created\n");
        return NULL;
    }

    queue->size = size;
    queue->used = 0;
    queue->head = 0;
    queue->tail = 0;
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

int queue_push(queue_t *queue, void *item)
{
    if (queue->used == queue->size)
        return 1;

    ++queue->used;
    queue->data[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->size;
    return 0;
}

void *queue_pop(queue_t *queue)
{
    if (queue->used == 0)
    {
        printf("Queue empty\n");
        return NULL;
    }

    void *item = queue->data[queue->head];
    queue->data[queue->head] = NULL;
    queue->head = (queue->head + 1) % queue->size;
    --queue->used;

    return item;
}
