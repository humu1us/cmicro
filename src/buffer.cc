#include <micro/core/buffer.h>

#include <stdexcept>

micro::Buffer::Buffer(const std::size_t size)
    : queue(std::deque<Message *>())
{
    std::size_t _max_size = queue.max_size();
    if (size != 0 && size <= _max_size)
        max_size = size;
    else
        max_size = _max_size;
}

bool micro::Buffer::is_empty() const
{
    return queue.empty();
}

bool micro::Buffer::is_full() const
{
    return queue.size() >= max_size;
}

std::size_t micro::Buffer::size() const
{
    return queue.size();
}

std::size_t micro::Buffer::capacity() const
{
    return max_size;
}
