cmake_minimum_required(VERSION 3.12)
project(SIKKA)
set(CMAKE_C_STANDARD 11)

set(
    SOURCES
    src/block.c
    src/blockchain.c
    src/mine.c
)

include_directories(./include)

add_executable(core ${SOURCES} src/main.c)