#ifndef PHIEU_H
#define PHIEU_H

#define MAX_PHIEU 100
#define MAX_STRING 100
#define MAX_ISBN_MUON 5

// Khai báo các mảng cho phiếu mượn
extern char maDocGiaMuon[MAX_PHIEU][MAX_STRING];       // Mã độc giả mượn
extern char maSachMuon[MAX_PHIEU][MAX_ISBN_MUON][MAX_STRING]; // Mảng lưu ISBN các sách mượn
extern char ngayMuon[MAX_PHIEU][11];                    // Ngày mượn
extern char ngayTraDuKien[MAX_PHIEU][11];              // Ngày trả dự kiến
extern int soSachMuon[MAX_PHIEU];                       // Số sách mỗi phiếu mượn
extern int daTra[MAX_PHIEU];                            // Trạng thái trả sách (0: chưa trả, 1: đã trả)
extern int soLuongPhieuMuon;                              // Số phiếu mượn hiện tại
extern char ngayTra[MAX_PHIEU][11];                    // Ngày trả

// Hàm khai báo
void lapPhieuMuon();
void lapPhieuTra();
void thongKeSoSachDangMuon();
void thongKeDocGiaTreHan();
void khoiTaoDuLieuPhieu();
int kiemTraQuaHan(const char *ngayMuon);

#endif
