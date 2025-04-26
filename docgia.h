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

// Menu quản lý độc giả
void menuDocGia();

// Thêm độc giả
void themDocGia();

// Danh sách độc giả
void hienThiDanhSachDocGia();

// Tìm độc giả theo CMND
void timKiemDocGiaTheoCMND(const char *cmnd);

// Tìm độc giả theo tên
void timKiemDocGiaTheoTen(const char *ten);

// Xóa độc giả theo id
void xoaDocGiaTheoMa(const char *id);

// cập nhập độc giả theo id
void capNhatDocGiaTheoMa(const char *id);

void khoiTaoDocGiaMacDinh();

#endif //DOCGIA_H
