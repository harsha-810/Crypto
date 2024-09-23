#include <stdio.h>
#include <string.h>
#include <ctype.h>
char encryptChar(char plainChar, char keyChar) {
    return ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
}
char decryptChar(char cipherChar, char keyChar) {
    return ((cipherChar - keyChar + 26) % 26) + 'A';
}
void repeatKey(char *key, char *text, char *repeatedKey) {
    int keyLength = strlen(key);
    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++) {
        repeatedKey[i] = key[i % keyLength];
    }
    repeatedKey[textLength] = '\0';
}
void encrypt(char *plaintext, char *key, char *ciphertext) {
    char repeatedKey[100];
    repeatKey(key, plaintext, repeatedKey);
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encryptChar(plaintext[i], repeatedKey[i]);
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void decrypt(char *ciphertext, char *key, char *plaintext) {
    char repeatedKey[100];
    repeatKey(key, ciphertext, repeatedKey);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = decryptChar(ciphertext[i], repeatedKey[i]);
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char plaintext[100], key[100], ciphertext[100];
    printf("Enter the plaintext (in uppercase, no spaces): ");
    scanf("%s", plaintext);
    printf("Enter the key (in uppercase): ");
    scanf("%s", key);
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);
    return 0;
}

