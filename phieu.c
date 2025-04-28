//
// Created by nhthinh on 26/04/2025.
//

#include "phieu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "docgia.h"
#include "sach.h"
#include "utils.h"

// Khai báo phiếu mượn
char maDocGiaMuon[MAX_PHIEU][MAX_STRING];
char ngayMuon[MAX_PHIEU][11];
char ngayTraDuKien[MAX_PHIEU][11];
char ngayTraThucTe[MAX_PHIEU][11];
int soSachMuon[MAX_PHIEU];
char maSachMuon[MAX_PHIEU][MAX_ISBN_MUON][MAX_STRING];
char ngayTra[MAX_PHIEU][11];
int daTra[MAX_PHIEU];
int phat[MAX_PHIEU];
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

    char inputBuffer[20];

    // Kiểm tra độc giả tồn tại
    printf("Nhap ma doc gia: ");
    readLine(maDocGiaMuon[soLuongPhieuMuon], MAX_STRING);
    
    if (!kiemTraDocGiaTonTaiTheoMa(maDocGiaMuon[soLuongPhieuMuon])) {
        printf("Ma doc gia khong ton tai trong he thong. Huy lap phieu.\n");
        return;
    }

    // Lấy ngày hiện tại làm ngày mượn
    layNgayHienTai(ngayMuon[soLuongPhieuMuon], sizeof(ngayMuon[soLuongPhieuMuon]));
    printf("Ngay muon: %s\n", ngayMuon[soLuongPhieuMuon]);
    
    // Tính ngày trả dự kiến (7 ngày sau ngày mượn)
    tinhNgayTraDuKien7Ngay(ngayMuon[soLuongPhieuMuon], ngayTraDuKien[soLuongPhieuMuon], sizeof(ngayTraDuKien[soLuongPhieuMuon]));
    printf("Ngay tra du kien: %s\n", ngayTraDuKien[soLuongPhieuMuon]);

    printf("Nhap so luong sach muon (toi da %d): ", MAX_ISBN_MUON);
    readLine(inputBuffer, sizeof(inputBuffer));
    soSachMuon[soLuongPhieuMuon] = strtol(inputBuffer, NULL, 10);
    
    if (soSachMuon[soLuongPhieuMuon] <= 0 || soSachMuon[soLuongPhieuMuon] > MAX_ISBN_MUON) {
        printf("So luong sach khong hop le. Huy lap phieu.\n");
        return;
    }

    // Kiểm tra sách tồn tại trước khi cho mượn
    for (int i = 0; i < soSachMuon[soLuongPhieuMuon]; i++) {
        do {
            printf("Nhap ISBN sach %d: ", i + 1);
            readLine(maSachMuon[soLuongPhieuMuon][i], MAX_STRING);
            
            if (!kiemTraSachTonTaiTheoISBN(maSachMuon[soLuongPhieuMuon][i])) {
                printf("ISBN sach khong ton tai. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);
    }

    strcpy(ngayTraThucTe[soLuongPhieuMuon], "");
    strcpy(ngayTra[soLuongPhieuMuon], "");

    daTra[soLuongPhieuMuon] = 0;
    phat[soLuongPhieuMuon] = 0;
    soLuongPhieuMuon++;
    printf("Lap phieu muon thanh cong!\n");
}

// Tạo phiếu trả
void lapPhieuTra() {
    char maDocGia[MAX_STRING];
    printf("Nhap ma doc gia muon tra sach: ");
    readLine(maDocGia, sizeof(maDocGia));

    int timThay = -1;
    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (strcmp(maDocGiaMuon[i], maDocGia) == 0 && daTra[i] == 0) {
            timThay = i;
            break;
        }
    }

    if (timThay != -1) {
        int index = timThay;
        printf("Nhap ngay tra thuc te (dd/mm/yyyy): ");
        readLine(ngayTraThucTe[index], sizeof(ngayTraThucTe[index]));
        strcpy(ngayTra[index], ngayTraThucTe[index]);

        // Kiểm tra và xử lý sách bị mất
        char inputBuffer[10];
        phat[index] = 0; // Reset mức phạt

        // Xử lý từng sách trong phiếu mượn
        for (int i = 0; i < soSachMuon[index]; i++) {
            int trangThai = 0;
            do {
                printf("\nSach %d (ISBN: %s):\n", i + 1, maSachMuon[index][i]);
                printf("1. Da tra\n");
                printf("2. Bi mat\n");
                printf("Nhap lua chon (1 hoac 2): ");
                readLine(inputBuffer, sizeof(inputBuffer));
                trangThai = atoi(inputBuffer);
                
                if (trangThai != 1 && trangThai != 2) {
                    printf("Lua chon khong hop le. Vui long chon 1 hoac 2.\n");
                }
            } while (trangThai != 1 && trangThai != 2);
        
            if (trangThai == 2) { // Sách bị mất
                // Tìm giá sách để tính tiền phạt
                int timThay = 0;
                for (int j = 0; j < soLuongSach; j++) {
                    if (strcmp(ISBN[j], maSachMuon[index][i]) == 0) {
                        int tienPhatMat = giaSach[j] * 2; // 200% giá sách
                        phat[index] += tienPhatMat;
                        printf("Sach bi mat. Tien phat: %d VND (200%% gia sach).\n", tienPhatMat);
                        timThay = 1;
                        break;
                    }
                }
                if (!timThay) {
                    printf("Khong tim thay thong tin sach trong he thong.\n");
                }
            } else {
                printf("Sach da duoc tra thanh cong.\n");
            }
        }

        // Tính thêm tiền phạt nếu trả trễ
        int soNgayTre = tinhSoNgayGiua2Ngay(ngayTraDuKien[index], ngayTraThucTe[index]);
        if (soNgayTre > 0) {
            int tienPhatTre = soNgayTre * 5000;
            phat[index] += tienPhatTre;
            printf("Phieu tra tre %d ngay. Tien phat: %d VND.\n", soNgayTre, tienPhatTre);
        }

        // Hiển thị tổng tiền phạt
        if (phat[index] > 0) {
            printf("Tong tien phat: %d VND.\n", phat[index]);
        } else {
            printf("Khong co tien phat.\n");
        }

        // Đánh dấu phiếu mượn đã trả
        daTra[index] = 1;
        printf("Tra sach thanh cong!\n");

    } else {
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
    int count = 0;
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    char ngayHienTai[11];
    strftime(ngayHienTai, sizeof(ngayHienTai), "%d/%m/%Y", today);


    for (int i = 0; i < soLuongPhieuMuon; i++) {
        if (daTra[i] == 0 && tinhSoNgayGiua2Ngay(ngayTraDuKien[i], ngayHienTai) > 0) {
             printf("- Ma doc gia: %s (Du kien tra: %s)\n", maDocGiaMuon[i], ngayTraDuKien[i]);
             count++;
        }
    }
    if (count == 0) {
        printf("Khong co doc gia nao tre han.\n");
    }
}

// Khởi tạo dữ liệu
void khoiTaoDuLieuPhieu() {

    //tre han
    strcpy(maDocGiaMuon[0], "DG001");
    strcpy(ngayMuon[0], "01/04/2025");
    strcpy(ngayTraDuKien[0], "10/04/2025");
    strcpy(maSachMuon[0][0], "ISBN001");
    strcpy(maSachMuon[0][1], "ISBN002");
    soSachMuon[0] = 2;
    daTra[0] = 0;
    strcpy(ngayTraThucTe[0], "");
    phat[0] = 0;

    //tre han
    strcpy(maDocGiaMuon[1], "DG002");
    strcpy(ngayMuon[1], "05/04/2025");
    strcpy(ngayTraDuKien[1], "12/04/2025");
    strcpy(maSachMuon[1][0], "ISBN003");
    strcpy(maSachMuon[1][1], "ISBN004");
    strcpy(maSachMuon[1][2], "ISBN005");
    soSachMuon[1] = 3;
    daTra[1] = 0; // Chưa trả
    strcpy(ngayTraThucTe[1], "");
    phat[1] = 0;

    //tre han
    strcpy(maDocGiaMuon[2], "DG003");
    strcpy(ngayMuon[2], "10/04/2025");
    strcpy(ngayTraDuKien[2], "20/04/2025");
    strcpy(maSachMuon[2][0], "ISBN006");
    soSachMuon[2] = 1;
    daTra[2] = 0; // Chưa trả
    strcpy(ngayTraThucTe[2], "");
    phat[2] = 0;

    strcpy(maDocGiaMuon[3], "DG004");
    strcpy(ngayMuon[3], "15/04/2025");
    strcpy(ngayTraDuKien[3], "25/04/2025");
    strcpy(maSachMuon[3][0], "ISBN007");
    strcpy(maSachMuon[3][1], "ISBN008");
    soSachMuon[3] = 2;
    daTra[3] = 1; // Đã trả
    strcpy(ngayTraThucTe[3], "24/04/2025");
    strcpy(ngayTra[3], ngayTraThucTe[3]);
    phat[3] = 0;

    //Tre han
    strcpy(maDocGiaMuon[4], "DG005");
    strcpy(ngayMuon[4], "01/04/2025");
    strcpy(ngayTraDuKien[4], "10/04/2025");
    strcpy(maSachMuon[4][0], "ISBN009");
    strcpy(maSachMuon[4][1], "ISBN010");
    soSachMuon[4] = 2;
    daTra[4] = 0; // Chưa trả
    strcpy(ngayTraThucTe[4], "");
    phat[4] = 0;

    soLuongPhieuMuon = 5;
}

