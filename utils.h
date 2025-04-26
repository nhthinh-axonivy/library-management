//
// Created by nhthinh on 26/04/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include "utils.h"
#define MAX_STRING 100

void layNgayHienTai(char *buffer, int maxLen);
void tinhNgayHetHan48Thang(const char *ngayLap, char *ngayHetHan, int maxLen);
void tinhNgayTraDuKien7Ngay(const char *ngayMuon, char *ngayTraDuKien, int maxLen);
int tinhSoNgayGiua2Ngay(const char *ngay1, const char *ngay2);
int laNamNhuan(int nam);
int ngayTrongThang(int thang, int nam);
int tinhNgayTrongNam(int ngay, int thang, int nam);
void ketThucChucNang();

#endif //UTILS_H
