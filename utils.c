#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utils.h"

// Lấy ngày hiện tại, định dạng dd/mm/yyyy
void layNgayHienTai(char *buffer, int maxLen) {
    time_t now = time(NULL);
    long seconds_in_day = 86400;
    long days = now / seconds_in_day;

    // Ngày bắt đầu từ 01/01/1970
    int year = 1970;
    int month = 1;
    int day = 1;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (days >= 365) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (days < 366) break;
            days -= 366;
        } else {
            days -= 365;
        }
        year++;
    }

    int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (is_leap) days_in_month[1] = 29;

    for (month = 0; month < 12; month++) {
        if (days < days_in_month[month]) break;
        days -= days_in_month[month];
    }

    day = (int)days + 1;
    month += 1; // vì mảng bắt đầu từ 0

    snprintf(buffer, maxLen, "%02d/%02d/%04d", day, month, year);
}

// Cộng 48 tháng vào ngày lập => ra ngày hết hạn
void tinhNgayHetHan48Thang(const char *ngayLap, char *ngayHetHan, int maxLen) {
    int day, month, year;
    sscanf(ngayLap, "%d/%d/%d", &day, &month, &year);

    year += (month + 48 - 1) / 12;
    month = (month + 48 - 1) % 12 + 1;

    snprintf(ngayHetHan, maxLen, "%02d/%02d/%04d", day, month, year);
}

void ketThucChucNang() {
    printf("Nhan Enter de tiep tuc...");
    getchar();
}
