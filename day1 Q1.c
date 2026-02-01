#include <stdio.h>

int main() {
    int a[100], n, x, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &x);

    printf("Enter position (1-based index): ");
    scanf("%d", &pos);

    // Check valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    // Insert element
    a[pos - 1] = x;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
