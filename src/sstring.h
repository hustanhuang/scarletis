#ifndef SSTRING_H
#define SSTRING_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *s;
} sstring;

sstring *sstr_create(const char *s);

void sstr_del(sstring *s);

const char *sstr_get(const sstring *s);

#endif
