/* 先読み技法を使ったコメント除去プログラム例 */
#include <stdio.h>

int main(void)
{
    int c;
    int n;

   c = getchar();
    while (c != EOF) {
        while (c != EOF) {
            n = getchar();
            if (c == '/' && n == '*') {
                c = getchar();
                break;
            } else {
                putchar(c);
                c = n;
            }
        }
        while (c != EOF) {
            n = getchar();
            if (c == '*' && n == '/') {
                c = getchar();
                break;
            } else {
                c = n;
            }
        }
    }

    return 0;
}
