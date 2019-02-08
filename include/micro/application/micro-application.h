#ifndef MICRO_APPLICATION_H
#define MICRO_APPLICATION_H

typedef struct
{
    void (*run) (void);
    char *name;
    char *version;
    char *url;
    char *author;
    char *author_email;
    char *description;
    char *long_description;
    char *app_help;
} MicroApplication;

#endif
