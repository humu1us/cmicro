#include <micro/core/buffer.h>
#include <micro/core/message.h>

#include <stdexcept>

micro::Buffer::Buffer(const std::size_t size)
    : queue(std::deque<std::unique_ptr<Message>>())
{
    std::size_t _max_size = queue.max_size();
    if (size != 0 && size <= _max_size)
        max_size = size;
    else
        max_size = _max_size;
}

void micro::Buffer::push(std::unique_ptr<micro::Message> msg)
{
    if (is_full())
        throw std::out_of_range("buffer is full");

    queue.push_back(std::move(msg));
}

std::unique_ptr<micro::Message> micro::Buffer::pop()
{
    if (queue.empty())
        return std::unique_ptr<micro::Message>(nullptr);

    std::unique_ptr<micro::Message> msg = std::move(queue.front());
    queue.pop_front();
    return msg;
}
