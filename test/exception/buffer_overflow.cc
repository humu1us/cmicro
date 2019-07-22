#include <micro/core/exception.h>

#include<assert.h>
#include <string>

int main()
{
    std::string error = std::string();
    try
    {
        throw micro::BufferOverflow();
    } catch(micro::BufferOverflow &e)
    {
        error = e.what();
    }
    assert(error == "Micro's buffer overflow!");

    error = "";
    try
    {
        throw micro::BufferOverflow();
    } catch(micro::MicroException &e)
    {
        error = e.what();
    }
    assert(error == "Micro's buffer overflow!");

    return 0;
}
