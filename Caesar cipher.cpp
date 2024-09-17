#include <stdio.h>
#include <string.h>
int main() {
    char text[100];
    int k, i;
    char ch;
    printf("Enter the text: ");
    gets(text);
    
    printf("Enter the shift value (k): ");
    scanf("%d", &k);
    for (i = 0; i < strlen(text); i++) {
        ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + k) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + k) % 26 + 'a';
        }
        text[i] = ch;
    }
    printf("Encrypted text: %s\n", text);

    return 0;
}

