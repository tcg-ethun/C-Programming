#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to encrypt/decrypt a single file
void processFile(const char *inputFile, const char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "rb");
    FILE *fout = fopen(outputFile, "wb");

    if (fin == NULL || fout == NULL) {
        printf("Error opening file: %s\n", inputFile);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    long processed = 0, total = 0;

    // Get file size
    fseek(fin, 0, SEEK_END);
    total = ftell(fin);
    fseek(fin, 0, SEEK_SET);

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

// Function to encrypt multiple files into a single encrypted file
void encryptMultipleFiles(int fileCount, char *fileNames[], const char *outputFile, int key) {
    FILE *fout = fopen(outputFile, "wb");

    if (fout == NULL) {
        printf("Error opening output file: %s\n", outputFile);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    long totalProcessed = 0;

    for (int i = 0; i < fileCount; i++) {
        FILE *fin = fopen(fileNames[i], "rb");
        if (fin == NULL) {
            printf("Error opening file: %s\n", fileNames[i]);
            continue;
        }

        // Get file size for progress tracking
        fseek(fin, 0, SEEK_END);
        long fileSize = ftell(fin);
        fseek(fin, 0, SEEK_SET);

        printf("\nEncrypting file: %s\n", fileNames[i]);
        long processed = 0;

        while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
            xorEncryptDecrypt(buffer, bytesRead, key);
            fwrite(buffer, 1, bytesRead, fout);
            processed += bytesRead;
            totalProcessed += bytesRead;
            showProgress(processed, fileSize);
        }

        fclose(fin);
    }

    printf("\nAll files encrypted successfully! Output saved as: %s\n", outputFile);
    fclose(fout);
}

// Function to decrypt a single file
void decryptFile(const char *inputFile, const char *outputFile, int key) {
    processFile(inputFile, outputFile, key);  // XOR is reversible, so same function is used
}

// Function to decrypt a single combined encrypted file into multiple files
void decryptMultipleFiles(const char *inputFile, const char *outputPrefix, int fileCount, int key) {
    FILE *fin = fopen(inputFile, "rb");

    if (fin == NULL) {
        printf("Error opening encrypted file: %s\n", inputFile);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    long totalProcessed = 0;

    for (int i = 0; i < fileCount; i++) {
        char outputFile[100];
        snprintf(outputFile, sizeof(outputFile), "%s_%d.dec", outputPrefix, i + 1);

        FILE *fout = fopen(outputFile, "wb");
        if (fout == NULL) {
            printf("Error creating file: %s\n", outputFile);
            continue;
        }

        printf("\nDecrypting to file: %s\n", outputFile);
        long processed = 0;

        while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
            xorEncryptDecrypt(buffer, bytesRead, key);
            fwrite(buffer, 1, bytesRead, fout);
            processed += bytesRead;
            totalProcessed += bytesRead;
            showProgress(processed, totalProcessed);
        }

        fclose(fout);
    }

    printf("\nDecryption complete! Files saved as %s_*.dec\n", outputPrefix);
    fclose(fin);
}

// Function to get a valid integer input for the key
int getValidIntegerInput() {
    int key;
    int valid = 0;

    while (!valid) {
        printf("Enter key (integer value): ");
        if (scanf("%d", &key) == 1) {
            valid = 1;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    return key;
}

int main() {
    int mode, fileCount;
    char outputFile[100];

    printf("\n=== File Encryption & Decryption by Ethun ===\n");
    printf("Welcome! This program allows you to encrypt or decrypt files.\n");

    // Select mode
    printf("\nSelect Mode:\n");
    printf("1. Encrypt a single file\n");
    printf("2. Encrypt multiple files \n");
    printf("3. Decrypt a single file\n");
    printf("4. Decrypt a combined encrypted file\n");
    printf("\n");
    printf("Enter your choice (1-4): ");

    while (scanf("%d", &mode) != 1 || (mode < 1 || mode > 4)) {
        printf("Invalid choice. Please enter a number between 1 and 4: ");
        while (getchar() != '\n');  // Clear input buffer
    }

    // Get encryption key
    int key = getValidIntegerInput();

    if (mode == 1 || mode == 3) {
        // Single file encryption/decryption
        char inputFile[100];
        printf("Enter input file name: ");
        scanf("%s", inputFile);
        printf("Enter output file name: ");
        scanf("%s", outputFile);

        if (mode == 1) {
            processFile(inputFile, outputFile, key);
        } else {
            decryptFile(inputFile, outputFile, key);
        }

    } else if (mode == 2) {
        // Multiple file encryption
        printf("Enter number of files to encrypt: ");
        while (scanf("%d", &fileCount) != 1 || fileCount < 1) {
            printf("Invalid input. Enter a valid number: ");
            while (getchar() != '\n');  // Clear input buffer
        }

        char *fileNames[fileCount];
        for (int i = 0; i < fileCount; i++) {
            fileNames[i] = malloc(100);
            printf("Enter file %d name: ", i + 1);
            scanf("%s", fileNames[i]);
        }

        printf("Enter output encrypted file name: ");
        scanf("%s", outputFile);

        encryptMultipleFiles(fileCount, fileNames, outputFile, key);

        for (int i = 0; i < fileCount; i++) {
            free(fileNames[i]);
        }
    } else if (mode == 4) {
        // Decrypt a single combined encrypted file into multiple files
        printf("Enter the encrypted file name: ");
        scanf("%s", outputFile);
        printf("Enter output file prefix: ");
        char outputPrefix[100];
        scanf("%s", outputPrefix);
        printf("Enter number of original files: ");
        scanf("%d", &fileCount);

        decryptMultipleFiles(outputFile, outputPrefix, fileCount, key);
    }

    return 0;
}
