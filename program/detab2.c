#include <stdio.h>

int main(void)
{
    int c;

    while (1) {
        if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\t') {
            printf("    ");
            continue;
        } else if (c == '\n') {
            putchar(c);
            continue;
        } else {
            putchar(c);
        }

        if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\t') {
            printf("   ");
            continue;
        } else if (c == '\n') {
            putchar(c);
            continue;
        } else {
            putchar(c);
        }

        if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\t') {
            printf("  ");
            continue;
        } else if (c == '\n') {
            putchar(c);
            continue;
        } else {
            putchar(c);
        }

        if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\t') {
            printf(" ");
            continue;
        } else if (c == '\n') {
            putchar(c);
            continue;
        } else {
            putchar(c);
        }
    }

    return 0;
}


