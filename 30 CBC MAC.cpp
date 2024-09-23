#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16

void xor_blocks(uint8_t *block1, uint8_t *block2, uint8_t *result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = block1[i] ^ block2[i];
    }
}

void simple_encrypt(uint8_t *input, uint8_t *output) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ 0xFF;
    }
}

void print_block(uint8_t *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", block[i]);
    }
    printf("\n");
}

int main() {
    uint8_t key[BLOCK_SIZE] = {0}; 
    uint8_t X[BLOCK_SIZE] = {0x01}; 
    uint8_t T[BLOCK_SIZE]; 
    uint8_t second_block[BLOCK_SIZE]; 
    uint8_t MAC_two_blocks[BLOCK_SIZE]; 

    simple_encrypt(X, T);
    printf("MAC(K, X): ");
    print_block(T);

    xor_blocks(X, T, second_block);
    printf("X ? T: ");
    print_block(second_block);

    uint8_t first_block_enc[BLOCK_SIZE];
    simple_encrypt(X, first_block_enc);

    uint8_t xor_result[BLOCK_SIZE];
    xor_blocks(first_block_enc, second_block, xor_result);

    simple_encrypt(xor_result, MAC_two_blocks);
    printf("MAC(K, X || (X ? T)): ");
    print_block(MAC_two_blocks);

    return 0;
}

