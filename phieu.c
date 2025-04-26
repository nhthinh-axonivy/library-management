#include "phieu.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

// Khai báo phiếu mượn
char maDocGiaMuon[MAX_PHIEU][MAX_STRING];
char maSachMuon[MAX_PHIEU][MAX_ISBN_MUON][MAX_STRING];
char ngayMuon[MAX_PHIEU][11];
char ngayTraDuKien[MAX_PHIEU][11];
int soSachMuon[MAX_PHIEU];
char ngayTra[MAX_PHIEU][11];
int daTra[MAX_PHIEU];
int soLuongPhieuMuon = 0;




// Kiểm tra quá hạn và trả về số ngày quá hạn
int kiemTraQuaHan(const char *ngayMuon) {
    time_t now = time(NULL);
    struct tm *today = localtime(&now);

    char ngayHienTai[11];
strftime(ngayHienTai, sizeof(ngayHienTai), "%d/%m/%Y", today);

    int soNgayMuon = tinhSoNgayGiua2Ngay(ngayMuon, ngayHienTai);

    if (soNgayMuon > 7) {
        return soNgayMuon - 7;
    } else {
        return 0;
    }
}

// Tạo phiếu mượn
void lapPhieuMuon() {
    if (soLuongPhieuMuon >= MAX_PHIEU) {
        printf("Da dat so luong phieu toi da.\n");
        return;
    }

    printf("Nhap ma doc gia: ");
    scanf("%s", maDocGiaMuon[soLuongPhieuMuon]);

    printf("Nhap ngay muon (dd/mm/yyyy): ");
    scanf("%s", ngayMuon[soLuongPhieuMuon]);

    printf("Nhap ngay tra du kien (dd/mm/yyyy): ");
    scanf("%s", ngayTraDuKien[soLuongPhieuMuon]);

    printf("Nhap so luong sach muon: ");
    scanf("%d", &soSachMuon[soLuongPhieuMuon]);

    for (int i = 0; i < soSachMuon[soLuongPhieuMuon]; i++) {
        printf("Nhap ISBN sach %d: ", i + 1);
        scanf("%s", maSachMuon[soLuongPhieuMuon][i]);
    }

    daTra[soLuongPhieuMuon] = 0; // Chưa trả
    soLuongPhieuMuon++;
    printf("Lap phieu muon thanh cong!\n");
}

// Tạo phiếu trả
void lapPhieuTra() {
    char maDocGia[MAX_STRING];
    printf("Nhap ma doc gia muon tra sach: ");
    scanf("%s", maDocGia);

    int timThay = 0;
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (strcmp(maDocGiaMuon[i], maDocGia) == 0 && daTra[i] == 0) {

            printf("Nhap ngay tra thuc te (dd/mm/yyyy): ");
            scanf("%s", ngayTra[soLuongPhieuMuon]);

            // Đánh dấu phiếu mượn đã trả
            daTra[i] = 1;
            printf("Tra sach thanh cong!\n");
            timThay = 1;
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay phieu muon chua tra cua doc gia nay.\n");
    }
}

// Thống kê số sách đang mượn
void thongKeSoSachDangMuon() {
    int tongSachDangMuon = 0;

    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (daTra[i] == 0) {
            tongSachDangMuon += soSachMuon[i];
        }
    }

    printf("Tong so sach dang duoc muon: %d\n", tongSachDangMuon);
}

// Thống kê độc giả trễ hạn
void thongKeDocGiaTreHan() {
    printf("Danh sach doc gia tre han:\n");

    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (daTra[i] == 0 && kiemTraQuaHan(ngayTraDuKien[i])) {
            printf("- Ma doc gia: %s\n", maDocGiaMuon[i]);
        }
    }
}

// Khởi tạo dữ liệu mặc định
void khoiTaoDuLieuPhieu() {
    // Dữ liệu phiếu mượn
    strcpy(maDocGiaMuon[0], "DG001");
    strcpy(ngayMuon[0], "01/04/2025");
    strcpy(ngayTraDuKien[0], "10/04/2025");
    strcpy(maSachMuon[0][0], "ISBN001");
    strcpy(maSachMuon[0][1], "ISBN002");
    soSachMuon[0] = 2;
    daTra[0] = 0; // Chưa trả

    strcpy(maDocGiaMuon[1], "DG002");
    strcpy(ngayMuon[1], "05/04/2025");
    strcpy(ngayTraDuKien[1], "12/04/2025");
    strcpy(maSachMuon[1][0], "ISBN003");
    strcpy(maSachMuon[1][1], "ISBN004");
    strcpy(maSachMuon[1][2], "ISBN005");
    soSachMuon[1] = 3;
    daTra[1] = 0; // Chưa trả

    strcpy(maDocGiaMuon[2], "DG003");
    strcpy(ngayMuon[2], "10/04/2025");
    strcpy(ngayTraDuKien[2], "20/04/2025");
    strcpy(maSachMuon[2][0], "ISBN006");
    soSachMuon[2] = 1;
    daTra[2] = 0; // Chưa trả

    strcpy(maDocGiaMuon[3], "DG004");
    strcpy(ngayMuon[3], "15/04/2025");
    strcpy(ngayTraDuKien[3], "25/04/2025");
    strcpy(maSachMuon[3][0], "ISBN007");
    strcpy(maSachMuon[3][1], "ISBN008");
    soSachMuon[3] = 2;
    daTra[3] = 1; // Đã trả

    strcpy(maDocGiaMuon[4], "DG005");
    strcpy(ngayMuon[4], "01/04/2025");
    strcpy(ngayTraDuKien[4], "10/04/2025");
    strcpy(maSachMuon[4][0], "ISBN009");
    strcpy(maSachMuon[4][1], "ISBN010");
    soSachMuon[4] = 2;
    daTra[4] = 0; // Chưa trả

    soLuongPhieuMuon = 5;
}
