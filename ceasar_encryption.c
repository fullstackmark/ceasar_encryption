#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to encrypt plaintext using Caesar cipher
void encrypt(char *plaintext, int key) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
        i++;
    }
}

// Function to decrypt ciphertext using Caesar cipher
void decrypt(char *ciphertext, int key) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        }
        i++;
    }
}

int main() {
    char plaintext[MAX_LENGTH];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Generate a secret key between 2 and 10
    int key = rand() % 9 + 2;

    // Encrypt the plaintext
    encrypt(plaintext, key);
    printf("Encrypted ciphertext: %s\n", plaintext);

    // Brute force attack trying keys from 2 to 10 to discover the key and decrypt the ciphertext
    printf("Brute force attack:\n");
    for (int i = 2; i <= 10; i++) {
        char ciphertext[MAX_LENGTH];
        strncpy(ciphertext, plaintext, sizeof(ciphertext));
        decrypt(ciphertext, i);
        printf("Key: %d, Plaintext: %s\n", i, ciphertext);
    }

    return 0;
}