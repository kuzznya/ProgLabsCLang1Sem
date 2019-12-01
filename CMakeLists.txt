cmake_minimum_required(VERSION 3.14)
project(ProgLabsCLang C)

set(CMAKE_C_STANDARD 99)

add_executable(ProgLabsCLang Lab14/main.c Lab14/bmp.c Lab14/bmp.h Lab14/gameio.c Lab14/gameio.h Lab14/gameoflife.c Lab14/gameoflife.h)