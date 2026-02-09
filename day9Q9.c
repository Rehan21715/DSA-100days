#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    // Input string
    scanf("%s", str);

    len = strlen(str);

    // Print reversed string
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
