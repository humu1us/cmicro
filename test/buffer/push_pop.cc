#include <micro/core/buffer.h>
#include <micro/core/message.h>
#include <micro/core/exception.h>

#include <assert.h>

int main()
{
    micro::Buffer buffer(2);
    assert(buffer.is_empty());
    assert(!buffer.is_full());
    assert(buffer.size() == 0);

    auto msg_1 = std::make_unique<micro::Message>(micro::Message(1, "", "", ""));
    assert(msg_1);
    assert(msg_1->get_iface_id() == 1);

    buffer.push(std::move(msg_1));
    assert(!msg_1);
    assert(!buffer.is_empty());
    assert(!buffer.is_full());
    assert(buffer.size() == 1);

    auto msg_2 = std::make_unique<micro::Message>(micro::Message(2, "", "", ""));
    assert(msg_2);
    assert(msg_2->get_iface_id() == 2);

    buffer.push(std::move(msg_2));
    assert(!msg_2);
    assert(!buffer.is_empty());
    assert(buffer.is_full());
    assert(buffer.size() == 2);

    auto msg_3 = std::make_unique<micro::Message>(micro::Message(3, "", "", ""));
    assert(msg_3);
    assert(msg_3->get_iface_id() == 3);

    std::string error = std::string();
    try
    {
        buffer.push(std::move(msg_3));
    } catch (micro::BufferOverflow &e)
    {
        error = e.what();
    }
    assert(error == "Micro's buffer overflow!");
    assert(!msg_3);

    std::unique_ptr<micro::Message> msg_1_ = buffer.pop();
    assert(msg_1_->get_iface_id() == 1);
    assert(!buffer.is_empty());
    assert(!buffer.is_full());
    assert(buffer.size() == 1);

    std::unique_ptr<micro::Message> msg_2_ = buffer.pop();
    assert(msg_2_->get_iface_id() == 2);
    assert(buffer.is_empty());
    assert(!buffer.is_full());
    assert(buffer.size() == 0);

    std::unique_ptr<micro::Message> msg_3_ = buffer.pop();
    assert(!msg_3_);
    assert(buffer.is_empty());
    assert(!buffer.is_full());
    assert(buffer.size() == 0);

    return 0;
}
