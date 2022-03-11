/* 先読み技法を使わないコメント除去プログラム */
#include <stdio.h>

int main(void)
{
    int c;

    while (1) {
        while ((c = getchar()) != EOF) {
            if (c == '/') {
                while ((c = getchar()) == '/') {
                    putchar(c);
                }
                if (c == '*') break;
                putchar('/');
                if (c == EOF) break;
            }
            putchar(c);
        }
        if (c == EOF) break;
        while ((c = getchar()) != EOF) {
            if (c == '*') {
                while ((c = getchar()) == '*') {
                }
                if (c == '/') break;
                if (c == EOF) break;
            }
        }
        if (c == EOF) break;
    }

    return 0;
}
