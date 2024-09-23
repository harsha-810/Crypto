#include <stdio.h>
#include <math.h>
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
int main() {
    int a = 5;
    int q = 23;

    int x_A = 6;
    int A = modExp(a, x_A, q);
    printf("Alice sends A = %d\n", A);

    int x_B = 15;
    int B = modExp(a, x_B, q);
    printf("Bob sends B = %d\n", B);

    int shared_A = modExp(B, x_A, q);
    printf("Alice's shared key = %d\n", shared_A);

    int shared_B = modExp(A, x_B, q);
    printf("Bob's shared key = %d\n", shared_B);

    if (shared_A == shared_B) {
        printf("Key exchange successful! Shared key = %d\n", shared_A);
    } else {
        printf("Key exchange failed!\n");
    }
    return 0;
}

