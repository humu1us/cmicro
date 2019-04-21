#ifndef MICRO_APP_H
#define MICRO_APP_H

class Message;

struct _MicroApp
{
    int (*init) (void);
    Message * (*run) (Message *);
    void (*free) (void);
    char *type;
    char *name;
    char *version;
    char *url;
    char *author;
    char *email;
    char *description;
    char *long_description;
    char *help;
};

typedef struct _MicroApp MicroApp;

#endif
