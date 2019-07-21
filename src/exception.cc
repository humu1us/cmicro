#include<micro/core/exception.h>

const char *micro::MicroException::what() const throw()
{
    return "Micro general exception!";
}

const char *micro::BufferOverflow::what() const throw()
{
    return "Micro's buffer overflow!";
}
