#ifndef MODE_OFB_H
#define MODE_OFB_H
#include "../common.h"

void Cipher_OFB_Process(block_cipher_func enc_func, const uint8_t *in, uint8_t *out, size_t len, const uint8_t *key, int keySize, const uint8_t *iv);
#endif