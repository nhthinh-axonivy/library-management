//
// Created by nht82 on 4/26/2025.
//
#include "sach.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ISBN[MAX_SACH][MAX_STRING];
char tenSach[MAX_SACH][MAX_STRING];
char tacGia[MAX_SACH][MAX_STRING];
char nhaXuatBan[MAX_SACH][MAX_STRING];
int namXuatBan[MAX_SACH];
char theLoai[MAX_SACH][MAX_STRING];
int giaSach[MAX_SACH];
int soLuongSach = 0;

void menuSach(void) {
    int chon;
    char input[MAX_STRING];
    do {
        printf("\n===== QUAN LY SACH =====\n");
        printf("1. Hien thi danh sach\n");
        printf("2. Them sach\n");
        printf("3. Cap nhat theo ISBN\n");
        printf("4. Xoa sach theo ISBN\n");
        printf("5. Tim kiem theo ISBN\n");
        printf("6. Tim kiem theo ten\n");
        printf("0. Quay lai\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                hienThiDanhSachSach();
                break;
            case 2:
                themSach();
                break;
            case 3:
                printf("Nhap ISBN sach can cap nhat: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                capNhatSachTheoISBN(input);
                break;
            case 4:
                printf("Nhap ISBN sach can xoa: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                xoaSachTheoISBN(input);
                break;
            case 5:
                printf("Nhap ISBN sach can tim: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                timSachTheoISBN(input);
                break;
            case 6:
                printf("Nhap ten sach can tim: ");
                fgets(input, MAX_STRING, stdin);
                input[strcspn(input, "\n")] = '\0';
                timSachTheoTen(input);
                break;
        }
    } while (chon != 0);
}

void hienThiDanhSachSach() {
    printf("=== DANH SACH SACH ===\n");
    for (int i = 0; i < soLuongSach; i++) {
        printf("Sach %d:\n", i + 1);
        printf("  ISBN          : %s\n", ISBN[i]);
        printf("  Ten sach      : %s\n", tenSach[i]);
        printf("  Tac gia       : %s\n", tacGia[i]);
        printf("  Nha xuat ban  : %s\n", nhaXuatBan[i]);
        printf("  Nam xuat ban  : %d\n", namXuatBan[i]);
        printf("  The loai      : %s\n", theLoai[i]);
        printf("  Gia           : %d\n", giaSach[i]);
        printf("----------------------------------------\n");
    }
    printf("========================================\n");
    ketThucChucNang();
}

//Thêm sách
void themSach() {
    char input[MAX_STRING];
    char *endptr;

    if (soLuongSach >= MAX_SACH) {
        printf("Danh sach sach da day, vui long xoa bot sach!\n");
        ketThucChucNang();
    }

    // Tạo ISBN tự động
    sprintf(ISBN[soLuongSach], "ISBN%04d", soLuongSach + 1);
    printf("Ma ISBN duoc tao tu dong: %s\n", ISBN[soLuongSach]);

    printf("Nhap ten sach: ");
    fgets(tenSach[soLuongSach], MAX_STRING, stdin);
    tenSach[soLuongSach][strcspn(tenSach[soLuongSach], "\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(tacGia[soLuongSach], MAX_STRING, stdin);
    tacGia[soLuongSach][strcspn(tacGia[soLuongSach], "\n")] = '\0';

    printf("Nhap nha xuat ban: ");
    fgets(nhaXuatBan[soLuongSach], MAX_STRING, stdin);
    nhaXuatBan[soLuongSach][strcspn(nhaXuatBan[soLuongSach], "\n")] = '\0';

    printf("Nhap nam xuat ban: ");
    fgets(input, MAX_STRING, stdin);
    input[strcspn(input, "\n")] = '\0';
    long namXB = strtol(input, &endptr, 10);
    if (*endptr == '\0') {
        namXuatBan[soLuongSach] = (int) namXB;
    } else {
        printf("Gia tri khong hop le. Nam xuat ban mac dinh la 0.\n");
        namXuatBan[soLuongSach] = 0;
    }

    printf("Nhap the loai: ");
    fgets(theLoai[soLuongSach], MAX_STRING, stdin);
    theLoai[soLuongSach][strcspn(theLoai[soLuongSach], "\n")] = '\0';

    printf("Nhap gia sach: ");
    fgets(input, MAX_STRING, stdin);
    input[strcspn(input, "\n")] = '\0';
    long gia = strtol(input, &endptr, 10);
    if (*endptr == '\0') {
        giaSach[soLuongSach] = (int) gia;
    } else {
        printf("Gia tri khong hop le. Gia sach mac dinh la 0.\n");
        giaSach[soLuongSach] = 0;
    }

    soLuongSach++;
    ketThucChucNang();
}


//Xóa sách theo ISBN
void xoaSachTheoISBN(const char *isbn) {
    int found = 0;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            found = 1;
            printf("Tim thay sach: %s\n", tenSach[i]);
            printf("Nhap 'Y' de xoa: ");

            char confirm = getchar();
            if (confirm == 'Y' || confirm == 'y') {
                for (int j = i; j < soLuongSach - 1; j++) {
                    strcpy(ISBN[j], ISBN[j + 1]);
                    strcpy(tenSach[j], tenSach[j + 1]);
                    strcpy(tacGia[j], tacGia[j + 1]);
                    strcpy(nhaXuatBan[j], nhaXuatBan[j + 1]);
                    namXuatBan[j] = namXuatBan[j + 1];
                    strcpy(theLoai[j], theLoai[j + 1]);
                    giaSach[j] = giaSach[j + 1];
                }
                soLuongSach--;
                printf("Sach da doc xoa thanh cong!\n");
            } else {
                printf("Huy xoa doc gia.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
    }
    ketThucChucNang();
}

//Cập nhập sách theo ISBN
void capNhatSachTheoISBN(const char *ma) {
    char input[MAX_STRING];
    char *endptr;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], ma) == 0) {
            printf("Tim thay sach %d:\n", i + 1);

            printf("  Ten sach       : %s\n", tenSach[i]);
            printf("Cap nhat ten sach (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(tenSach[i], input);

            printf("  Tac gia        : %s\n", tacGia[i]);
            printf("Cap nhat tac gia (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(tacGia[i], input);

            printf("  Nha xuat ban   : %s\n", nhaXuatBan[i]);
            printf("Cap nhat NXB (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(nhaXuatBan[i], input);

            printf("  Nam xuat ban   : %d\n", namXuatBan[i]);
            printf("Cap nhat nam XB (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) {
                const long value = strtol(input, &endptr, 10);
                if (*endptr == '\0') namXuatBan[i] = (int) value;
            }

            printf("  The loai       : %s\n", theLoai[i]);
            printf("Cap nhat the loai (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) strcpy(theLoai[i], input);

            printf("  Gia sach       : %d\n", giaSach[i]);
            printf("Cap nhat gia sach (Enter de giu nguyen): ");
            fgets(input, MAX_STRING, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strlen(input) > 0) {
                const long value = strtol(input, &endptr, 10);
                if (*endptr == '\0') giaSach[i] = (int) value;
            }

            printf("Cap nhat sach thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sach voi ISBN: %s\n", ma);
    ketThucChucNang();
}

void timSachTheoISBN(const char *isbn) {
    int found = 0;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(isbn, ISBN[i]) == 0) {
            // Tìm thấy thì in thông tin độc giả
            printf("Tim thay sach:\n");
            printf("Sach %d:\n", i + 1);
            printf("  ISBN          : %s\n", ISBN[i]);
            printf("  Ten sach      : %s\n", tenSach[i]);
            printf("  Tac gia       : %s\n", tacGia[i]);
            printf("  Nha xuat ban  : %s\n", nhaXuatBan[i]);
            printf("  Nam xuat ban  : %d\n", namXuatBan[i]);
            printf("  The loai      : %s\n", theLoai[i]);
            printf("  Gia           : %d\n", giaSach[i]);
            printf("----------------------------------------\n");
            found = 1;
            break;
        }
    }

    // Nếu không tìm thấy, thông báo
    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
        printf("----------------------------------------\n");
    }
    ketThucChucNang();
}

//Tìm kiếm sách theo tên
void timSachTheoTen(const char *ten) {
    int found = 0;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ten, tenSach[i]) == 0) {
            // Tìm thấy thì in thông tin độc giả
            printf("Tim thay sach:\n");
            printf("Sach %d:\n", i + 1);
            printf("  ISBN          : %s\n", ISBN[i]);
            printf("  Ten sach      : %s\n", tenSach[i]);
            printf("  Tac gia       : %s\n", tacGia[i]);
            printf("  Nha xuat ban  : %s\n", nhaXuatBan[i]);
            printf("  Nam xuat ban  : %d\n", namXuatBan[i]);
            printf("  The loai      : %s\n", theLoai[i]);
            printf("  Gia           : %d\n", giaSach[i]);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    // Nếu không tìm thấy, thông báo
    if (!found) {
        printf("Khong tim thay sach voi Ten: %s\n", ten);
        printf("----------------------------------------\n");
    }
    ketThucChucNang();
}

void khoiTaoSachMacDinh() {
    strcpy(ISBN[soLuongSach], "ISBN0001");
    strcpy(tenSach[soLuongSach], "Lap trinh C co ban");
    strcpy(tacGia[soLuongSach], "Nguyen Van A");
    strcpy(nhaXuatBan[soLuongSach], "NXB Giao Duc");
    namXuatBan[soLuongSach] = 2020;
    strcpy(theLoai[soLuongSach], "Giao trinh");
    giaSach[soLuongSach] = 85000;
    soLuongSach++;

    strcpy(ISBN[soLuongSach], "ISBN0002");
    strcpy(tenSach[soLuongSach], "Cau truc du lieu");
    strcpy(tacGia[soLuongSach], "Tran Thi B");
    strcpy(nhaXuatBan[soLuongSach], "NXB Khoa Hoc");
    namXuatBan[soLuongSach] = 2021;
    strcpy(theLoai[soLuongSach], "Hoc thuat");
    giaSach[soLuongSach] = 99000;
    soLuongSach++;

    strcpy(ISBN[soLuongSach], "ISBN0003");
    strcpy(tenSach[soLuongSach], "Thuat toan va ung dung");
    strcpy(tacGia[soLuongSach], "Le Van C");
    strcpy(nhaXuatBan[soLuongSach], "NXB Tre");
    namXuatBan[soLuongSach] = 2019;
    strcpy(theLoai[soLuongSach], "Tham khao");
    giaSach[soLuongSach] = 110000;
    soLuongSach++;
}
