#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int n, M, result;
    n = 61 * 53;
    printf("Enter the plaintext block (M): ");
    scanf("%d", &M);
    result = gcd(M, n);
    if (result != 1) {
        printf("The plaintext block shares a common factor with n.\n");
        printf("One of the factors of n is: %d\n", result);
    } else {
        printf("No common factor found.\n");
    }
    return 0;
}

