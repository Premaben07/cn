#include <stdio.h>

int findMissing(int arr[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int n ;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers elements:\n",  n);
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int missing = findMissing(arr, size);
    printf("Missing number is: %d\n", missing);
    return 0;
}