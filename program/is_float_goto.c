#include <stdio.h>

int is_float(char *s)
{
    goto S0;

S0:
    if (*s == '+' || *s == '-') {
        s++;
        goto S1;
    } else if (*s == '.') {
        s++;
        goto S2;
    } else if ('0' <= *s && *s <= '9') {
        s++;
        goto S3;
    } else {
        goto S9;
    }
S1:
    if (*s == '.') {
        s++;
        goto S2;
    } else if ('0' <= *s && *s <= '9') {
        s++;
        goto S3;
    } else {
        goto S9;
    }
S2:
    if ('0' <= *s && *s <= '9') {
        s++;
        goto S4;
    } else {
        goto S9;
    }
S3:
    if (*s == '.') {
        s++;
        goto S4;
    } else if ('0' <= *s && *s <= '9') {
        s++;
        goto S3;
    } else if (*s == 'E' || *s == 'e') {
        s++;
        goto S5;
    } else if (*s == '\0') {
        goto S8;
    } else {
        goto S9;
    }
S4:
    if ('0' <= *s && *s <= '9') {
        s++;
        goto S4;
    } else if (*s == 'E' || *s == 'e') {
        s++;
        goto S5;
    } else if (*s == '\0') {
        goto S8;
    } else {
        goto S9;
    }
S5:
    if (*s == '+' || *s == '-') {
        s++;
        goto S6;
    } else if ('0' <= *s && *s <= '9') {
        s++;
        goto S7;
    } else {
        goto S9;
    }
S6:
    if ('0' <= *s && *s <= '9') {
        s++;
        goto S7;
    } else {
        goto S9;
    }
S7:
    if ('0' <= *s && *s <= '9') {
        s++;
        goto S7;
    } else if (*s == '\0') {
        goto S8;
    } else {
        goto S9;
    }
S8:
    return 1;
S9:
    return 0;
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
