#include <stdio.h>


int main() {
    int arr[] = {10, 5, 5};  // Define an array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    // Loop through the array

    int sum =0;
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
         sum += arr[i];
    }
    printf("\n");
    printf(" The sum of array is : %d",sum);
    return 0;
}