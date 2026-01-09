# CBC (Cipher Block Chaining) Mode

## Description
각 평문 블록을 이전 단계의 암호문 블록과 XOR 연산한 후 암호화합니다. 

### Encryption / Decryption
![CBC Mode](https://upload.wikimedia.org/wikipedia/commons/thumb/8/80/CBC_encryption.svg/600px-CBC_encryption.svg.png)
![CBC Mode Decryption](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2a/CBC_decryption.svg/600px-CBC_decryption.svg.png)

## Test
![CBC Test](../../imgs/tests/cbc_test.png)

## Reference
- Document: [NIST SP 800-38A](https://nvlpubs.nist.gov/nistpubs/legacy/sp/nistspecialpublication800-38a.pdf)
- Section: 6.2 Cipher Block Chaining Mode (Page 10)