#ifndef MICRO_EXCEPTION_H
#define MICRO_EXCEPTION_H

#include <stdexcept>

namespace micro
{
    class MicroException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class BufferOverflow : public MicroException
    {
    public:
        const char *what() const throw();
    };
}

#endif
