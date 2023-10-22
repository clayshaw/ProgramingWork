#include <stdio.h>

int isPythagorean(int a, int b, int c) {
    return a * a + b * b == c * c;
}

int main() {
    int limit = 500;
    for (int a = 1; a <= limit; a++) {
        for (int b = a; b <= limit; b++) {
            for (int c = b; c <= limit; c++) {
                if (isPythagorean(a, b, c)) {
                    printf("%d, %d, %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}