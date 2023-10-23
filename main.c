#include <stdio.h> // input and output
#include <stdlib.h> // memory allocation
#include <string.h> // for strings and lengths


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

int main(){

    char input[1024];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", input);
    getchar();

    printf("Enter an encryption key: ");
    scanf("%d", &key);

    char* encryptedText = encrypt(input, key);

    printf("Encrypted text: %s\n", encryptedText);

    free(encryptedText);

};