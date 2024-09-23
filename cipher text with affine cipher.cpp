#include <stdio.h>
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
void solveAffine(int p1, int c1, int p2, int c2) {
    int a, b;
    int a_value = (c1 - c2 + 26) % 26;
    int p_diff = (p1 - p2 + 26) % 26; 
    int p_diff_inv = modInverse(p_diff, 26);
    if (p_diff_inv == -1) {
        printf("No modular inverse found, cannot solve.\n");
        return;
    }
    a = (a_value * p_diff_inv) % 26;
    b = (c1 - (a * p1)) % 26;
    if (b < 0) {
        b += 26;
    }
    printf("The value of 'a' is: %d\n", a);
    printf("The value of 'b' is: %d\n", b);
}
int main() {
    int p1 = 4;  
    int c1 = 1; 
    int p2 = 19;
    int c2 = 20;
    solveAffine(p1, c1, p2, c2);
    return 0;
}

