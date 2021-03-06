#include <stdio.h>

int is_float(char *s)
{
    if (*s == '+' || *s == '-') {
        s++;
    }

    if (*s == '.') {
        s++;
        if ('0' <= *s && *s <= '9') {
            do {
                s++;
            } while ('0' <= *s && *s <= '9');
        } else {
            return 0;
        }
    } else if ('0' <= *s && *s <= '9') {
        do {
            s++;
        } while ('0' <= *s && *s <= '9');
        if (*s == '.') {
            do {
                s++;
            } while ('0' <= *s && *s <= '9');
        }
    } else {
        return 0;
    }

    if (*s == 'E' || *s == 'e') {
        s++;
        if (*s == '+' || *s == '-') {
            s++;
        }
        if ('0' <= *s && *s <= '9') {
            do {
                s++;
            } while ('0' <= *s && *s <= '9');
        } else {
            return 0;
        }
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
        { ".", 0 },
        { "++", 0 },
        { "--", 0 },
        { "+.", 0 },
        { "-.", 0 },
        { "+0+", 0 },
        { "-0-", 0 },
        { "+1", 1 },
        { "-1", 1 },
        { "1", 1 },
        { "+1.", 1 },
        { "-1.", 1 },
        { "1.", 1 },
        { "+.1", 1 },
        { "-.1", 1 },
        { ".1", 1 },
        { "+1234567890", 1 },
        { "-1234567890", 1 },
        { "1234567890", 1 },
        { "+1234567890.", 1 },
        { "-1234567890.", 1 },
        { "1234567890.", 1 },
        { "+.1234567890", 1 },
        { "-.1234567890", 1 },
        { ".1234567890", 1 },
        { "1E", 0 },
        { "1E+", 0 },
        { "1E-", 0 },
        { "1E+1", 1 },
        { "1E-1", 1 },
        { "1E1", 1 },
        { "1E+1234567890", 1 },
        { "1E-1234567890", 1 },
        { "1E1234567890", 1 },
        { "1.E1", 1 },
        { ".1E1", 1 },
        { "1e", 0 },
        { "1e+", 0 },
        { "1e-", 0 },
        { "1e+1", 1 },
        { "1e-1", 1 },
        { "1e1", 1 },
        { "1.e1", 1 },
        { ".1e1", 1 },
    };
    int i;

    for (i = 0; i < sizeof(tests)/sizeof(*tests); i++) {
        printf("'%s'\t%s\n", tests[i].s, tests[i].b == is_float(tests[i].s) ? "OK" : "NG"); 
    }

    return 0;
}
