#include <stdio.h>
#include "../src/sstring.h"

int main() {
    printf("string test\n");

    sstring *str = sstr_create("hehe");
    printf("%s\n", sstr_get(str));
    sstr_del(str);

    return 0;
}
