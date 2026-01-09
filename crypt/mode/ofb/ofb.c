#include "ofb.h"
#include <string.h>

void Cipher_OFB_Process(block_cipher_func enc_func, const uint8_t *in, uint8_t *out, size_t len, const uint8_t *key, int keySize, const uint8_t *iv) {
    uint8_t feedback[BLOCK_SIZE];
    uint8_t mask[BLOCK_SIZE];
    memcpy(feedback, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        enc_func(feedback, mask, key, keySize);
        memcpy(feedback, mask, BLOCK_SIZE); 
        
        size_t chunk = (len - i < BLOCK_SIZE) ? len - i : BLOCK_SIZE;
        for (size_t j = 0; j < chunk; j++) {
            out[i + j] = in[i + j] ^ mask[j];
        }
    }
}