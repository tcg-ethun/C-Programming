#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void restart();
void play();
void nope();

int main() {
    play();
    return 0;
}

void play() {
    int input, otp1;
    srand(time(0));  // Seed with current time
    otp1 = 1 + rand() % 10;  // 1-digit OTP

    printf("1-digit OTP: %d\n", otp1);  // Debugging purpose, remove for real game
    printf("Guess the number (1-10): ");
    scanf("%d", &input);

    if (input < 1 || input > 10) {
        printf("Invalid Number! Please enter a number between 1 and 10.\n");
        return;
    }

    while (input != otp1) {
        printf("Wrong! Guess again: ");
        scanf("%d", &input);

        if (input < 1 || input > 10) {
            printf("Invalid Number! Please enter a number between 1 and 10.\n");
            return;
        }
    }

    printf("Congratulations! You got the number.\n\n");
    restart();
}

void restart() {
    int enter;
    printf("Do you want to play again?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &enter);

    if (enter == 1) {
        play();
    } else if (enter == 2) {
        nope();
    } else {
        printf("Invalid Number! Exiting game.\n");
    }
}

void nope() {
    printf("Game Ended!\n");
}
