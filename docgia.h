//
// Created by nhthinh on 25/04/2025.
//

#ifndef DOCGIA_H
#define DOCGIA_H


#define MAX_DOCGIA 100
#include "utils.h"

extern char maDocGia[MAX_DOCGIA][MAX_STRING];
extern char hoVaTen[MAX_DOCGIA][MAX_STRING];
extern char cmnd[MAX_DOCGIA][MAX_STRING];
extern char ngaySinh[MAX_DOCGIA][MAX_STRING];
extern char gioiTinh[MAX_DOCGIA][MAX_STRING];
extern char email[MAX_DOCGIA][MAX_STRING];
extern char diaChi[MAX_DOCGIA][MAX_STRING];
extern char ngayLapThe[MAX_DOCGIA][MAX_STRING];
extern char ngayHetHan[MAX_DOCGIA][MAX_STRING];
extern int soLuongDocGia;

void menuDocGia();
void themDocGia();
void hienThiDanhSachDocGia();
void timKiemDocGiaTheoCMND(const char *cmnd);
void timKiemDocGiaTheoTen(const char *ten);
void xoaDocGiaTheoMa(const char *id);
void capNhatDocGiaTheoMa(const char *id);
int kiemTraDocGiaTonTaiTheoMa(const char *ma);
int kiemTraDocGiaTonTaiTheoCMND(const char *cmnd);
void thongKeSoLuongDocGia();
void thongKeSoLuongDocGiaTheoGioiTinh();
void khoiTaoDocGia();

#endif //DOCGIA_H
