#include <stdio.h>
#include <limits.h>

int main() {
    
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = INT_MIN, second_largest = INT_MIN;
    for(int i = 0; i < n; i++) { if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    printf("Second largest: %d\n", second_largest);
    return 0;
}