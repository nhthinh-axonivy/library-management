//
// Created by nhthinh on 25/04/2025.
//
#include <stdio.h>
#include <string.h>
#include "docgia.h"

#include <ctype.h>

#include "utils.h"


char maDocGia[MAX_DOCGIA][MAX_STRING];
char hoVaTen[MAX_DOCGIA][MAX_STRING];
char cmnd[MAX_DOCGIA][MAX_STRING];
char ngaySinh[MAX_DOCGIA][MAX_STRING];
char gioiTinh[MAX_DOCGIA][MAX_STRING];
char email[MAX_DOCGIA][MAX_STRING];
char diaChi[MAX_DOCGIA][MAX_STRING];
char ngayLapThe[MAX_DOCGIA][MAX_STRING];
char ngayHetHan[MAX_DOCGIA][MAX_STRING];
int soLuongDocGia = 0;
int demMaDocGia = 0;


void menuDocGia() {
    int chon;
    char input[MAX_STRING];
    do {
        printf("\n===== QUAN LY DOC GIA =====\n");
        printf("1. Hien thi danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Cap nhat theo ma\n");
        printf("4. Xoa doc gia theo ma\n");
        printf("5. Tim kiem theo CMND\n");
        printf("6. Tim kiem theo ho va ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                hienThiDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                printf("Nhap ma doc gia can cap nhat: ");
                scanf("%s", input);
                capNhatDocGiaTheoMa(input);
                break;
            case 4:
                printf("Nhap ma doc gia can xoa: ");
                scanf("%s", input);
                xoaDocGiaTheoMa(input);
                break;
            case 5:
                printf("Nhap CMND doc gia can tim: ");
                scanf("%s", input);
                timKiemDocGiaTheoCMND(input);
                break;
            case 6:
                printf("Nhap ho ten doc gia can tim: ");
                scanf(" %[^\n]s", input);
                timKiemDocGiaTheoTen(input);
                break;
        }
    } while (chon != 0);
}

void themDocGia() {
    if (soLuongDocGia >= MAX_DOCGIA) {
        printf("Danh sach doc gia da day, vui long xoa bot doc gia!\n");
        ketThucChucNang();
    }

    sprintf(maDocGia[soLuongDocGia], "DG%03d", demMaDocGia + 1);
    printf("Ma doc gia duoc tao tu dong: %s\n", maDocGia[soLuongDocGia]);

    char ngayLap[11];
    layNgayHienTai(ngayLap, sizeof(ngayLap));
    strcpy(ngayLapThe[soLuongDocGia], ngayLap);

    char hetHan[11];
    tinhNgayHetHan48Thang(ngayLap, hetHan, sizeof(hetHan));
    strcpy(ngayHetHan[soLuongDocGia], hetHan);

    printf("Nhap ho va ten: ");
    scanf(" %[^\n]s", hoVaTen[soLuongDocGia]);

    printf("Nhap CMND: ");
    scanf("%s", cmnd[soLuongDocGia]);

    printf("Nhap ngay sinh: ");
    scanf("%s", ngaySinh[soLuongDocGia]);

    printf("Nhap gioi tinh: ");
    scanf("%s", gioiTinh[soLuongDocGia]);

    printf("Nhap email: ");
    scanf("%s", email[soLuongDocGia]);

    printf("Nhap dia chi: ");
    scanf(" %[^\n]s", diaChi[soLuongDocGia]);

    soLuongDocGia++;
    demMaDocGia++;
    ketThucChucNang();
}


// Hiển thị danh sách độc giả
void hienThiDanhSachDocGia() {
    printf("=== DANH SACH DOC GIA ===\n");
    for (int i = 0; i < soLuongDocGia; i++) {
        printf("Doc gia %d:\n", i + 1);
        printf("  Ma doc gia     : %s\n", maDocGia[i]);
        printf("  Ho va ten      : %s\n", hoVaTen[i]);
        printf("  CMND           : %s\n", cmnd[i]);
        printf("  Ngay sinh      : %s\n", ngaySinh[i]);
        printf("  Gioi tinh      : %s\n", gioiTinh[i]);
        printf("  Email          : %s\n", email[i]);
        printf("  Dia chi        : %s\n", diaChi[i]);
        printf("  Ngay lap the   : %s\n", ngayLapThe[i]);
        printf("  Ngay het han   : %s\n", ngayHetHan[i]);
        printf("----------------------------------------\n");
    }
    printf("=====================================\n");
    ketThucChucNang();
}


// Tìm độc giả theo CMND
void timKiemDocGiaTheoCMND(const char *cmndCanTim) {
    int found = 0;

    for (int i = 0; i < soLuongDocGia; i++) {
        if (kiemTraDocGiaTonTaiTheoCMND(cmndCanTim)) {
            printf("Tim thay doc gia:\n");
            printf("Doc gia %d:\n", i + 1);
            printf("  Ma doc gia     : %s\n", maDocGia[i]);
            printf("  Ho va ten      : %s\n", hoVaTen[i]);
            printf("  CMND           : %s\n", cmnd[i]);
            printf("  Ngay sinh      : %s\n", ngaySinh[i]);
            printf("  Gioi tinh      : %s\n", gioiTinh[i]);
            printf("  Email          : %s\n", email[i]);
            printf("  Dia chi        : %s\n", diaChi[i]);
            printf("  Ngay lap the   : %s\n", ngayLapThe[i]);
            printf("  Ngay het han   : %s\n", ngayHetHan[i]);
            printf("----------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi cmnd: %s\n", cmndCanTim);
        printf("----------------------------------------\n");
    }
    ketThucChucNang();
}

// Tìm độc giả theo họ tên
void timKiemDocGiaTheoTen(const char *tenCanTim) {
    int found = 0;
    char tenCanTimLowercase[MAX_STRING];
    strcpy(tenCanTimLowercase, tenCanTim);
    for (char *p = tenCanTimLowercase; *p; ++p) *p = tolower(*p);

    for (int i = 0; i < soLuongDocGia; i++) {
        char tenDocGiaLowercase[MAX_STRING];
        strcpy(tenDocGiaLowercase, hoVaTen[i]);
        for (char *q = tenDocGiaLowercase; *q; ++q) *q = tolower(*q);

        if (strstr(tenDocGiaLowercase, tenCanTimLowercase) != NULL) {
            if (!found) {
                printf("=== Ket qua tim kiem ===\n");
            }
            printf("Doc gia %d:\n", i + 1);
            printf("  Ma doc gia     : %s\n", maDocGia[i]);
            printf("  Ho va ten      : %s\n", hoVaTen[i]);
            printf("  CMND           : %s\n", cmnd[i]);
            printf("  Ngay sinh      : %s\n", ngaySinh[i]);
            printf("  Gioi tinh      : %s\n", gioiTinh[i]);
            printf("  Email          : %s\n", email[i]);
            printf("  Dia chi        : %s\n", diaChi[i]);
            printf("  Ngay lap the   : %s\n", ngayLapThe[i]);
            printf("  Ngay het han   : %s\n", ngayHetHan[i]);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi ten: %s\n", tenCanTim);
        printf("----------------------------------------\n");
    }

    ketThucChucNang();
}


// Xóa thông tin độc giả theo mã
void xoaDocGiaTheoMa(const char *ma) {
    int found = 0;

    for (int i = 0; i < soLuongDocGia; i++) {
        if (kiemTraDocGiaTonTaiTheoMa(ma)) {
            found = 1;
            printf("Tim thay doc gia: %s\n", hoVaTen[i]);
            printf("Nhap 'Y' de xoa: ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
                for (int j = i; j < soLuongDocGia - 1; j++) {
                    strcpy(maDocGia[j], maDocGia[j + 1]);
                    strcpy(hoVaTen[j], hoVaTen[j + 1]);
                    strcpy(cmnd[j], cmnd[j + 1]);
                    strcpy(ngaySinh[j], ngaySinh[j + 1]);
                    strcpy(gioiTinh[j], gioiTinh[j + 1]);
                    strcpy(email[j], email[j + 1]);
                    strcpy(diaChi[j], diaChi[j + 1]);
                    strcpy(ngayLapThe[j], ngayLapThe[j + 1]);
                    strcpy(ngayHetHan[j], ngayHetHan[j + 1]);
                }
                soLuongDocGia--;
                printf("Doc gia da duoc xoa thanh cong!\n");
            } else {
                printf("Huy xoa doc gia.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi ma: %s\n", ma);
    }
    ketThucChucNang();
}


// Cập nhật thông tin độc giả theo mã
void capNhatDocGiaTheoMa(const char *ma) {
    char input[MAX_STRING];

    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], ma) == 0) {
            printf("Tim thay doc gia %d:\n", i + 1);

            printf("  Ho va ten      : %s\n", hoVaTen[i]);
            printf("Cap nhat ho va ten (Enter de giu nguyen): ");
            scanf(" %[^\n]s", input);
            if (strlen(input) > 0) strcpy(hoVaTen[i], input);

            printf("  CMND           : %s\n", cmnd[i]);
            printf("Cap nhat CMND (Enter de giu nguyen): ");
            scanf("%s", input);
            if (strlen(input) > 0) strcpy(cmnd[i], input);

            printf("  Ngay sinh      : %s\n", ngaySinh[i]);
            printf("Cap nhat ngay sinh (Enter de giu nguyen): ");
            scanf("%s", input);
            if (strlen(input) > 0) strcpy(ngaySinh[i], input);

            printf("  Gioi tinh      : %s\n", gioiTinh[i]);
            printf("Cap nhat gioi tinh (Enter de giu nguyen): ");
            scanf("%s", input);
            if (strlen(input) > 0) strcpy(gioiTinh[i], input);

            printf("  Email          : %s\n", email[i]);
            printf("Cap nhat email (Enter de giu nguyen): ");
            scanf("%s", input);
            if (strlen(input) > 0) strcpy(email[i], input);

            printf("  Dia chi        : %s\n", diaChi[i]);
            printf("Cap nhat dia chi (Enter de giu nguyen): ");
            scanf(" %[^\n]s", input);
            if (strlen(input) > 0) strcpy(diaChi[i], input);

            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay ma doc gia voi ma: %s\n", ma);
    ketThucChucNang();
}

//Thống kê số lượng độc giả đang có trong hệ thống.
void thongKeSoLuongDocGia() {
    printf("Tong so luong doc gia: %d\n", soLuongDocGia);
    ketThucChucNang();
}

//Thống kee số lượng độc giả theo giới tính  
void thongKeSoLuongDocGiaTheoGioiTinh() {
    int nam = 0, nu = 0;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(gioiTinh[i], "Nam") == 0) nam++;
        else if (strcmp(gioiTinh[i], "Nu") == 0) nu++;
    }
    printf("Doc gia Nam: %d, Doc gia Nu: %d\n", nam, nu);
    ketThucChucNang();
}


int kiemTraDocGiaTonTaiTheoMa(const char *ma) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], ma) == 0) return 1;
    }
    return 0;
}

int kiemTraDocGiaTonTaiTheoCMND(const char *cmnd) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(cmnd[i], cmnd == 0)) return 1;
    }
    return 0;
}

// Khoi tao test data doc gia
void khoiTaoDocGia() {
    // Độc giả 1
    strcpy(maDocGia[0], "DG001");
    strcpy(hoVaTen[0], "Nguyen Hung Thinh");
    strcpy(cmnd[0], "24810216");
    strcpy(ngaySinh[0], "08/02/1999");
    strcpy(gioiTinh[0], "Nam");
    strcpy(email[0], "24810216@student.hcmus.edu.vn");
    strcpy(diaChi[0], "09 Nguyen Tu Nha");
    strcpy(ngayLapThe[0], "25/04/2025");
    strcpy(ngayHetHan[0], "25/04/2029");
    soLuongDocGia++;
    demMaDocGia++;

    // Độc giả 2
    strcpy(maDocGia[1], "DG002");
    strcpy(hoVaTen[1], "Nguyen Thanh Thanh");
    strcpy(cmnd[1], "25810217");
    strcpy(ngaySinh[1], "15/06/2000");
    strcpy(gioiTinh[1], "Nu");
    strcpy(email[1], "25810217@student.hcmus.edu.vn");
    strcpy(diaChi[1], "39B Truong Son");
    strcpy(ngayLapThe[1], "25/04/2025");
    strcpy(ngayHetHan[1], "25/04/2029");
    soLuongDocGia++;
    demMaDocGia++;

    // Độc giả 3
    strcpy(maDocGia[2], "DG003");
    strcpy(hoVaTen[2], "Le Van Tuan");
    strcpy(cmnd[2], "26810218");
    strcpy(ngaySinh[2], "22/08/1998");
    strcpy(gioiTinh[2], "Nam");
    strcpy(email[2], "26810218@student.hcmus.edu.vn");
    strcpy(diaChi[2], "123 Le Loi");
    strcpy(ngayLapThe[2], "26/04/2025");
    strcpy(ngayHetHan[2], "26/04/2029");
    soLuongDocGia++;
    demMaDocGia++;

    // Độc giả 4
    strcpy(maDocGia[3], "DG004");
    strcpy(hoVaTen[3], "Tran Thi Mai");
    strcpy(cmnd[3], "27810219");
    strcpy(ngaySinh[3], "30/12/2001");
    strcpy(gioiTinh[3], "Nu");
    strcpy(email[3], "27810219@student.hcmus.edu.vn");
    strcpy(diaChi[3], "45 Nguyen Trai");
    strcpy(ngayLapThe[3], "27/04/2025");
    strcpy(ngayHetHan[3], "27/04/2029");
    soLuongDocGia++;
    demMaDocGia++;

    // Độc giả 5
    strcpy(maDocGia[4], "DG005");
    strcpy(hoVaTen[4], "Pham Van Duc");
    strcpy(cmnd[4], "28810220");
    strcpy(ngaySinh[4], "05/03/2000");
    strcpy(gioiTinh[4], "Nam");
    strcpy(email[4], "28810220@student.hcmus.edu.vn");
    strcpy(diaChi[4], "67 Le Duan");
    strcpy(ngayLapThe[4], "28/04/2025");
    strcpy(ngayHetHan[4], "28/04/2029");
    soLuongDocGia++;
    demMaDocGia++;
}
