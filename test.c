#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef char* (*EncryptFuncPtr)(char*, int);
typedef char* (*DecryptFuncPtr)(char*, int);

int main(){

    void* library = dlopen("/Users/ostapturash/p_p_3/libmyLibrary.dylib", RTLD_LAZY);

    if (!library){
        fprintf(stderr, "Failed to load the library: %s\n", dlerror());
        return 1;
    }

    EncryptFuncPtr encrypt = (EncryptFuncPtr) dlsym(library,"encrypt");
    DecryptFuncPtr decrypt = (EncryptFuncPtr) dlsym(library,"decrypt");

    if (!encrypt || !decrypt){
        fprintf(stderr, "Failed to load the functions: %s\n", dlerror());
        return 1;
    }

    while (1){
        int choice;
        printf("Choose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1){
            char input[100];
            int key;

            getchar();
            printf("Enter the message to encrypt: ");
            fgets(input, sizeof (input), stdin);

            printf("Enter the encryption key: ");
            scanf("%d", &key);

            char* encryptedText = encrypt(input, key);
            printf("Encrypted: %s\n", encryptedText);

            free(encryptedText);
        }
        else if (choice == 2){
            char encryptedText[100];
            int key;

            getchar();
            printf("Enter the message to decrypt: ");
            fgets(encryptedText, sizeof(encryptedText), stdin);

            printf("Enter the decryption key: ");
            scanf("%d", &key);

            char* decryptedText = decrypt(encryptedText, key);
            printf("Decrypted: %s\n", decryptedText);

            free(decryptedText);
        }
        else if (choice == 3){
            break;
        }
    }

    dlclose(library);
    return 0;
}