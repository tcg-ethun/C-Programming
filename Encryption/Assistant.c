#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void greet() {
    printf("Hello! I am your virtual assistant. How can I assist you today?\n");
}

void tellTime() {
    time_t t;
    time(&t);
    printf("Current time: %s", ctime(&t));
}

void openApp(char *appName) {
    if (strcmp(appName, "notepad") == 0) {
        system("notepad");
    } else if (strcmp(appName, "calculator") == 0) {
        system("calc");
    } else {
        printf("Sorry, I don't recognize that application.\n");
    }
}

void tellJoke() {
    printf("Why don't programmers like nature? It has too many bugs.\n");
}

void exitAssistant() {
    printf("Goodbye! Have a nice day!\n");
    exit(0);
}

int main() {
    char input[100];
    char appName[50];

    greet();

    while (1) {
        printf("\nEnter a command: ");
        fgets(input, 100, stdin);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "time") == 0) {
            tellTime();
        } else if (strncmp(input, "open ", 5) == 0) {
            sscanf(input, "open %s", appName);
            openApp(appName);
        } else if (strcmp(input, "joke") == 0) {
            tellJoke();
        } else if (strcmp(input, "exit") == 0) {
            exitAssistant();
        } else {
            printf("Sorry, I don't understand that command.\n");
        }
    }

    return 0;
}