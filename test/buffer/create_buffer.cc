#include <micro/core/buffer.h>
#include <micro/core/message.h>

#include <assert.h>

int main()
{
    // testing a buffer construct with no size argument
    micro::Buffer buffer = micro::Buffer();
    assert(buffer.size() == 0);
    std::size_t expected = std::deque<std::unique_ptr<micro::Message>>().max_size();
    assert(buffer.capacity() == expected);
    assert(buffer.is_empty() == true);
    assert(buffer.is_full() == false);

    // testing a buffer construct with size argument
    const std::size_t size = 10;
    micro::Buffer buffer_size = micro::Buffer(size);
    assert(buffer_size.size() == 0);
    assert(buffer_size.capacity() == size);
    assert(buffer_size.is_empty() == true);
    assert(buffer_size.is_full() == false);

    return 0;
}
