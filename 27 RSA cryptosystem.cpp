#include <stdio.h>
#include <math.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
void createDictionary(int e, int n) {
    printf("Dictionary (Ciphertext -> Plaintext Mapping):\n");
    for (int i = 0; i < 26; i++) {
        int ciphertext = modExp(i, e, n);
        printf("Ciphertext: %d -> Plaintext: %d\n", ciphertext, i);
    }
}

int main() {
    int p = 61;
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;
    if (gcd(e, phi) != 1) {
        printf("Invalid public key!\n");
        return -1;
    }
    createDictionary(e, n);
    int plaintext = 19;
    int ciphertext = modExp(plaintext, e, n);
    printf("\nEncrypted 'T' (19) -> Ciphertext: %d\n", ciphertext);
    printf("\nAttacker uses the dictionary to find the plaintext of ciphertext %d -> Plaintext: %d\n", ciphertext, plaintext);

    return 0;
}

