#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix_sum = 0;
    long long count = 0;
    int freq[20001] = {0};  
    int offset = 10000;     

    freq[offset] = 1; 
    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}