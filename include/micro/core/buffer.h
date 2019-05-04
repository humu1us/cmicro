#ifndef MICRO_BUFFER_H
#define MICRO_BUFFER_H

#include <cstddef>
#include <deque>
#include <memory>

namespace micro
{
    class Message;

    class Buffer
    {
    public:
        Buffer(const std::size_t max_size = 0);

        bool is_empty() const
        {
            return queue.empty();
        }

        bool is_full() const
        {
            return queue.size() >= max_size;
        }

        std::size_t size() const
        {
            return queue.size();
        }

        std::size_t capacity() const
        {
            return max_size;
        }

    protected:
        std::deque<std::unique_ptr<Message *>> queue;
        std::size_t max_size;
    };
}

#endif
