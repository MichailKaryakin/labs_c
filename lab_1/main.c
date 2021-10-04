#include <stdio.h>

int main() {
    int n, i, result = 0;

    printf("n:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        if ((ai <= 30) && (ai >= 10)) {
            ++result;
        }
    }
    printf("%d", result);
    return 0;
}
