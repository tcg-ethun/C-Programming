#include <stdio.h>

int main() {
    int age = 20;
    int *ptr = &age;
    int result = *ptr;

    printf("Address of age: %p \n", (void *)&age); // Use %p and cast to (void *)
    printf("Address of age as unsigned int: %lu \n", (unsigned long)&age); // Optionally, %lu for large values
    printf("\n");

    printf("Pointer value (value stored at ptr): %d \n", *ptr); // Use %d
    printf("Address stored in pointer (ptr): %p\n", (void *)ptr); // Use %p
    printf("\n");

    printf("Address of result variable: %p\n", (void *)&result); // Use %p
    printf("Value of result variable: %d\n", result); // Use %d
    printf("\n");

    printf("Value of age using pointer dereferencing: %d \n", *(&age)); // %d is correct
    printf("\n");

    return 0;
}