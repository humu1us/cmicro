#include <micro/util/queue.h>

#include <assert.h>

int main()
{
    queue_t *q = queue_new(10);

    int el_1 = 23;
    char el_2 = 'b';
    float el_3 = 5.0556;

    int error;
    error = queue_push(q, &el_1);
    assert(error == 0);
    error = queue_push(q, &el_2);
    assert(error == 0);
    void *pop_1 = queue_pop(q);
    assert(el_1 == *((int *)pop_1));
    error = queue_push(q, &el_3);
    assert(error == 0);
    void *pop_2 = queue_pop(q);
    assert(el_2 == *((char *)pop_2));
    void *pop_3 = queue_pop(q);
    assert(el_3 == *((float *)pop_3));

    int elements[10];
    for (int i = 0; i < 10; i++)
    {
        elements[i] = 100 + i * i;
        error = queue_push(q, &elements[i]);
        assert(error == 0);
    }
    // when the list is full the 'queue_push' must return 1
    error = queue_push(q, &el_1);
    assert(error == 1);

    for (int i = 0; i < 10; ++i)
    {
        int pop = *((int *)queue_pop(q));
        assert(100 + i * i == pop);
    }

    queue_free(q);
    return 0;
}
