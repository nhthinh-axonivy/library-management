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


void menuDocGia() {
    int chon;
    char input[MAX_STRING];
    do {
        printf("\n===== QUAN LY DOC GIA =====\n");
        printf("1. Hien thi danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Cap nhat doc gia\n");
        printf("4. Xoa doc gia\n");
        printf("5. Tim kiem theo CMND\n");
        printf("6. Tim kiem theo ho ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar(); // bỏ '\n'

        switch(chon) {
            case 1:
                hienThiDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3:
                printf("Nhap ma doc gia can cap nhat: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                capNhatDocGiaTheoMa(input);
                break;
            case 4:
                printf("Nhap ma doc gia can xoa: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                xoaDocGiaTheoMa(input);
                break;
            case 5:
                printf("Nhap CMND can tim: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                timKiemDocGiaTheoCMND(input);
                break;
            case 6:
                printf("Nhap ho ten can tim: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                timKiemDocGiaTheoTen(input);
                break;
        }
    } while(chon != 0);
}

int themDocGia() {
    if (soLuongDocGia >= MAX_DOCGIA) {
        printf("Danh sach doc gia da day, vui long xoa bot doc gia!\n");
        return 0;
    }

    sprintf(maDocGia[soLuongDocGia], "DG%04d", soLuongDocGia + 1);
    printf("Ma doc gia duoc tao tu dong: %s\n", maDocGia[soLuongDocGia]);

    char ngayLap[11];
    layNgayHienTai(ngayLap, sizeof(ngayLap));
    strcpy(ngayLapThe[soLuongDocGia], ngayLap);

    char hetHan[11];
    tinhNgayHetHan48Thang(ngayLap, hetHan, sizeof(hetHan));
    strcpy(ngayHetHan[soLuongDocGia], hetHan);

    printf("Nhap ho va ten: ");
    fgets(hoVaTen[soLuongDocGia], MAX_STRING, stdin);
    hoVaTen[soLuongDocGia][strcspn(hoVaTen[soLuongDocGia], "\n")] = '\0';

    printf("Nhap CMND: ");
    fgets(cmnd[soLuongDocGia], MAX_STRING, stdin);
    cmnd[soLuongDocGia][strcspn(cmnd[soLuongDocGia], "\n")] = '\0';

    printf("Nhap ngay sinh: ");
    fgets(ngaySinh[soLuongDocGia], MAX_STRING, stdin);
    ngaySinh[soLuongDocGia][strcspn(ngaySinh[soLuongDocGia], "\n")] = '\0';

    printf("Nhap gioi tinh: ");
    fgets(gioiTinh[soLuongDocGia], MAX_STRING, stdin);
    gioiTinh[soLuongDocGia][strcspn(gioiTinh[soLuongDocGia], "\n")] = '\0';

    printf("Nhap email: ");
    fgets(email[soLuongDocGia], MAX_STRING, stdin);
    email[soLuongDocGia][strcspn(email[soLuongDocGia], "\n")] = '\0';

    printf("Nhap dia chi: ");
    fgets(diaChi[soLuongDocGia], MAX_STRING, stdin);
    diaChi[soLuongDocGia][strcspn(diaChi[soLuongDocGia], "\n")] = '\0';

    soLuongDocGia++;
    return 1;
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
        if (strcmp(cmndCanTim, cmnd[i]) == 0) {
            // Tìm thấy thì in thông tin độc giả
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

    // Nếu không tìm thấy, thông báo
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
        if (strcmp(maDocGia[i], ma) == 0) {
            found = 1;
            printf("Tim thay doc gia %d:\n", i + 1);
            printf("  Ho va ten      : %s\n", hoVaTen[i]);
            printf("Nhap 'Y' de xoa: ");

            // Đọc input và xóa ký tự thừa trong bộ đệm
            char confirm = getchar();

            if (confirm == 'Y' || confirm == 'y') {
                // Dịch mảng để xóa phần tử
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
                soLuongDocGia--; // Giảm số lượng độc giả
                printf("Doc gia da duoc xoa.\n");
            } else {
                printf("Huy xoa doc gia.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia voi ma: %s\n", ma);
    }

    printf("Nhan Enter de tiep tuc...");
    getchar(); // Để dừng và chờ người dùng nhập Enter
}


// Cập nhật thông tin độc giả theo mã
void capNhatDocGiaTheoMa(const char *ma) {
    char input[MAX_STRING];

    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], ma) == 0) {
            printf("Tim thay doc gia %d:\n", i + 1);

            printf("  Ho va ten      : %s\n", hoVaTen[i]);
            printf("Cap nhat ho va ten (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(hoVaTen[i], input);

            printf("  CMND           : %s\n", cmnd[i]);
            printf("Cap nhat CMND (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(cmnd[i], input);

            printf("  Ngay sinh      : %s\n", ngaySinh[i]);
            printf("Cap nhat ngay sinh (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(ngaySinh[i], input);

            printf("  Gioi tinh      : %s\n", gioiTinh[i]);
            printf("Cap nhat gioi tinh (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(gioiTinh[i], input);

            printf("  Email          : %s\n", email[i]);
            printf("Cap nhat email (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(email[i], input); // sửa email[soLuongDocGia] thành email[i]

            printf("  Dia chi        : %s\n", diaChi[i]);
            printf("Cap nhat dia chi (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(diaChi[i], input);

            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay ma doc gia voi ma: %s\n",ma);
    ketThucChucNang();
}

void khoiTaoDocGiaMacDinh() {
    strcpy(maDocGia[0], "DG0001");
    strcpy(hoVaTen[0], "Nguyen Hung Thinh");
    strcpy(cmnd[0], "24810216");
    strcpy(ngaySinh[0], "08/02/1999");
    strcpy(gioiTinh[0], "Nam");
    strcpy(email[0], "24810216@student.hcmus.edu.vn");
    strcpy(diaChi[0], "09 Nguyen Tu Nha");
    strcpy(ngayLapThe[0], "25/04/2025");
    strcpy(ngayHetHan[0], "25/04/2029");

    strcpy(maDocGia[1], "DG0002");
    strcpy(hoVaTen[1], "Nguyen Thanh Thanh");
    strcpy(cmnd[1], "9999999");
    strcpy(ngaySinh[1], "26/04/2025");
    strcpy(gioiTinh[1], "Nu");
    strcpy(email[1], "9999999@student.hcmus.edu.vn");
    strcpy(diaChi[1], "39B Truong Son");
    strcpy(ngayLapThe[1], "25/04/2025");
    strcpy(ngayHetHan[1], "25/04/2029");
    soLuongDocGia = 2;
}