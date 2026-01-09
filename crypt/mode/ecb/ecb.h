#ifndef MODE_ECB_H
#define MODE_ECB_H
#include "../common.h"

void Cipher_ECB_Encrypt(block_cipher_func cipher_func, const uint8_t *plain, uint8_t *cipher, size_t len, const uint8_t *key, int keySize);
void Cipher_ECB_Decrypt(block_cipher_func cipher_func, const uint8_t *cipher, uint8_t *plain, size_t len, const uint8_t *key, int keySize);
#endif