#include <micro/app/micro-app.h>


micro::MicroApp::MicroApp(char *name)
    : name(name)
    , iface_types(nullptr)
    , version(nullptr)
    , url(nullptr)
    , author(nullptr)
    , email(nullptr)
    , description(nullptr)
    , long_description(nullptr)
    , help(nullptr)
{
}
