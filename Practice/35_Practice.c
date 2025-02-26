#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // Seed with current time
    int otp2 = 10 + rand() % 90;  // 2-digit OTP
    printf("2-digit OTP: %d\n", otp2);

    int otp4 = 1000 + rand() % 9000;  // 4-digit OTP
    printf("4-digit OTP: %d\n", otp4);

    int otp6 = 100000 + rand() % 900000;  // 6-digit OTP
    printf("6-digit OTP: %d\n", otp6);

    int otp8 = 10000000 + rand() % 90000000;  // 8-digit OTP
    printf("8-digit OTP: %d\n", otp8);
    
    return 0;
}