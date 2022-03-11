#include <stdio.h>

const int TAB_NO = 4;

int main(void)
{
    int c;
    int n;
    int t;

    n = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            t = TAB_NO - n%TAB_NO;
            printf("%*s", t, "");
            n += t;
        } else if (c == '\n') {
            putchar(c);
            n = 0;
        } else {
            putchar(c);
            n++;
        }
    }

    return 0;
}
