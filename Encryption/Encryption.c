#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024  // Buffer size for file reading

// Function to show a progress bar
void showProgress(long processed, long total) {
    int progress = (processed * 100) / total;
    printf("\rProgress: %d%%", progress);
    fflush(stdout);
}

// XOR Encryption/Decryption function
void xorEncryptDecrypt(char *buffer, size_t length, int key) {
    for (size_t i = 0; i < length; i++) {
        buffer[i] ^= key;  // XOR each byte with the key
    }
}

// Function to encrypt/decrypt a file
void processFile(const char *inputFile, const char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "rb");
    FILE *fout = fopen(outputFile, "wb");

    if (fin == NULL || fout == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    long processed = 0, total = 0;

    // Get file size
    fseek(fin, 0, SEEK_END);
    total = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    // Process file in chunks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
        xorEncryptDecrypt(buffer, bytesRead, key);
        fwrite(buffer, 1, bytesRead, fout);
        processed += bytesRead;
        showProgress(processed, total);  // Show progress bar
    }

    printf("\nOperation successful! Output saved as: %s\n", outputFile);

    fclose(fin);
    fclose(fout);
}

// Function to get a valid integer input for the key
int getValidIntegerInput() {
    int key;
    int valid = 0;

    // Keep asking until the user provides a valid integer
    while (!valid) {
        printf("Enter key (integer value): ");
        if (scanf("%d", &key) == 1) {
            valid = 1;  // Valid integer input
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    return key;
}

int main() {
    char inputFile[100], outputFile[100];
    int choice;
printf("\n ");
    printf("=== File Encryption & Decryption Made BY Ethun ===\n");
    printf("Welcome! This program allows you to encrypt or decrypt a file.\n");

    // Display menu
    printf("\nPlease select an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice (1/2): ");
    
    // Validate choice input
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice. Please enter 1 for encrypt or 2 for decrypt: ");
        while (getchar() != '\n'); // clear buffer
    }
    getchar();  // Consume newline character left by scanf

    // Get file names and key
    printf("Enter the file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    // Get valid integer key input
    int key = getValidIntegerInput();

    // Process the file (encrypt or decrypt based on the choice)
    processFile(inputFile, outputFile, key);

    return 0;
}
