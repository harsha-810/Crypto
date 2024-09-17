#include <stdio.h>
#include <string.h>
void encrypt(char text[], char cipher[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = cipher[text[i] - 'A'];  
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = cipher[text[i] - 'a'] + 32;  
        }
    }
}
int main() {
    char text[100];  
    char cipher[27];  
    printf("Enter the text: ");
    gets(text); 
    
    printf("Enter the cipher alphabet (26 letters): ");
    scanf("%s", cipher);
    encrypt(text, cipher);
    printf("Encrypted text: %s\n", text);
    return 0;
}

