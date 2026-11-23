#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], freq[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array
    }

    // Count frequency
    for(int i = 0; i < n; i++) {
        if(freq[i] == -1) {
            int count = 1;
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // Mark as counted
                }
            }
            freq[i] = count;
        }
    }

    // Display frequency
    printf("\nElement\tFrequency\n");
    for(int i = 0; i < n; i++) {
        if(freq[i] != 0)
            printf("%d\t%d\n", arr[i], freq[i]);
    }

    return 0;
}