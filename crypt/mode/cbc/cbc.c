#include "cbc.h"
#include <string.h>

void Cipher_CBC_Encrypt(block_cipher_func enc_func, const uint8_t *plain, uint8_t *cipher, size_t len, const uint8_t *key, int keySize, const uint8_t *iv) {
    uint8_t prev[BLOCK_SIZE];
    memcpy(prev, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        uint8_t block[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) block[j] = plain[i + j] ^ prev[j];
        
        enc_func(block, &cipher[i], key, keySize);
        memcpy(prev, &cipher[i], BLOCK_SIZE);
    }
}

void Cipher_CBC_Decrypt(block_cipher_func dec_func, const uint8_t *cipher, uint8_t *plain, size_t len, const uint8_t *key, int keySize, const uint8_t *iv) {
    uint8_t prev[BLOCK_SIZE];
    memcpy(prev, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        uint8_t block[BLOCK_SIZE];
        dec_func(&cipher[i], block, key, keySize);
        
        for (int j = 0; j < BLOCK_SIZE; j++) plain[i + j] = block[j] ^ prev[j];
        memcpy(prev, &cipher[i], BLOCK_SIZE);
    }
}