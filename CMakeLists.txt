cmake_minimum_required(VERSION 3.30)
project(QuanLyThuVien C)

set(CMAKE_C_STANDARD 23)

add_executable(QuanLyThuVien main.c
        docgia.c
        docgia.h
        utils.c
        utils.h
        sach.h
        sach.c
)
