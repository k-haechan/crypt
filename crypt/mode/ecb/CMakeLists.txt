cmake_minimum_required(VERSION 3.10)
project(ecb_test C)

# 헤더 파일 경로 설정 (현재 폴더, 공통 폴더, AES 폴더)
include_directories(. .. ../../aes)

# 빌드에 필요한 모든 소스 파일
set(SOURCES 
    ecb.c 
    test.c 
    ../../aes/aes.c
)

# 실행 파일 생성
add_executable(ecb_test ${SOURCES})