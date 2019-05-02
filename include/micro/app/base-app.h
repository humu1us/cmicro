#ifndef MICRO_BASE_APP_H
#define MICRO_BASE_APP_H

namespace micro
{
    class Message;
    class BaseApp
    {
    public:
        BaseApp(char *name);

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

typedef micro::BaseApp *micro_app_create();
typedef void micro_app_destroy(micro::BaseApp *app);

#endif
