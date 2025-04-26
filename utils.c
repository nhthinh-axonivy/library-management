#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"

// Kiểm tra năm nhuận
int laNamNhuan(int nam) {
    return (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0));
}

int ngayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Nếu tháng 2 và năm nhuận, tháng 2 có 29 ngày
    if (thang == 2 && laNamNhuan(nam)) {
        return 29;
    }

    return ngayTrongThang[thang - 1];
}

// Hàm tính số ngày trong năm tính từ ngày 1/1 đến ngày cụ thể
int tinhNgayTrongNam(int ngay, int thang, int nam) {
    int tongNgay = 0;

    for (int i = 1; i < thang; i++) {
        tongNgay += ngayTrongThang(i, nam);
    }

    // Cộng thêm số ngày của tháng hiện tại
    tongNgay += ngay;

    // Xử lý năm nhuận
    for (int i = 0; i < nam; i++) {
        if (laNamNhuan(i)) {
            tongNgay++; // Mỗi năm nhuận có thêm 1 ngày
        }
    }

    return tongNgay;
}

// Lấy ngày hiện tại, định dạng dd/mm/yyyy
void layNgayHienTai(char *buffer, int maxLen) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int ngay = t->tm_mday;
    int thang = t->tm_mon + 1;  // tm_mon bắt đầu từ 0
    int nam = t->tm_year + 1900; // tm_year là số năm từ 1900

    snprintf(buffer, maxLen, "%02d/%02d/%04d", ngay, thang, nam);
}

// Cộng 48 tháng vào ngày lập => ra ngày hết hạn
void tinhNgayHetHan48Thang(const char *ngayLap, char *ngayHetHan, int maxLen) {
    int ngay, thang, nam;
    sscanf(ngayLap, "%d/%d/%d", &ngay, &thang, &nam);

    int totalMonths = thang + 48;
    nam += (totalMonths - 1) / 12;  // Cộng số năm cho 48 tháng
    thang = (totalMonths - 1) % 12 + 1;  // Cập nhật tháng

    snprintf(ngayHetHan, maxLen, "%02d/%02d/%04d", ngay, thang, nam);
}

// Cộng thêm 7 ngày vào ngày mượn
void tinhNgayTraDuKien7Ngay(const char *ngayMuon, char *ngayTraDuKien, int maxLen) {
    int ngay, thang, nam;
    sscanf(ngayMuon, "%d/%d/%d", &ngay, &thang, &nam);

    // Số ngày mỗi tháng (không xét năm nhuận vì đơn giản)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    ngay += 7; // Cộng thêm 7 ngày
    while (ngay > daysInMonth[thang - 1]) {  // Nếu ngày vượt qua số ngày trong tháng
        ngay -= daysInMonth[thang - 1];
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    snprintf(ngayTraDuKien, maxLen, "%02d/%02d/%04d", ngay, thang, nam);
}

// Tính số ngày chênh lệch giữa hai ngày
int tinhSoNgayGiua2Ngay(const char *ngay1, const char *ngay2) {
    int d1, m1, y1, d2, m2, y2;
    sscanf(ngay1, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(ngay2, "%d/%d/%d", &d2, &m2, &y2);

    // Tính số ngày tính từ năm 0 đến ngày hiện tại
    int total1 = tinhNgayTrongNam(d1, m1, y1);
    int total2 = tinhNgayTrongNam(d2, m2, y2);

    return total2 - total1;  // Chênh lệch giữa hai ngày
}

// Dừng lại để người dùng nhấn Enter
void ketThucChucNang() {
    printf("Nhan Enter de tiep tuc...");
    getchar();
}
