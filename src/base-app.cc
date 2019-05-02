#include <micro/app/base-app.h>


micro::BaseApp::BaseApp(char *name)
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
