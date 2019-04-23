#ifndef MICRO_MESSAGE_H
#define MICRO_MESSAGE_H

#include <string>

namespace micro
{
    class Message
    {
    public:
        Message(unsigned iface_id,
                const std::string &iface_support,
                const std::string &metadata,
                const std::string &data);

        unsigned get_iface_id() const
        {
            return iface_id;
        }

        const std::string get_iface_support() const
        {
            return iface_support;
        }

        const std::string get_metadata() const
        {
            return metadata;
        }

        const std::string get_data() const
        {
            return data;
        }

    protected:
        unsigned iface_id;
        std::string iface_support;
        std::string metadata;
        std::string data;
    };
}

#endif
