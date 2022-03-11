#include <stdio.h>

int is_int(char *s)
{
    if (*s == '+' || *s == '-') {
        s++;
    }

    if (!('0' <= *s && *s <= '9')) {
        return 0;
    }

    s++;
    while ('0' <= *s && *s <= '9') {
        s++;
    }

    return *s == '\0';
}

int main(void)
{
    struct {
        char *s;
        int b;
    } tests[] = {
        { "", 0 },
        { "+", 0 },
        { "-", 0 },
        { "++1", 0 },
        { "+1", 1 },
        { "+12", 1 },
        { "-1234567890", 1 },
        { "1234567890", 1 },
    };
    int i;

    for (i = 0; i < sizeof(tests)/sizeof(*tests); i++) {
        printf("'%s'\t%s\n", tests[i].s, tests[i].b == is_int(tests[i].s) ? "OK" : "NG"); 
    }

    return 0;
}
