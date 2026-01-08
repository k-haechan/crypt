# 1. CMake 최소 요구 버전 (설치하신 버전에 맞춰 보통 3.10 이상으로 설정)
cmake_minimum_required(VERSION 3.10)

# 2. 프로젝트 이름 설정
project(MyCryptProject)

# 3. 실행 파일 생성 설정
# 형식: add_executable(생성할_파일명 소스_파일명)
add_executable(main_app main.c)