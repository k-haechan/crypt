#ifndef MODE_CBC_H
#define MODE_CBC_H
#include "../common.h"

void Cipher_CBC_Encrypt(block_cipher_func cipher_func, const uint8_t *plain, uint8_t *cipher, size_t len, const uint8_t *key, int keySize, const uint8_t *iv);
void Cipher_CBC_Decrypt(block_cipher_func cipher_func, const uint8_t *cipher, uint8_t *plain, size_t len, const uint8_t *key, int keySize, const uint8_t *iv);
#endif