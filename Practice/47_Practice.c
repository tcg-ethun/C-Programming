#include <stdio.h>

int main() {
    int x = 10; // A normal integer
    int *p1 = &x;
    int **p2 = &p1;
    int ***p3 = &p2;
    int ****p4 = &p3;
    int *****p5 = &p4;
    int ******p6 = &p5;
    int *******p7 = &p6;
    int ********p8 = &p7;
    int *********p9 = &p8;
    int **********p10 = &p9; // 10-level pointer

    // Accessing the value of x through 10 levels of pointers
    printf("Value of x: %d\n", **********p10);

    return 0;
}
