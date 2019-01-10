#include <micro/util/queue.h>

#include <assert.h>

int main()
{
    queue_t *q = queue_new(6);
    assert(q);
    queue_free(q);
    return 0;
}
