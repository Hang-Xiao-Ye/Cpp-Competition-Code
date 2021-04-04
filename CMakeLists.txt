# CLionProject CMakeLists.txt :
# Created by Yhx.
# 2020-10-07 10:40

cmake_minimum_required(VERSION 3.15.3)

project(CMakeProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(PROJECT_NAME CMakeProject)

file(GLOB_RECURSE files *.cpp *.cxx *.c++ *.cc *.cp *.c)

foreach (file ${files})

    string(REGEX REPLACE ".+/(.+)" "\\1" exe ${file})

    IF (${file} MATCHES .vscode)
        CONTINUE()
    ENDIF (${file} MATCHES .vscode)
    IF (${file} MATCHES .idea)
        CONTINUE()
    ENDIF (${file} MATCHES .idea)
    IF (${file} MATCHES cmake-build-debug)
        CONTINUE()
    ENDIF (${file} MATCHES cmake-build-debug)

    add_executable(${exe} ${file})
    message("Adding executable : " ${file} " as " ${exe})
endforeach (file ${files})
