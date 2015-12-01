#include "skey.h"

#include <stdlib.h>
#include <string.h>

skey_t *skey_create(char *k, char *v) {
    skey_t *new_key = malloc(sizeof(skey_t));
    new_key->key = malloc(sizeof(char) * (strlen(k) + 1));
    new_key->value = malloc(sizeof(char) * (strlen(v) + 1));
    INIT_LIST_HEAD(&new_key->node);
    strcpy(new_key->key, k);
    strcpy(new_key->value, v);
    return new_key;
}

void skey_del(skey_t *k) {
    list_del(&k->node);
    free(k->key);
    free(k->value);
    free(k);
}
