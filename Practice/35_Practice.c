#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // Seed with current time

    int otp = 1000 + rand() % 9000;  // 4-digit OTP
    printf("4-digit OTP: %d\n", otp);

    int otp6 = 100000 + rand() % 900000;  // 6-digit OTP
    printf("6-digit OTP: %d\n", otp6);

    return 0;
}