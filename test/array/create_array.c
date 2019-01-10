#include <micro/util/array.h>

#include <assert.h>

int main()
{
    array_t *arr = array_new(6);
    assert(arr);
    array_free(arr);
    return 0;
}
