#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cbc.h"
#include "../../aes/aes.h"

#ifdef _WIN32
#include <windows.h>
#endif

// NIST SP 800-38A F.2.1 (AES-128, CBC)
static const uint8_t NIST_KEY[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
static const uint8_t NIST_IV[]  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
static const uint8_t NIST_PT[]  = {0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a};
static const uint8_t NIST_CT[]  = {0x76, 0x49, 0xab, 0xac, 0x81, 0x19, 0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b, 0x12, 0xe9, 0x19, 0x7d};

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
    printf("--- AES-128 CBC NIST SP 800-38A 테스트 시작 ---\n");
    print_hex_short("평문 (Plaintext)", NIST_PT, 16);
    print_hex_short("IV", NIST_IV, 16);

    Cipher_CBC_Encrypt(AES_Encrypt, NIST_PT, cipher, 16, NIST_KEY, 128, NIST_IV);
    print_hex_short("암호문 (Ciphertext)", cipher, 16);
    if (memcmp(cipher, NIST_CT, 16) == 0) printf("[성공] 암호문이 NIST 표준과 일치합니다.\n");
    else printf("[실패] 암호문 불일치.\n");

    Cipher_CBC_Decrypt(AES_Decrypt, cipher, decrypted, 16, NIST_KEY, 128, NIST_IV);
    print_hex_short("복호화 (Decrypted)", decrypted, 16);
    if (memcmp(decrypted, NIST_PT, 16) == 0) printf("[성공] 복호화된 데이터가 원본 평문과 일치합니다.\n");
    else printf("[실패] 복호화 데이터 불일치.\n");

    return 0;
}