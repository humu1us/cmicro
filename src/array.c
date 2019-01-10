#include <micro/util/array.h>

#include <stdlib.h>

struct array
{
    size_t size;
    size_t used;
    void **data;
};

array_t *array_new(size_t size)
{
    array_t *array = (array_t *)malloc(sizeof(array_t *));

    if (!array)
        return NULL;

    array->size = size;
    array->used = 0;
    array->data = (void **)malloc(sizeof(void *) * size);

    if (!array->data)
    {
        free(array);
        return NULL;
    }

    return array;
}

void array_free(array_t *array)
{
    if (!array)
        return;

    free(array->data);
    free(array);
}
