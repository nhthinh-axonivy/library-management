#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utils.h"

#include <stdio.h>
#include <time.h>

// Lấy ngày hiện tại, định dạng dd/mm/yyyy
void layNgayHienTai(char *buffer, int maxLen) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int day = t->tm_mday;
    int month = t->tm_mon + 1;  // tm_mon bắt đầu từ 0
    int year = t->tm_year + 1900; // tm_year là số năm từ 1900

    snprintf(buffer, maxLen, "%02d/%02d/%04d", day, month, year);
}

// Cộng 48 tháng vào ngày lập => ra ngày hết hạn
void tinhNgayHetHan48Thang(const char *ngayLap, char *ngayHetHan, int maxLen) {
    int day, month, year;
    sscanf(ngayLap, "%d/%d/%d", &day, &month, &year);

    int totalMonths = month + 48;
    year += (totalMonths - 1) / 12;
    month = (totalMonths - 1) % 12 + 1;

    snprintf(ngayHetHan, maxLen, "%02d/%02d/%04d", day, month, year);
}

void ketThucChucNang() {
    printf("Nhan Enter de tiep tuc...");
    getchar();
}
