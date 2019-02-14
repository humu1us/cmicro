#include "micro-app-handler.h"
#include "micro-app-handler-private.h"
#include <micro/application/micro-application.h>

#include <glib.h>

struct _MicroAppHandlerPrivate
{
    GArray *instances;
};


MicroAppHandlerPrivate *micro_app_handler_private_new(unsigned n_instances)
{
    MicroAppHandlerPrivate *priv = NULL;
    priv = (MicroAppHandlerPrivate *) malloc(sizeof(MicroAppHandlerPrivate));

    if (!priv)
        return NULL;

    priv->instances = g_array_sized_new(FALSE, FALSE, sizeof(MicroApplication *), n_instances);

    return priv;
}


void micro_app_handler_private_free(MicroAppHandlerPrivate *priv)
{
    if (!priv)
        return;

    GArray *arr = priv->instances;
    MicroApplication *app = NULL;

    for (unsigned i = 0; i < arr->len; ++i)
    {
        app = g_array_index(arr, MicroApplication*, i);
        app->free();
        free(app);
    }

    g_array_free(arr, TRUE);
    free(priv);
}

void micro_app_handler_private_add(MicroAppHandlerPrivate *priv, MicroApplication *app)
{
    g_array_append_val(priv->instances, app);
}
