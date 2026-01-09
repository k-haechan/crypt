#include "ctr.h"
#include <string.h>

void Cipher_CTR_Process(block_cipher_func enc_func, const uint8_t *in, uint8_t *out, size_t len, const uint8_t *key, int keySize, const uint8_t *nonce) {
    uint8_t ctr[BLOCK_SIZE];
    uint8_t mask[BLOCK_SIZE];
    memcpy(ctr, nonce, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        enc_func(ctr, mask, key, keySize);
        
        size_t chunk = (len - i < BLOCK_SIZE) ? len - i : BLOCK_SIZE;
        for (size_t j = 0; j < chunk; j++) {
            out[i + j] = in[i + j] ^ mask[j];
        }

        for (int j = BLOCK_SIZE - 1; j >= 0; j--) {
            if (++ctr[j] != 0) break;
        }
    }
}