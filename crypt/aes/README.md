# AES (Advanced Encryption Standard) Module

이 모듈은 NIST(National Institute of Standards and Technology) 표준인 **FIPS 197**을 준수하는 AES 암호화 알고리즘 구현체를 포함하고 있습니다.

## 📌 개요
AES는 대칭키 암호화 방식으로, 전 세계적으로 가장 널리 사용되는 보안 알고리즘입니다. 본 프로젝트에서는 보안 통신을 위해 128-bit, 192-bit, 256-bit 키 길이를 지원하는 AES 모듈을 구현합니다.

## 📂 주요 기능
* **Key Expansion**: 입력받은 Cipher Key를 기반으로 Round Key 생성
* **Encryption (Cipher)**: 평문을 암호문으로 변환 (SubBytes, ShiftRows, MixColumns, AddRoundKey)
* **Decryption (Inverse Cipher)**: 암호문을 다시 평문으로 복호화
* **Mode of Operation**: (필요 시 추가 예정, 예: ECB, CBC, GCM 등)

## 🛠 구현 상세
* **Block Size**: 128 bits (16 bytes)
* **Key Lengths**: 128, 192, 256 bits 지원
* **State Matrix**: 4x4 행렬 구조를 통한 데이터 처리

## 🔗 Reference
본 모듈은 아래의 공식 표준 문서를 바탕으로 설계 및 구현되었습니다.
* **NIST FIPS 197 (AES Standard):** [https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf](https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf)

<!-- ## 🚀 사용법 (Example)
```c
#include "aes.h"

// AES-128 예시
unsigned char key[16] = { ... };
unsigned char plaintext[16] = { ... };
unsigned char ciphertext[16];

aes_encrypt(plaintext, key, ciphertext, AES_128); -->