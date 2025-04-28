//
// Created by nht82 on 26/04/2025.
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

//Menu quản lý sách
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
        
        readLine(input, sizeof(input));
        chon = atoi(input);

        switch (chon) {
            case 1:
                hienThiDanhSachSach();
                break;
            case 2:
                themSach();
                break;
            case 3:
                printf("Nhap ISBN sach can cap nhat: ");
                readLine(input, sizeof(input));
                capNhatSachTheoISBN(input);
                break;
            case 4:
                printf("Nhap ISBN sach can xoa: ");
                readLine(input, sizeof(input));
                xoaSachTheoISBN(input);
                break;
            case 5:
                printf("Nhap ISBN sach can tim: ");
                readLine(input, sizeof(input));
                timSachTheoISBN(input);
                break;
            case 6:
                printf("Nhap ten sach can tim: ");
                readLine(input, sizeof(input));
                timSachTheoTen(input);
                break;
            case 0:
                printf("Quay lai menu chinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
        
        if (chon != 0) {
            ketThucChucNang();
        }
    } while (chon != 0);
}

//Hieern thị thông tin sách trong hệ thống
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

// Thêm thng tin sách vào hệ thống
void themSach() {
    if (soLuongSach >= MAX_SACH) {
        printf("Danh sach sach da day, vui long xoa bot sach!\n");
        return;
    }

    char inputBuffer[MAX_STRING];

    // Tạo mã ISBN tự động
    sprintf(ISBN[soLuongSach], "ISBN%03d", demMaSach + 1);
    printf("Ma ISBN duoc tao tu dong: %s\n", ISBN[soLuongSach]);

    // Nhập tên sách với kiểm tra
    do {
        printf("Nhap ten sach: ");
        readLine(tenSach[soLuongSach], MAX_STRING);
        if (strlen(tenSach[soLuongSach]) == 0) {
            printf("Ten sach khong duoc de trong. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    // Nhập tên tác giả
    do {
        printf("Nhap ten tac gia: ");
        readLine(tacGia[soLuongSach], MAX_STRING);
        if (strlen(tacGia[soLuongSach]) == 0) {
            printf("Ten tac gia khong duoc de trong. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    // Nhập nhà xuất bản
    printf("Nhap nha xuat ban: ");
    readLine(nhaXuatBan[soLuongSach], MAX_STRING);

    // Nhập năm xuất bản
    do {
        printf("Nhap nam xuat ban: ");
        readLine(inputBuffer, sizeof(inputBuffer));
        namXuatBan[soLuongSach] = atoi(inputBuffer);
        
        // Giả sử sách hợp lệ chỉ từ năm 1900 đến năm hiện tại
        if (namXuatBan[soLuongSach] < 1900 || namXuatBan[soLuongSach] > 2025) {
            printf("Nam xuat ban khong hop le. Vui long nhap nam tu 1900 den 2025.\n");
        } else {
            break;
        }
    } while (1);

    // Nhập thể loại
    printf("Nhap the loai: ");
    readLine(theLoai[soLuongSach], MAX_STRING);

    // Nhập giá sách với kiểm tra
    do {
        printf("Nhap gia sach: ");
        readLine(inputBuffer, sizeof(inputBuffer));
        giaSach[soLuongSach] = atoi(inputBuffer);
        
        if (giaSach[soLuongSach] <= 0) {
            printf("Gia sach phai lon hon 0. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    soLuongSach++;
    demMaSach++;
    printf("Them sach thanh cong!\n");
}

//Xóa sách trong hệ thống theo ISBN
void xoaSachTheoISBN(const char *isbn) {
    int found = 0;
    char confirmBuffer[10];

    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            found = 1;
            printf("Tim thay sach: %s\n", tenSach[i]);
            printf("Nhap 'Y' de xoa: ");
            readLine(confirmBuffer, sizeof(confirmBuffer));

            if (confirmBuffer[0] == 'Y' || confirmBuffer[0] == 'y') {
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
}

//Cập nhập thông tin sách theo ISBN
void capNhatSachTheoISBN(const char *ma) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], ma) == 0) {
            printf("Tim thay sach %d:\n", i + 1);
            char inputBuffer[MAX_STRING];
            char tempBuffer[MAX_STRING];

            printf("Ten sach hien tai: %s\n", tenSach[i]);
            printf("Cap nhat ten sach (Enter de bo qua): ");
            readLine(tempBuffer, sizeof(tempBuffer));
            if (strlen(tempBuffer) > 0) {
                strcpy(tenSach[i], tempBuffer);
            }

            printf("Tac gia hien tai: %s\n", tacGia[i]);
            printf("Cap nhat tac gia (Enter de bo qua): ");
            readLine(tempBuffer, sizeof(tempBuffer));
            if (strlen(tempBuffer) > 0) {
                strcpy(tacGia[i], tempBuffer);
            }

            printf("NXB hien tai: %s\n", nhaXuatBan[i]);
            printf("Cap nhat NXB (Enter de bo qua): ");
            readLine(tempBuffer, sizeof(tempBuffer));
            if (strlen(tempBuffer) > 0) {
                strcpy(nhaXuatBan[i], tempBuffer);
            }

            printf("Nam XB hien tai: %d\n", namXuatBan[i]);
            printf("Cap nhat nam XB (0 de bo qua): ");
            readLine(inputBuffer, sizeof(inputBuffer));
            int namMoi = atoi(inputBuffer);
            if (namMoi != 0) {
                namXuatBan[i] = namMoi;
            }

            printf("The loai hien tai: %s\n", theLoai[i]);
            printf("Cap nhat the loai (Enter de bo qua): ");
            readLine(tempBuffer, sizeof(tempBuffer));
            if (strlen(tempBuffer) > 0) {
                strcpy(theLoai[i], tempBuffer);
            }

            printf("Gia hien tai: %d\n", giaSach[i]);
            printf("Cap nhat gia (0 de bo qua): ");
            readLine(inputBuffer, sizeof(inputBuffer));
            int giaMoi = atoi(inputBuffer);
            if (giaMoi != 0) {
                giaSach[i] = giaMoi;
            }

            printf("Cap nhat sach thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sach voi ISBN: %s\n", ma);
}

//Tìm sách theo mã ISBN
void timSachTheoISBN(const char *isbn) {
    if (strlen(isbn) == 0) {
        printf("ISBN tim kiem khong duoc de trong.\n");
        printf("----------------------------------------\n");
        return;
    }
    
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
            printf("  Gia           : %d VND\n", giaSach[i]);
            printf("----------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ISBN: %s\n", isbn);
        printf("----------------------------------------\n");
    }
}

//Tìm sách theo tên sách
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

//Kiểm tra sách tồn tại trong hệ thososng hay không theo mã ISBN
int kiemTraSachTonTaiTheoISBN(const char *isbn) {
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(ISBN[i], isbn) == 0) return 1;
    }
    return 0;
}

//Thng kê tổng số lượng sách trong hệ thống
void thongKeSoLuongSach() {
    printf("Tong so luong sach: %d\n", soLuongSach);
    ketThucChucNang();
}

//Thống kê số lượng sách theo loại
void thongKeSoLuongSachTheoTheLoai() {
    printf("=== THONG KE SACH THEO THE LOAI ===\n");
    
    if (soLuongSach == 0) {
        printf("Chua co sach nao trong thu vien.\n");
        return;
    }
    
    char theLoaiDuyNhat[MAX_SACH][MAX_STRING];
    int soLuongSachTheoTheLoai[MAX_SACH] = {0};
    int soLuongTheLoaiDuyNhat = 0;

    // Tìm các thể loại duy nhất và đếm số lượng sách của mỗi thể loại
    for (int i = 0; i < soLuongSach; i++) {
        int theLoaiMoi = 1;
        int theLoaiIndex = -1;

        for (int j = 0; j < soLuongTheLoaiDuyNhat; j++) {
            if (strcmp(theLoai[i], theLoaiDuyNhat[j]) == 0) {
                theLoaiMoi = 0;
                theLoaiIndex = j;
                break;
            }
        }

        if (theLoaiMoi) {
            strcpy(theLoaiDuyNhat[soLuongTheLoaiDuyNhat], theLoai[i]);
            soLuongSachTheoTheLoai[soLuongTheLoaiDuyNhat] = 1;
            soLuongTheLoaiDuyNhat++;
        } else {
            soLuongSachTheoTheLoai[theLoaiIndex]++;
        }
    }

    printf("So luong the loai sach: %d\n", soLuongTheLoaiDuyNhat);
    printf("----------------------------------------\n");
    
    for (int i = 0; i < soLuongTheLoaiDuyNhat; i++) {
        printf("The loai: %-20s | So luong: %d sach\n", theLoaiDuyNhat[i], soLuongSachTheoTheLoai[i]);
    }
    
    printf("----------------------------------------\n");
    printf("Tong so sach: %d\n", soLuongSach);
}

//Khởi tạo dữ liệu
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
