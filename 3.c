#include <stdio.h>

int main() {
    int arr[100], n, pos;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete (0-based index)
    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    // Validate position
    if (pos < 0 || pos >= n) {
        printf("Invalid position! No deletion performed.\n");
        return 1;
    }

    // Shift elements left to overwrite the deleted element
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Reduce array size

    // Print updated array
    printf("Updated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}