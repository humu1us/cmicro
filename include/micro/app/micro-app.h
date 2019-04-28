#ifndef MICRO_APP_H
#define MICRO_APP_H

namespace micro
{
    class Message;
    class MicroApp
    {
    public:
        MicroApp(char *name);

        virtual Message *run(const Message &msg) = 0;

        char *name;
        char **iface_types;
        char *version;
        char *url;
        char *author;
        char *email;
        char *description;
        char *long_description;
        char *help;
    };
}

typedef micro::MicroApp *micro_app_create();
typedef void micro_app_destroy(micro::MicroApp *app);

#endif
