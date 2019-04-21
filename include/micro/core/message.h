#ifndef MICRO_MESSAGE_H
#define MICRO_MESSAGE_H

#include <string>

namespace micro
{
    class Message
    {
    public:
        Message(unsigned iface_id,
                unsigned iface_type,
                const std::string &metadata,
                const std::string &data);

    protected:
        unsigned iface_id;
        unsigned iface_type;
        std::string metadata;
        std::string data;
    };
}

#endif
