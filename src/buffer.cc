#include <micro/core/buffer.h>
#include <micro/core/message.h>

#include <deque>
#include <stdexcept>

namespace micro
{
    class Buffer::Impl
    {
    public:
        Impl(const std::size_t size);

        bool is_empty() const;
        bool is_full() const;
        std::size_t size() const;
        std::size_t capacity() const;

        void push(std::unique_ptr<Message> msg);
        std::unique_ptr<Message> pop();

    private:
        std::deque<std::unique_ptr<Message>> queue;
        std::size_t max_size;
    };
}

// Implementation
micro::Buffer::Impl::Impl(const std::size_t size)
    : queue(std::deque<std::unique_ptr<Message>>())
    , max_size(size ? size : queue.max_size())
{
}

bool micro::Buffer::Impl::is_empty() const
{
    return queue.empty();
}

bool micro::Buffer::Impl::is_full() const
{
    return queue.size() >= max_size;
}

std::size_t micro::Buffer::Impl::size() const
{
    return queue.size();
}

std::size_t micro::Buffer::Impl::capacity() const
{
    return max_size;
}

void micro::Buffer::Impl::push(std::unique_ptr<Message> msg)
{
    if (is_full())
        throw std::out_of_range("buffer is full");

    queue.push_back(std::move(msg));
}

std::unique_ptr<micro::Message> micro::Buffer::Impl::pop()
{
    if (queue.empty())
        return std::unique_ptr<micro::Message>(nullptr);

    std::unique_ptr<micro::Message> msg = std::move(queue.front());
    queue.pop_front();
    return msg;
}

// Pimpl
micro::Buffer::Buffer(const std::size_t size)
    : impl(std::make_unique<micro::Buffer::Impl>(size))
{
}

micro::Buffer::~Buffer() = default;

bool micro::Buffer::is_empty() const
{
    return impl->is_empty();
}

bool micro::Buffer::is_full() const
{
    return impl->is_full();
}

std::size_t micro::Buffer::size() const
{
    return impl->size();
}

std::size_t micro::Buffer::capacity() const
{
    return impl->capacity();
}

void micro::Buffer::push(std::unique_ptr<Message> msg)
{
    return impl->push(std::move(msg));
}

std::unique_ptr<micro::Message> micro::Buffer::pop()
{
    return impl->pop();
}
