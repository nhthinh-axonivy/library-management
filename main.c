//
// Created by nhthinh on 25/04/2025.
//

#include <stdio.h>

#include "docgia.h"
#include "phieu.h"
#include "sach.h"
#include "thongKe.h"
#include <stdlib.h>
#include "utils.h"


int main() {
    khoiTaoDocGia();
    khoiTaoSach();
    khoiTaoDuLieuPhieu();
    int luaChon;
    char inputBuffer[20];

    do {
        printf("\n===== HE THONG QUAN LY THU VIEN =====\n");
        printf("===== MENU CHINH =====\n");
        printf("1. Quan ly doc gia\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");

        readLine(inputBuffer, sizeof(inputBuffer));
        luaChon = atoi(inputBuffer);

        switch (luaChon) {
            case 1: menuDocGia();
                break;
            case 2: menuSach();
                break;
            case 3: lapPhieuMuon(); break;
            case 4: lapPhieuTra(); break;
            case 5: menuThongKe(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le. Vui long chon lai.\n"); break;
        }
    } while (luaChon != 0);
    return 0;
}
