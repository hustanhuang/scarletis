#include "sstring.h"

sstring *sstr_create(const char *s) {
    sstring *new_s = malloc(sizeof(sstring));
    new_s->s = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(new_s->s, s);
    return new_s;
}

void sstr_del(sstring *s) {
    free(s->s);
    free(s);
}

const char *sstr_get(const sstring *s) {
    return s->s;
}
