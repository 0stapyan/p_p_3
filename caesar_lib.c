#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* rawText, int key){

    int length = strlen(rawText);
    char* encryptedText = (char*) malloc(length + 1);

    if (rawText == NULL){
        return NULL;
    }

    for (int i = 0; i < length; i++){
        char c = rawText[i];
        if (c >= 'A' && c <= 'Z'){
            encryptedText[i] = (c - 'A' + key) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z'){
            encryptedText[i] = (c - 'a' + key) % 26 + 'a';
        }
        else if (c >= '0' && c <= '9'){
            encryptedText[i] = (c - '0' + key) % 10 + '0';
        }
        else{
            encryptedText[i] = c;
        }
    }
    return encryptedText;
}

char* decrypt(char* encryptedText, int key){

    int length = strlen(encryptedText);
    char* decryptedText = (char*)malloc(length + 1);

    if (encryptedText == NULL) {
        return NULL;
    }

    for (int i = 0; i < length; i++){
        char c = encryptedText[i];
        if (c >= 'A' && c <= 'Z'){
            decryptedText[i] = (c - 'A' - key + 26) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z'){
            decryptedText[i] = (c - 'a' - key + 26) % 26 + 'a';
        }
        else if (c >= '0' && c <= '9'){
            decryptedText[i] = (c - '0' - key + 10) % 10 + '0';
        }
        else{
            decryptedText[i] = c;
        }
    }
    return decryptedText;
}