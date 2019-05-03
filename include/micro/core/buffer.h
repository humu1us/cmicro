#ifndef MICRO_BUFFER_H
#define MICRO_BUFFER_H

#include <cstddef>
#include <deque>

namespace micro
{
    class Message;

    class Buffer
    {
    public:
        Buffer(const std::size_t max_size = 0);

        bool is_empty() const;
        bool is_full() const;
        std::size_t size() const;
        std::size_t capacity() const;

    protected:
        std::deque<Message *> queue;
        std::size_t max_size;
    };
}

#endif
