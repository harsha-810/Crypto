#include <stdio.h>
#include <string.h>
#define SIZE 5
char matrix[SIZE][SIZE];
void removeDuplicates(char *str) {
    int index = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}
void createMatrix(char *key) {
    int alphabets[26] = {0};  
    int x = 0, y = 0;
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] != 'J' && alphabets[key[i] - 'A'] == 0) {
            matrix[x][y++] = key[i];
            alphabets[key[i] - 'A'] = 1;

            if (y == SIZE) {
                x++;
                y = 0;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch != 'J' && alphabets[ch - 'A'] == 0) {
            matrix[x][y++] = ch;
            alphabets[ch - 'A'] = 1;

            if (y == SIZE) {
                x++;
                y = 0;
            }
        }
    }
}
void displayMatrix() {
    printf("Playfair Cipher Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
void findPosition(char letter, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPair(char a, char b, char *encrypted) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);
    if (row1 == row2) {
        encrypted[0] = matrix[row1][(col1 + 1) % SIZE];
        encrypted[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        encrypted[0] = matrix[(row1 + 1) % SIZE][col1];
        encrypted[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        encrypted[0] = matrix[row1][col2];
        encrypted[1] = matrix[row2][col1];
    }
}
void preparePlaintext(char *plaintext) {
    int len = strlen(plaintext);
    char temp[100];
    int index = 0;
    for (int i = 0; i < len; i += 2) {
        temp[index++] = plaintext[i];

        if (i + 1 < len) {
            if (plaintext[i] == plaintext[i + 1]) {
                temp[index++] = 'X';
            } else {
                temp[index++] = plaintext[i + 1];
            }
        } else {
            temp[index++] = 'X'; 
        }
    }
    temp[index] = '\0';
    strcpy(plaintext, temp);
}
void encrypt(char *plaintext, char *ciphertext) {
    preparePlaintext(plaintext);
    int len = strlen(plaintext);
    int index = 0;

    for (int i = 0; i < len; i += 2) {
        encryptPair(plaintext[i], plaintext[i + 1], &ciphertext[index]);
        index += 2;
    }
    ciphertext[index] = '\0';
}
int main() {
    char key[100], plaintext[100], ciphertext[100];
    printf("Enter the key (in uppercase): ");
    scanf("%s", key);
    removeDuplicates(key);
    createMatrix(key);
    displayMatrix();
    printf("Enter the plaintext (in uppercase, without spaces): ");
    scanf("%s", plaintext);
    encrypt(plaintext, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    return 0;
}
