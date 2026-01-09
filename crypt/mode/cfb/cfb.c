#include "cfb.h"
#include <string.h>

void Cipher_CFB_Encrypt(block_cipher_func enc_func, const uint8_t *plain, uint8_t *cipher, size_t len, const uint8_t *key, int keySize, const uint8_t *iv) {
    uint8_t feedback[BLOCK_SIZE];
    memcpy(feedback, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        uint8_t mask[BLOCK_SIZE];
        enc_func(feedback, mask, key, keySize);
        
        for (int j = 0; j < BLOCK_SIZE; j++) cipher[i + j] = plain[i + j] ^ mask[j];
        memcpy(feedback, &cipher[i], BLOCK_SIZE);
    }
}

void Cipher_CFB_Decrypt(block_cipher_func enc_func, const uint8_t *cipher, uint8_t *plain, size_t len, const uint8_t *key, int keySize, const uint8_t *iv) {
    uint8_t feedback[BLOCK_SIZE];
    memcpy(feedback, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        uint8_t mask[BLOCK_SIZE];
        // 복호화 시에도 알고리즘의 Encrypt 엔진이 필요하므로 enc_func을 사용합니다.
        enc_func(feedback, mask, key, keySize);
        
        for (int j = 0; j < BLOCK_SIZE; j++) plain[i + j] = cipher[i + j] ^ mask[j];
        memcpy(feedback, &cipher[i], BLOCK_SIZE);
    }
}