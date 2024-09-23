#include <stdio.h>
#include <string.h>
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}
void affineEncrypt(char* plaintext, int a, int b, char* ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            int p = plaintext[i] - 'A';
            int c = (a * p + b) % 26;
            ciphertext[i] = c + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
void affineDecrypt(char* ciphertext, int a, int b, char* plaintext) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("Decryption not possible because 'a' has no modular inverse!\n");
        return;
    }
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int c = ciphertext[i] - 'A';
            int p = (a_inv * (c - b + 26)) % 26;
            plaintext[i] = p + 'A'; 
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}
int main() {
    char plaintext[100], ciphertext[100], decryptedtext[100];
    int a, b;
    printf("Enter the plaintext (in uppercase): ");
    scanf("%s", plaintext);
    printf("Enter the values of 'a' and 'b': ");
    scanf("%d %d", &a, &b);
    if (modInverse(a, 26) == -1) {
        printf("'a' must be coprime with 26. Please enter a valid value.\n");
        return 0;
    }
    affineEncrypt(plaintext, a, b, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    affineDecrypt(ciphertext, a, b, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);
    return 0;
}
