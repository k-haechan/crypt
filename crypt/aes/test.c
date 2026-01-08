#include <stdio.h>
#include <string.h>
#include "aes.h"

// 윈도우용 헤더
#ifdef _WIN32
#include <windows.h>
#endif

void print_hex(const char *label, const uint8_t *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) printf("%02x ", data[i]);
    printf("\n");
}

int main() {
    // 윈도우 터미널 출력 인코딩을 UTF-8로 강제 설정
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    // FIPS 197 Appendix C.1 - AES-128 Test Vector
    uint8_t key[16] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    uint8_t plaintext[16] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
        0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
    };
    uint8_t ciphertext[16];
    uint8_t decrypted[16];

    // 예상되는 암호문 (Expected Ciphertext)
    uint8_t expected[16] = {
        0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 
        0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a
    };

    printf("--- AES-128 FIPS 197 테스트 시작 ---\n");
    print_hex("평문 (Plaintext)  ", plaintext, 16);
    print_hex("키 (Key)          ", key, 16);

    // 1. 암호화 수행
    AES_Encrypt(plaintext, ciphertext, key, 128);
    print_hex("암호문 (Ciphertext)", ciphertext, 16);

    if (memcmp(ciphertext, expected, 16) == 0) {
        printf("[성공] 암호문이 FIPS 197 Appendix C.1 표준과 일치합니다.\n");
    } else {
        printf("[실패] 암호문이 표준 결과와 다릅니다!\n");
    }

    // 2. 복호화 수행
    AES_Decrypt(ciphertext, decrypted, key, 128);
    print_hex("복호화 (Decrypted) ", decrypted, 16);

    if (memcmp(plaintext, decrypted, 16) == 0) {
        printf("[성공] 복호화된 데이터가 원본 평문과 일치합니다.\n");
    } else {
        printf("[실패] 복호화 데이터가 원본과 다릅니다!\n");
    }

    return 0;
}