#include "micro-app-handler.h"
#include "micro-app-handler-private.h"

#include <stdlib.h>


MicroAppHandler *micro_app_handler_new(unsigned n_instances)
{
    MicroAppHandler *hnd = (MicroAppHandler *) malloc(sizeof(MicroAppHandler));

    if (!hnd)
        return NULL;

    hnd->priv = micro_app_handler_private_new(n_instances);

    if (!hnd->priv)
    {
        free(hnd);
        return NULL;
    }

    return hnd;
}

void micro_app_handler_free(MicroAppHandler *hnd)
{
    if (!hnd)
        return;

    micro_app_handler_private_free(hnd->priv);

    free(hnd);
}
