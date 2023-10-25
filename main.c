#include <stdio.h> // input and output
#include <stdlib.h> // memory allocation
#include <string.h> // for strings and lengths

extern char* encrypt(char* rawText, int key);

extern char* decrypt(char* encryptedText, int key);

int main() {
    while (1) {
        char userInput[2];
        char text[1024];
        int key;

        printf("Do you want to encrypt(0) or decrypt(1) a text? ");
        scanf("%1s", userInput);

        if (userInput[0] == '0') {
            printf("Enter a message to encrypt: ");
            scanf(" %[^\n]", text);
            getchar();

            printf("Enter an encryption key: ");
            scanf("%d", &key);

            char* encryptedText = encrypt(text, key);

            printf("Encrypted text: %s\n", encryptedText);

            free(encryptedText);
        }

        else if (userInput[0] == '1') {
            printf("Enter a message to decrypt: ");
            scanf(" %[^\n]", text);
            getchar();

            printf("Enter a decryption key: ");
            scanf("%d", &key);

            char* decryptedText = decrypt(text, key);

            printf("Decrypted text: %s\n", decryptedText);

            free(decryptedText);
        }
    }
}
