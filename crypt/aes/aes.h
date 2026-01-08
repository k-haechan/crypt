#ifndef AES_H
#define AES_H

#include <stdint.h>

// keySize는 128, 192, 256 중 하나를 입력합니다.
void AES_Encrypt(const uint8_t *input, uint8_t *output, const uint8_t *key, int keySize);
void AES_Decrypt(const uint8_t *input, uint8_t *output, const uint8_t *key, int keySize);

#endif