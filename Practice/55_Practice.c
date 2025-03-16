#include <stdio.h>

int main() {
    int myNumbers[] = {25, 50, 75, 100,90,39,28,48},i;
    int length = sizeof(myNumbers)  / sizeof(myNumbers[0]);
    
    for (i = 0; i <length ; i++) {
     printf("%d ", myNumbers[i]);
    }

    return 0;
}