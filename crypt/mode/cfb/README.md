# CFB (Cipher Feedback) Mode

## Description
이전 단계의 암호문을 암호화 함수의 입력으로 사용하여 평문과 XOR할 키 스트림을 생성합니다.

### Encryption / Decryption
![CFB Mode](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/CFB_encryption.svg/1280px-CFB_encryption.svg.png)
![CFB Mode Decryption](https://upload.wikimedia.org/wikipedia/commons/thumb/5/57/CFB_decryption.svg/600px-CFB_decryption.svg.png)

## Test
![CFB Test](../../imgs/tests/cfb_test.png)

## Reference
- Document: [NIST SP 800-38A](https://nvlpubs.nist.gov/nistpubs/legacy/sp/nistspecialpublication800-38a.pdf)
- Section: 6.3 Cipher Feedback Mode (Page 11)