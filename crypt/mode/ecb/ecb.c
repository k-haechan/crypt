#include "ecb.h"

void Cipher_ECB_Encrypt(block_cipher_func enc_func, const uint8_t *plain, uint8_t *cipher, size_t len, const uint8_t *key, int keySize) {
    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        enc_func(&plain[i], &cipher[i], key, keySize);
    }
}

void Cipher_ECB_Decrypt(block_cipher_func dec_func, const uint8_t *cipher, uint8_t *plain, size_t len, const uint8_t *key, int keySize) {
    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        dec_func(&cipher[i], &plain[i], key, keySize);
    }
}