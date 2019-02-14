#ifndef MICRO_APP_HANDLER_PRIVATE_H
#define MICRO_APP_HANDLER_PRIVATE_H


typedef struct _MicroAppHandlerPrivate MicroAppHandlerPrivate;
typedef struct _MicroApplication MicroApplication;

MicroAppHandlerPrivate *micro_app_handler_private_new(unsigned n_instances);
void micro_app_handler_private_free(MicroAppHandlerPrivate *priv);
void micro_app_handler_private_add(MicroAppHandlerPrivate *priv, MicroApplication *app);

#endif

