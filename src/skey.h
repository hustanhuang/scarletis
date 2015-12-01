#ifndef SKEY_H_
#define SKEY_H_

#include "slist.h"

typedef struct {
    char *key;
    char *value;
    list_t node;
} skey_t;

/* create a key */
skey_t *skey_create(char *k, char *v);

/* delete a key */
void skey_del(skey_t *k);

#endif
