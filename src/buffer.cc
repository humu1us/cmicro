#include <micro/core/buffer.h>
#include <micro/core/message.h>

#include <deque>
#include <stdexcept>

namespace micro
{
    class Buffer::Impl
    {
    public:
        std::deque<std::unique_ptr<Message>> queue;
        std::size_t max_size;

        Impl(const std::size_t size);

        void push(std::unique_ptr<Message> msg);
        std::unique_ptr<Message> pop();
    };
}

// Implementation
micro::Buffer::Impl::Impl(const std::size_t size)
    : queue(std::deque<std::unique_ptr<Message>>())
    , max_size(size ? size : queue.max_size())
{
}

void micro::Buffer::Impl::push(std::unique_ptr<Message> msg)
{
    if (queue.size() >= max_size)
        throw std::out_of_range("buffer is full");

    queue.push_back(std::move(msg));
}

std::unique_ptr<micro::Message> micro::Buffer::Impl::pop()
{
    if (queue.empty())
        return nullptr;

    auto msg = std::move(queue.front());
    queue.pop_front();
    return msg;
}

// Pimpl
micro::Buffer::Buffer(const std::size_t size)
    : pimpl(std::make_unique<micro::Buffer::Impl>(size))
{
}

micro::Buffer::~Buffer() = default;

bool micro::Buffer::is_empty() const
{
    return pimpl->queue.empty();
}

bool micro::Buffer::is_full() const
{
    return pimpl->queue.size() >= pimpl->max_size;
}

std::size_t micro::Buffer::size() const
{
    return pimpl->queue.size();
}

std::size_t micro::Buffer::capacity() const
{
    return pimpl->max_size;
}

void micro::Buffer::push(std::unique_ptr<Message> msg)
{
    return pimpl->push(std::move(msg));
}

std::unique_ptr<micro::Message> micro::Buffer::pop()
{
    return pimpl->pop();
}
