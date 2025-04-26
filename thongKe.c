//
// Created by nhthinh on 26/04/2025.
//

#include <stdio.h>
#include "thongKe.h"

#include "docgia.h"
#include "phieu.h"
#include "sach.h"

void menuThongKe() {
    int luaChon;

    while (1) {
        // Hiển thị menu thống kê
        printf("\n=== MENU THONG KE ===\n");
        printf("1. Thong ke so luong sach trong thu vien\n");
        printf("2. Thong ke so luong sach theo the loai\n");
        printf("3. Thong ke so luong doc gia\n");
        printf("4. Thong ke so luong doc gia theo gioi tinh\n");
        printf("5. Thong ke so sach dang duoc muon\n");
        printf("6. Thong ke danh sach doc gia bi tre han\n");
        printf("0. Quay lai\n");
        scanf("%d", &luaChon);

        // Xử lý các lựa chọn từ người dùng
        switch (luaChon) {
            case 1:
                thongKeSoLuongSach(); // Gọi hàm thống kê số lượng sách
                break;
            case 2:
                thongKeSoLuongSachTheoTheLoai(); // Gọi hàm thống kê số lượng sách theo thể loại
                break;
            case 3:
                thongKeSoLuongDocGia(); // Gọi hàm thống kê số lượng độc giả
                break;
            case 4:
                thongKeSoLuongDocGiaTheoGioiTinh(); // Gọi hàm thống kê số lượng độc giả theo giới tính
                break;
            case 5:
                thongKeSoSachDangMuon(); // Gọi hàm thống kê số sách đang được mượn
                break;
            case 6:
                thongKeDocGiaTreHan(); // Gọi hàm thống kê danh sách độc giả bị trễ hạn
                break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    }
}
