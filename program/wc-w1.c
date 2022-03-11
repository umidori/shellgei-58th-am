#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    int n;

    n = 0;
    while (1) {
        while ((c = getchar()) != EOF && isspace(c)) {
        }
        if (c == EOF) break;
        n++;
        while ((c = getchar()) != EOF && !isspace(c)) {
        }
        if (c == EOF) break;
    }
    printf("%d\n", n);

    return 0;
}
