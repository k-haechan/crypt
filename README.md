# 🛡️ Secure TCP Communication Project

C언어로 직접 구현한 암호화 모듈(AES, ARIA, SHA)을 활용하여, Windows와 macOS 환경에서 안전하게 데이터를 주고받는 보안 TCP 통신 시스템입니다. 

---

## 🎯 주요 기능
- 암호 알고리즘: AES-128/256, ARIA, SHA-256 직접 구현 및 검증
- 보안 프로토콜: 송신 데이터 암호화 및 무결성(HMAC) 검증 레이어 적용
- 크로스 플랫폼: Winsock2(Windows) 및 POSIX Socket(macOS/Linux) 공용 설계
- 모듈화: 도메인 중심 설계(Domain-Driven Design)로 각 알고리즘의 독립성 확보

---

## 📂 프로젝트 구조
my_secure_tcp/  
├── crypt/                # 암호화 도메인 (AES, ARIA, SHA)  
├── network/              # 네트워크 통신 모듈 (TCP Server/Client)  
├── src/                  # 메인 실행 소스 (server_main.c, client_main.c)  
├── tests/                # 단위 테스트 코드  
├── CMakeLists.txt        # 전체 빌드 설정  
└── README.md             # 프로젝트 설명서  

---

## 🛠️ 빌드 방법 (Build Instructions)

본 프로젝트는 CMake를 통해 각 운영체제에 최적화된 빌드 환경을 제공합니다.

### 1. 환경별 사전 요구 사항
- Windows (MSYS2): 
  - pacman -S mingw-w64-ucrt-x86_64-gcc
  - pacman -S mingw-w64-ucrt-x86_64-cmake
- macOS: 
  - Xcode Command Line Tools 설치 (xcode-select --install)
  - CMake 설치 (brew install cmake)

### 2. 컴파일 절차
터미널(또는 PowerShell)에서 아래 명령어를 순서대로 입력하세요.

# 1. 빌드 폴더 생성 및 이동
mkdir build
cd build

# 2. 빌드 환경 설정 (Generator 지정)
# [Windows - MSYS2 환경인 경우]
cmake .. -G "Unix Makefiles"

# [macOS / Linux 환경인 경우]
cmake ..

# 3. 프로젝트 빌드
cmake --build .

<!-- ---

## 🏃 실행 방법

빌드가 완료되면 build 디렉토리 내에 생성된 실행 파일을 사용합니다. (두 개의 터미널 필요)

서버 실행 (Terminal 1):
./server_main

클라이언트 실행 (Terminal 2):
./client_main

---

## 🛡️ 보안 통신 시퀀스 (Protocol)

1. Connection: 클라이언트가 서버에 TCP 연결을 요청합니다.
2. Handshake: 암호화에 사용할 대칭키를 안전하게 공유합니다.
3. Data Transfer: 모든 데이터는 설정된 알고리즘(AES/ARIA)으로 암호화되어 전송됩니다.
4. Verification: SHA-256을 통해 전송 중 데이터 변조 여부를 확인합니다. -->