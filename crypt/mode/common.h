#ifndef MODE_COMMON_H
#define MODE_COMMON_H

#include <stdint.h>
#include <stddef.h>

#define BLOCK_SIZE 16

// 블록 암호 알고리즘 함수 포인터 타입 (AES_Encrypt, ARIA_Encrypt 등과 호환)
typedef void (*block_cipher_func)(const uint8_t *in, uint8_t *out, const uint8_t *key, int keySize);

#endif