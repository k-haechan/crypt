cmake_minimum_required(VERSION 3.10)
project(AES_Module C)

# 1. AES 라이브러리 생성
add_library(aes STATIC aes.c)

# 2. 테스트 실행 파일 생성
add_executable(aes_test test.c)

# 3. 테스트 실행 파일에 aes 라이브러리 링크
target_link_libraries(aes_test PRIVATE aes)

# 4. 헤더 파일 경로 설정
target_include_directories(aes_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})