#ifndef MICRO_BUFFER_H
#define MICRO_BUFFER_H

#include <cstddef>
#include <memory>

namespace micro
{
    class Message;

    class Buffer
    {
    public:
        explicit Buffer(const std::size_t size = 0);
        ~Buffer() noexcept;

        bool is_empty() const;
        bool is_full() const;
        std::size_t size() const;
        std::size_t capacity() const;

        void push(std::unique_ptr<Message> msg);
        std::unique_ptr<Message> pop();

    private:
        class Impl;
        std::unique_ptr<Impl> impl;
    };
}

#endif
