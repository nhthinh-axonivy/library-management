#include <stdio.h>

#include "docgia.h"
#include "phieu.h"
#include "sach.h"
#include "thongKe.h"


int main() {
    khoiTaoDocGia();
    khoiTaoSach();
    khoiTaoDuLieuPhieu();
    int luaChon;
    do {
        printf("===== MENU CHINH =====\n");
        printf("1. Quan ly doc gia\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap phieu muon sach\n");
        printf("4. Lap phieu tra sach\n");
        printf("5. Thong ke\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1: menuDocGia();
                break;
            case 2: menuSach();
                break;
            case 3: lapPhieuMuon(); break;
            case 4: lapPhieuTra(); break;
            case 5: menuThongKe(); break;
        }
    } while (luaChon != 0);
    return 0;
}
