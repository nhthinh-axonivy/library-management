//
// Created by nht82 on 4/26/2025.
//
#include "sach.h"

#include <ctype.h>
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
int demMaSach = 0;

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
                scanf("%s", input);
                capNhatSachTheoISBN(input);
                break;
            case 4:
                printf("Nhap ISBN sach can xoa: ");
                scanf("%s", input);
                xoaSachTheoISBN(input);
                break;
            case 5:
                printf("Nhap ISBN sach can tim: ");
                scanf("%s", input);
                timSachTheoISBN(input);
                break;
            case 6:
                printf("Nhap ten sach can tim: ");
                scanf("%s", input);
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

void themSach() {
    if (soLuongSach >= MAX_SACH) {
        printf("Danh sach sach da day, vui long xoa bot sach!\n");
        ketThucChucNang();
    }

    sprintf(ISBN[soLuongSach], "ISBN%03d", demMaSach + 1);
    printf("Ma ISBN duoc tao tu dong: %s\n", ISBN[soLuongSach]);

    getchar();
    printf("Nhap ten sach: ");
    scanf("%[^\n]s", tenSach[soLuongSach]);

    getchar();
    printf("Nhap ten tac gia: ");
    scanf("%[^\n]s", tacGia[soLuongSach]);

    getchar();
    printf("Nhap nha xuat ban: ");
    scanf("%[^\n]s", nhaXuatBan[soLuongSach]);

    printf("Nhap nam xuat ban: ");
    scanf("%d", &namXuatBan[soLuongSach]);

    getchar();
    printf("Nhap the loai: ");
    scanf("%[^\n]s", theLoai[soLuongSach]);

    printf("Nhap gia sach: ");
    scanf("%d", &giaSach[soLuongSach]);

    soLuongSach++;
    demMaSach++;
    ketThucChucNang();
}

void xoaSachTheoISBN(const char *isbn) {
    int found = 0;
    char confirm;

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            found = 1;
            printf("Tim thay sach: %s\n", tenSach[i]);
            printf("Nhap 'Y' de xoa: ");
            scanf(" %c", &confirm);

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
                printf("Sach da xoa thanh cong!\n");
            } else {
                printf("Huy xoa sach.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
    }
    ketThucChucNang();
}

void capNhatSachTheoISBN(const char *ma) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], ma) == 0) {
            printf("Tim thay sach %d:\n", i + 1);

            getchar();
            printf("Ten sach hien tai: %s\n", tenSach[i]);
            printf("Cap nhat ten sach (Enter de bo qua): ");
            scanf("%[^\n]s", tenSach[i]);

            getchar();
            printf("Tac gia hien tai: %s\n", tacGia[i]);
            printf("Cap nhat tac gia (Enter de bo qua): ");
            scanf("%[^\n]s", tacGia[i]);

            getchar();
            printf("NXB hien tai: %s\n", nhaXuatBan[i]);
            printf("Cap nhat NXB (Enter de bo qua): ");
            scanf("%[^\n]s", nhaXuatBan[i]);

            printf("Nam XB hien tai: %d\n", namXuatBan[i]);
            printf("Cap nhat nam XB (0 de bo qua): ");
            int namMoi;
            scanf("%d", &namMoi);
            if (namMoi != 0) {
                namXuatBan[i] = namMoi;
            }

            getchar();
            printf("The loai hien tai: %s\n", theLoai[i]);
            printf("Cap nhat the loai (Enter de bo qua): ");
            scanf("%[^\n]s", theLoai[i]);

            printf("Gia hien tai: %d\n", giaSach[i]);
            printf("Cap nhat gia (0 de bo qua): ");
            int giaMoi;
            scanf("%d", &giaMoi);
            if (giaMoi != 0) {
                giaSach[i] = giaMoi;
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
        if (strcmp(ISBN[i], isbn) == 0) {
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

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
        printf("----------------------------------------\n");
    }
    ketThucChucNang();
}

void timSachTheoTen(const char *ten) {
    int found = 0;
    char tenCanTimLowercase[MAX_STRING];
    strcpy(tenCanTimLowercase, ten);
    for (char *p = tenCanTimLowercase; *p; ++p) *p = tolower(*p);

    for (int i = 0; i < soLuongSach; i++) {
        char tenSachLowercase[MAX_STRING];
        strcpy(tenSachLowercase, tenSach[i]);
        for (char *q = tenSachLowercase; *q; ++q) *q = tolower(*q);

        if (strstr(tenSachLowercase, tenCanTimLowercase) != NULL) {
            if (!found) {
                printf("=== Ket qua tim kiem ===\n");
            }
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

    if (!found) {
        printf("Khong tim thay sach voi Ten: %s\n", ten);
        printf("----------------------------------------\n");
    }
    ketThucChucNang();
}

int kiemTraSachTonTaiTheoISBN(const char *isbn) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) return 1;
    }
    return 0;
}

void thongKeSoLuongSach() {
    printf("Tong so luong sach: %d\n", soLuongSach);
    ketThucChucNang();
}

void thongKeSoLuongSachTheoTheLoai() {
    char theLoaiDuyNhat[MAX_SACH][MAX_STRING];
    int soLuongTheLoaiDuyNhat = 0;

    for (int i = 0; i < soLuongSach; i++) {
        int theLoaiMoi = 1;

        for (int j = 0; j < soLuongTheLoaiDuyNhat; j++) {
            if (strcmp(theLoai[i], theLoaiDuyNhat[j]) == 0) {
                theLoaiMoi = 0;
                break;
            }
        }

        if (theLoaiMoi) {
            strcpy(theLoaiDuyNhat[soLuongTheLoaiDuyNhat], theLoai[i]);
            soLuongTheLoaiDuyNhat++;
        }
    }

    for (int i = 0; i < soLuongTheLoaiDuyNhat; i++) {
        int dem = 0;
        for (int j = 0; j < soLuongSach; j++) {
            if (strcmp(theLoai[j], theLoaiDuyNhat[i]) == 0) {
                dem++;
            }
        }
        printf("The loai %s: %d sach\n", theLoaiDuyNhat[i], dem);
    }
    ketThucChucNang();
}

void khoiTaoSach() {
    strcpy(ISBN[0], "ISBN001");
    strcpy(tenSach[0], "Lap trinh C co ban");
    strcpy(tacGia[0], "Nguyen Van A");
    strcpy(nhaXuatBan[0], "NXB Giao Duc");
    namXuatBan[0] = 2020;
    strcpy(theLoai[0], "Giao trinh");
    giaSach[0] = 85000;
    soLuongSach++;

    strcpy(ISBN[1], "ISBN002");
    strcpy(tenSach[1], "Cau truc du lieu va giai thuat");
    strcpy(tacGia[1], "Tran Thi B");
    strcpy(nhaXuatBan[1], "NXB Khoa Hoc");
    namXuatBan[1] = 2021;
    strcpy(theLoai[1], "Giao trinh");
    giaSach[1] = 99000;
    soLuongSach++;

    strcpy(ISBN[2], "ISBN003");
    strcpy(tenSach[2], "Lap trinh huong doi tuong");
    strcpy(tacGia[2], "Le Van C");
    strcpy(nhaXuatBan[2], "NXB Tre");
    namXuatBan[2] = 2019;
    strcpy(theLoai[2], "Giao trinh");
    giaSach[2] = 110000;
    soLuongSach++;

    strcpy(ISBN[3], "ISBN004");
    strcpy(tenSach[3], "The God Father");
    strcpy(tacGia[3], "Mario Puzo");
    strcpy(nhaXuatBan[3], "NXB Van Hoc");
    namXuatBan[3] = 2018;
    strcpy(theLoai[3], "Tieu thuyet");
    giaSach[3] = 150000;
    soLuongSach++;

    strcpy(ISBN[4], "ISBN005");
    strcpy(tenSach[4], "Sherlock Holmes");
    strcpy(tacGia[4], "Arthur Conan Doyle");
    strcpy(nhaXuatBan[4], "NXB Kim Dong");
    namXuatBan[4] = 2019;
    strcpy(theLoai[4], "Trinh tham");
    giaSach[4] = 120000;
    soLuongSach++;

    strcpy(ISBN[5], "ISBN006");
    strcpy(tenSach[5], "Co so du lieu");
    strcpy(tacGia[5], "Pham Van D");
    strcpy(nhaXuatBan[5], "NXB Thong Tin");
    namXuatBan[5] = 2022;
    strcpy(theLoai[5], "Giao trinh");
    giaSach[5] = 95000;
    soLuongSach++;

    strcpy(ISBN[6], "ISBN007");
    strcpy(tenSach[6], "Mang may tinh");
    strcpy(tacGia[6], "Tran Van E");
    strcpy(nhaXuatBan[6], "NXB Bachkhoa");
    namXuatBan[6] = 2021;
    strcpy(theLoai[6], "Giao trinh");
    giaSach[6] = 88000;
    soLuongSach++;

    strcpy(ISBN[7], "ISBN008");
    strcpy(tenSach[7], "Dac Nhan Tam");
    strcpy(tacGia[7], "Dale Carnegie");
    strcpy(nhaXuatBan[7], "NXB Tong Hop");
    namXuatBan[7] = 2020;
    strcpy(theLoai[7], "Ky nang song");
    giaSach[7] = 85000;
    soLuongSach++;

    strcpy(ISBN[8], "ISBN009");
    strcpy(tenSach[8], "Toi tu hoc");
    strcpy(tacGia[8], "Le Thanh F");
    strcpy(nhaXuatBan[8], "NXB Tri Thuc");
    namXuatBan[8] = 2023;
    strcpy(theLoai[8], "Ky nang song");
    giaSach[8] = 75000;
    soLuongSach++;

    strcpy(ISBN[9], "ISBN010");
    strcpy(tenSach[9], "Harry Potter");
    strcpy(tacGia[9], "J.K. Rowling");
    strcpy(nhaXuatBan[9], "NXB Tre");
    namXuatBan[9] = 2017;
    strcpy(theLoai[9], "Tieu thuyet");
    giaSach[9] = 200000;
    soLuongSach++;

    demMaSach = 10;
}
