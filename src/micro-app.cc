#include <micro/app/micro-app.h>


micro::MicroApp::MicroApp(const std::string &name, const std::string &type)
    : name(name)
    , type(type)
{
}

const std::string micro::MicroApp::get_name() const
{
    return name;
}

const std::string micro::MicroApp::get_type() const
{
    return type;
}

const std::string micro::MicroApp::get_version() const
{
    return version;
}

const std::string micro::MicroApp::get_url() const
{
    return url;
}

const std::string micro::MicroApp::get_author() const
{
    return author;
}

const std::string micro::MicroApp::get_email() const
{
    return email;
}

const std::string micro::MicroApp::get_description() const
{
    return description;
}

const std::string micro::MicroApp::get_long_description() const
{
    return long_description;
}

const std::string micro::MicroApp::get_help() const
{
    return help;
}
