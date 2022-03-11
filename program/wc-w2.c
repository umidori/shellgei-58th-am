#include <stdio.h>
#include <ctype.h>

enum {NO, YES};

int main(void)
{
    int c;
    int n;
    int inword;

    n = 0;
    inword = NO;
    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            inword = NO;
        } else if (inword == NO) {
            inword = YES;
            n++;
        }
    }
    printf("%d\n", n);

    return 0;
}
