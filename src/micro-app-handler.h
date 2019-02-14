#ifndef MICRO_APP_HANDLER_H
#define MICRO_APP_HANDLER_H

typedef struct _MicroAppHandler MicroAppHandler;
typedef struct _MicroAppHandlerPrivate MicroAppHandlerPrivate;

struct _MicroAppHandler
{
    MicroAppHandlerPrivate *priv;
    char *name;
};


MicroAppHandler *micro_app_handler_new(unsigned n_instances);
void micro_app_handler_free(MicroAppHandler *hnd);

#endif
