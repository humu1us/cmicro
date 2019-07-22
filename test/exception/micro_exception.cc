#include <micro/core/exception.h>

#include<assert.h>
#include <string>

int main()
{
    std::string error = std::string();
    try
    {
        throw micro::MicroException();
    } catch(micro::MicroException &e)
    {
        error = e.what();
    }
    assert(error == "Micro general exception!");

    error = "";
    try
    {
        throw micro::MicroException();
    } catch(std::exception &e)
    {
        error = e.what();
    }
    assert(error == "Micro general exception!");

    return 0;
}
