//
// Created by nht82 on 4/26/2025.
//

#ifndef SACH_H
#define SACH_H

#define MAX_SACH 100
#include "utils.h"

extern char ISBN[MAX_SACH][MAX_STRING];
extern char tenSach[MAX_SACH][MAX_STRING];
extern char tacGia[MAX_SACH][MAX_STRING];
extern char nhaXuatBan[MAX_SACH][MAX_STRING];
extern int namXuatBan[MAX_SACH];
extern char theLoai[MAX_SACH][MAX_STRING];
extern int giaSach[MAX_SACH];
extern int soLuongSach;

// Menu quản lý sách
void menuSach(void);

void hienThiDanhSachSach();

//Thêm sách
void themSach();

//Xóa sách theo ISBN
void xoaSachTheoISBN(const char *isbn);

//Cập nhập sách theo ISBN
void capNhatSachTheoISBN(const char *isbn);

//Tìm sách theo ISBN
void timSachTheoISBN(const char *isbn);

//Tìm kiếm sách theo tên
void timSachTheoTen(const char *ten);

void khoiTaoSachMacDinh();

#endif //SACH_H
