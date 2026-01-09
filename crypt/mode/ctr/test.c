#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "ctr.h"
#include "../../aes/aes.h"

#ifdef _WIN32
#include <windows.h>
#endif

// NIST SP 800-38A F.5.1 (AES-128, CTR)
static const uint8_t NIST_KEY[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
static const uint8_t NIST_CTR[] = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff};
static const uint8_t NIST_PT[]  = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a};
static const uint8_t NIST_CT[]  = {0x87, 0x4d, 0x61, 0x91, 0xb6, 0x20, 0xe3, 0x26, 0x1b, 0xef, 0x68, 0x64, 0x99, 0x0d, 0xb6, 0xce};

void print_hex_short(const char *label, const uint8_t *data, size_t len) {
    printf("%-18s: ", label);
    if (len <= 12) {
        for (size_t i = 0; i < len; i++) printf("%02x ", data[i]);
    } else {
        for (size_t i = 0; i < 6; i++) printf("%02x ", data[i]);
        printf("... ");
        for (size_t i = len - 6; i < len; i++) printf("%02x ", data[i]);
    }
    printf("\n");
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    uint8_t cipher[16], decrypted[16];
    printf("--- AES-128 CTR NIST SP 800-38A 테스트 시작 ---\n");

    Cipher_CTR_Process(AES_Encrypt, NIST_PT, cipher, 16, NIST_KEY, 128, NIST_CTR);
    print_hex_short("암호문 (Ciphertext)", cipher, 16);
    if (memcmp(cipher, NIST_CT, 16) == 0) printf("[성공] 암호문이 NIST 표준과 일치합니다.\n");
    else printf("[실패] 암호문 불일치.\n");

    Cipher_CTR_Process(AES_Encrypt, cipher, decrypted, 16, NIST_KEY, 128, NIST_CTR);
    print_hex_short("복호화 (Decrypted)", decrypted, 16);
    if (memcmp(decrypted, NIST_PT, 16) == 0) printf("[성공] 복호화된 데이터가 원본 평문과 일치합니다.\n");
    else printf("[실패] 복호화 데이터 불일치.\n");

    return 0;
}