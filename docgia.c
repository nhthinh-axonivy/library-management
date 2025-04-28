//
// Created by nhthinh on 25/04/2025.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "docgia.h"
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



// Chức năng hiển thị thông tin độc giả
void hienThiChiTietDocGia(int index) {
    if (index < 0 || index >= soLuongDocGia) {
        printf("<!> Chi so doc gia khong hop le.\n");
        return;
    }
    printf("  Ma doc gia     : %s\n", maDocGia[index]);
    printf("  Ho va ten      : %s\n", hoVaTen[index]);
    printf("  CMND           : %s\n", cmnd[index]);
    printf("  Ngay sinh      : %s\n", ngaySinh[index]);
    printf("  Gioi tinh      : %s\n", gioiTinh[index]);
    printf("  Email          : %s\n", email[index]);
    printf("  Dia chi        : %s\n", diaChi[index]);
    printf("  Ngay lap the   : %s\n", ngayLapThe[index]);
    printf("  Ngay het han   : %s\n", ngayHetHan[index]);
    printf("----------------------------------------\n");
}

// Menu quản lý độc giả
void menuDocGia() {
    int chon = -1;
    char inputBuffer[MAX_STRING];
    do {
        printf("\n===== QUAN LY DOC GIA =====\n");
        printf("1. Hien thi danh sach doc gia\n");
        printf("2. Them doc gia\n");
        printf("3. Cap nhat theo ma\n");
        printf("4. Xoa doc gia theo ma\n");
        printf("5. Tim kiem theo CMND\n");
        printf("6. Tim kiem theo ho va ten\n");
        printf("0. Quay lai\n");
        printf("---------------------------\n");
        printf("Chon chuc nang: ");

        readLine(inputBuffer, sizeof(inputBuffer));
        chon = atoi(inputBuffer);

        switch (chon) {
            case 1:
                hienThiDanhSachDocGia();
                break;
            case 2:
                themDocGia();
                break;
            case 3: {
                char maCanCapNhat[MAX_STRING];
                printf("Nhap ma doc gia can cap nhat: ");
                readLine(maCanCapNhat, sizeof(maCanCapNhat));
                capNhatDocGiaTheoMa(maCanCapNhat);
                break;
            }
            case 4: {
                char maCanXoa[MAX_STRING];
                printf("Nhap ma doc gia can xoa: ");
                readLine(maCanXoa, sizeof(maCanXoa));
                xoaDocGiaTheoMa(maCanXoa);
                break;
            }
            case 5: {
                char cmndCanTim[MAX_STRING];
                printf("Nhap CMND doc gia can tim: ");
                readLine(cmndCanTim, sizeof(cmndCanTim));
                timKiemDocGiaTheoCMND(cmndCanTim);
                break;
            }
            case 6: {
                char tenCanTim[MAX_STRING];
                printf("Nhap ho ten doc gia can tim: ");
                readLine(tenCanTim, sizeof(tenCanTim)); // readLine handles spaces
                timKiemDocGiaTheoTen(tenCanTim);
                break;
            }
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
        if (chon != 0) {
            ketThucChucNang();
        }
    } while (chon != 0);
}

void themDocGia() {
    if (soLuongDocGia >= MAX_DOCGIA) {
        printf("Danh sach doc gia da day, khong the them moi!\n");
        return;
    }

    int index = soLuongDocGia;

    // Tự động gen ID độc giả
    sprintf(maDocGia[index], "DG%03d", demMaDocGia + 1);
    printf("Ma doc gia duoc tao tu dong: %s\n", maDocGia[index]);

    // Tự động thêm ngày lập và ngày hết hạn dựa theo ngày hiện tại
    char ngayLap[11];
    layNgayHienTai(ngayLap, sizeof(ngayLap));
    strcpy(ngayLapThe[index], ngayLap);
    char hetHan[11];
    tinhNgayHetHan48Thang(ngayLap, hetHan, sizeof(hetHan));
    strcpy(ngayHetHan[index], hetHan);
    printf("Ngay lap the: %s\n", ngayLapThe[index]);
    printf("Ngay het han: %s\n", ngayHetHan[index]);

    //Họ Tên
    printf("Nhap ho va ten: ");
    readLine(hoVaTen[index], sizeof(hoVaTen[index]));

    // Kiểm tra input và trên hệ thống để đảm bảo cmnd không trùng nhau
    do {
        printf("Nhap CMND: ");
        readLine(cmnd[index], sizeof(cmnd[index]));
        if (kiemTraDocGiaTonTaiTheoCMND(cmnd[index])) {
             printf("CMND nay da ton tai. Vui long nhap lai!\n");
        } else {
            break;
        }
    } while (1);


    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    readLine(ngaySinh[index], sizeof(ngaySinh[index]));

do {
        printf("Nhap gioi tinh (Nam/Nu): ");
        readLine(gioiTinh[index], sizeof(gioiTinh[index]));
        char lowerGioiTinh[MAX_STRING];
        strcpy(lowerGioiTinh, gioiTinh[index]);
        for (char *p = lowerGioiTinh; *p; ++p) *p = tolower(*p);
        if (strcmp(lowerGioiTinh, "nam") == 0 || strcmp(lowerGioiTinh, "nu") == 0) {
            gioiTinh[index][0] = toupper(gioiTinh[index][0]); // Standardize first letter to uppercase
            break;
        }
        printf("Gioi tinh khong hop le. Vui long nhap 'Nam' hoac 'Nu'.\n");
    } while (1);

    printf("Nhap email: ");
    readLine(email[index], sizeof(email[index]));

    printf("Nhap dia chi: ");
    readLine(diaChi[index], sizeof(diaChi[index]));

    soLuongDocGia++;
    demMaDocGia++;
    printf("Them doc gia thanh cong!\n");
}


void hienThiDanhSachDocGia() {
    if (soLuongDocGia == 0) {
        printf("Danh sach doc gia rong.\n");
        return;
    }
    printf("======= DANH SACH DOC GIA (%d doc gia) =======\n", soLuongDocGia);
    for (int i = 0; i < soLuongDocGia; i++) {
        printf("--- Doc gia %d ---\n", i + 1);
        hienThiChiTietDocGia(i);
    }
    printf("===============================================\n");
}

// Chức năng tìm kiếm độc giả theo cmnd
void timKiemDocGiaTheoCMND(const char *cmndCanTim) {
    int found = 0;
    printf("=== Tim kiem doc gia theo CMND: %s ===\n", cmndCanTim);
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(cmnd[i], cmndCanTim) == 0) {
            printf("Tim thay doc gia:\n");
            hienThiChiTietDocGia(i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay doc gia voi CMND: %s\n", cmndCanTim);
    }
    printf("=====================================\n");
}

// Chức năng tìm kiếm độc giả theo tên
void timKiemDocGiaTheoTen(const char *tenCanTim) {
    int found = 0;
    char tenCanTimLower[MAX_STRING];
    char tenDocGiaLower[MAX_STRING];

    // Convert search term to lowercase
    strcpy(tenCanTimLower, tenCanTim);
    for (char *p = tenCanTimLower; *p; ++p) *p = tolower(*p);

    printf("=== Tim kiem doc gia theo Ten: %s ===\n", tenCanTim);
    for (int i = 0; i < soLuongDocGia; i++) {
        strcpy(tenDocGiaLower, hoVaTen[i]);
        for (char *q = tenDocGiaLower; *q; ++q) *q = tolower(*q);

        if (strstr(tenDocGiaLower, tenCanTimLower) != NULL) {
            if (!found) { // Print header only once
                 printf("Ket qua tim thay:\n");
            }
            hienThiChiTietDocGia(i);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay doc gia nao co ten: %s\n", tenCanTim);
    }
    printf("=====================================\n");
}

// Xóa độc giả theo mã độc giả
void xoaDocGiaTheoMa(const char *maCanXoa) {
    int index = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], maCanXoa) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Tim thay doc gia can xoa:\n");
        hienThiChiTietDocGia(index);

        char confirmBuffer[10];
        printf("Nhap 'Y' de xac nhan xoa: ");
        readLine(confirmBuffer, sizeof(confirmBuffer));

        if (strcmp(confirmBuffer, "Y") == 0 || strcmp(confirmBuffer, "y") == 0) {
            // Shift elements down to fill the gap
            for (int j = index; j < soLuongDocGia - 1; j++) {
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
            soLuongDocGia--; // Decrease the count
            printf("Doc gia '%s' da duoc xoa thanh cong!\n", maCanXoa);
        } else {
            printf("Huy xoa doc gia.\n");
        }
    } else {
        printf("Khong tim thay doc gia voi ma: %s\n", maCanXoa);
    }
}

// Cập nhập thông tin độc giả theo mã độc giả
void capNhatDocGiaTheoMa(const char *maCanCapNhat) {
    int index = -1;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], maCanCapNhat) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Tim thay doc gia can cap nhat (Ma: %s). Nhap thong tin moi hoac Enter de giu nguyen.\n", maCanCapNhat);
        hienThiChiTietDocGia(index); // Show current details

        char inputBuffer[MAX_STRING];

        printf("Cap nhat Ho va ten [%s]: ", hoVaTen[index]);
        readLine(inputBuffer, sizeof(inputBuffer));
        if (strlen(inputBuffer) > 0) strcpy(hoVaTen[index], inputBuffer);

        printf("Cap nhat CMND [%s]: ", cmnd[index]);
        readLine(inputBuffer, sizeof(inputBuffer));
        if (strlen(inputBuffer) > 0) {
            // check xem cmnd mới có trùng với cmnd đã có trong hệ thống
            int cmndExists = 0;
            for(int k=0; k < soLuongDocGia; ++k) {
                if (k != index && strcmp(cmnd[k], inputBuffer) == 0) {
                    cmndExists = 1;
                    break;
                }
            }
            if (!cmndExists) {
                strcpy(cmnd[index], inputBuffer);
            } else {
                printf("CMND '%s' da ton tai. Khong cap nhat CMND.\n", inputBuffer);
            }
        }


        printf("Cap nhat Ngay sinh [%s]: ", ngaySinh[index]);
        readLine(inputBuffer, sizeof(inputBuffer));
        if (strlen(inputBuffer) > 0) strcpy(ngaySinh[index], inputBuffer);

        do {
            printf("Cap nhat Gioi tinh [%s]: ", gioiTinh[index]);
            readLine(gioiTinh[index], sizeof(gioiTinh[index]));
            char lowerGioiTinh[MAX_STRING];
            strcpy(lowerGioiTinh, gioiTinh[index]);
            for (char *p = lowerGioiTinh; *p; ++p) *p = tolower(*p);
            if (strcmp(lowerGioiTinh, "nam") == 0 || strcmp(lowerGioiTinh, "nu") == 0) {
                gioiTinh[index][0] = toupper(gioiTinh[index][0]);
                break;
            }
            printf("Gioi tinh khong hop le. Vui long nhap 'Nam' hoac 'Nu'.\n");
        } while (1);

        printf("Cap nhat Email [%s]: ", email[index]);
        readLine(inputBuffer, sizeof(inputBuffer));
        if (strlen(inputBuffer) > 0) strcpy(email[index], inputBuffer);

        printf("Cap nhat Dia chi [%s]: ", diaChi[index]);
        readLine(inputBuffer, sizeof(inputBuffer));
        if (strlen(inputBuffer) > 0) strcpy(diaChi[index], inputBuffer);

        printf("Cap nhat thong tin doc gia thanh cong.\n");

    } else {
        printf("Khong tim thay doc gia voi ma: %s\n", maCanCapNhat);
    }
}

//Thông kế số lượng độc giả trong hệ thống
void thongKeSoLuongDocGia() {
    printf("=== Thong ke so luong doc gia ===\n");
    printf("Tong so luong doc gia hien co: %d\n", soLuongDocGia);
    printf("=================================\n");
}

//Thống kê độc giả theo giới tính
void thongKeSoLuongDocGiaTheoGioiTinh() {
    int nam = 0, nu = 0;
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcasecmp(gioiTinh[i], "Nam") == 0) {
            nam++;
        } else if (strcasecmp(gioiTinh[i], "Nu") == 0) {
            nu++;
        }
    }
    printf("=== Thong ke doc gia theo gioi tinh ===\n");
    printf("So luong doc gia Nam: %d\n", nam);
    printf("So luong doc gia Nu : %d\n", nu);
    printf("======================================\n");
}

//kiểm tra độc giả tồn tại trong hệ thống theo mã đôộc giả
int kiemTraDocGiaTonTaiTheoMa(const char *ma) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(maDocGia[i], ma) == 0) {
            return 1;
        }
    }
    return 0;
}

//Kiểm tra độc giả tồn tại theo cmnd
int kiemTraDocGiaTonTaiTheoCMND(const char *cmndCanTim) {
    for (int i = 0; i < soLuongDocGia; i++) {
        if (strcmp(cmnd[i], cmndCanTim) == 0) {
            return 1;
        }
    }
    return 0; // Not found
}

// Khởi tạo data độc giả để test hệ thống
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

    soLuongDocGia = 5;
    demMaDocGia = 5;
    printf("Khoi tao du lieu doc gia mau thanh cong.\n");
}