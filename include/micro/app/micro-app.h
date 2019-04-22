#ifndef MICRO_APP_H
#define MICRO_APP_H

#include <string>

namespace micro
{
    class MicroApp
    {
    public:
        MicroApp(const std::string &name, const std::string &type);

        virtual Message run(const Message &msg) = 0;

        const std::string get_name() const;
        const std::string get_type() const;
        const std::string get_version() const;
        const std::string get_url() const;
        const std::string get_author() const;
        const std::string get_email() const;
        const std::string get_description() const;
        const std::string get_long_description() const;
        const std::string get_help() const;

    protected:
        std::string name;
        std::string type;
        std::string version;
        std::string url;
        std::string author;
        std::string email;
        std::string description;
        std::string long_description;
        std::string help;
    };
}

#endif
