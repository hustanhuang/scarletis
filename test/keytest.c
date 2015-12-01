#include <stdio.h>
#include "../src/skey.h"

int main() {
    skey_t *key = skey_create("hehe", "haha");
    printf("key: %s\nvalue: %s\n", key->key, key->value);
    skey_del(key);
    return 0;
}
