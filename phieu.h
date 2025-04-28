#ifndef PHIEU_H
#define PHIEU_H

#define MAX_PHIEU 100
#define MAX_STRING 100
#define MAX_ISBN_MUON 5

// Khai báo các mảng cho phiếu mượn
extern char maDocGiaMuon[MAX_PHIEU][MAX_STRING];
extern char maSachMuon[MAX_PHIEU][MAX_ISBN_MUON][MAX_STRING];
extern char ngayMuon[MAX_PHIEU][11];
extern char ngayTraDuKien[MAX_PHIEU][11];
extern int soSachMuon[MAX_PHIEU];
extern int daTra[MAX_PHIEU];
extern int soLuongPhieuMuon;
extern int phat[MAX_PHIEU];
extern char ngayTra[MAX_PHIEU][11];
extern char ngayTraThucTe[MAX_PHIEU][11];

void lapPhieuMuon();
void lapPhieuTra();
void thongKeSoSachDangMuon();
void thongKeDocGiaTreHan();
void khoiTaoDuLieuPhieu();
int kiemTraQuaHan(const char *ngayMuon);

#endif
