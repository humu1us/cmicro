#include <micro/core/message.h>


micro::Message::Message(unsigned iface_id,
                        const std::string &iface_support,
                        const std::string &metadata,
                        const std::string &data)
    : iface_id(iface_id)
    , iface_support(iface_support)
    , metadata(metadata)
    , data(data)

{
}
