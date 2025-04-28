//
// Created by nht82 on 26/04/2025.
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

void menuSach(void);
void hienThiDanhSachSach();
void themSach();
void xoaSachTheoISBN(const char *isbn);
void capNhatSachTheoISBN(const char *isbn);
void timSachTheoISBN(const char *isbn);
void timSachTheoTen(const char *ten);
int kiemTraSachTonTaiTheoISBN(const char *isbn);
void thongKeSoLuongSach();
void thongKeSoLuongSachTheoTheLoai();
void khoiTaoSach();

#endif //SACH_H
