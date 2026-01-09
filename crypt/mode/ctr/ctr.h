#ifndef MODE_CTR_H
#define MODE_CTR_H
#include "../common.h"

void Cipher_CTR_Process(block_cipher_func enc_func, const uint8_t *in, uint8_t *out, size_t len, const uint8_t *key, int keySize, const uint8_t *nonce);
#endif