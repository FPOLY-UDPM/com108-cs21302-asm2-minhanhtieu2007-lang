/******************************************************************************
 * Họ và tên: Tiêu Anh Minh
 * MSSV:      PS48358
 * Lớp:       CS21301
 *****************************************************************************/
// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c
// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện
// 5. Chức năng số 5: Chức năng đổi tiền
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// Hàm tìm Ước Chung Lớn Nhất
int UCLN(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// Hàm tìm Bội Số Chung Nhỏ Nhất
int BSCNN(int a, int b)
{
    return (a * b) / UCLN(a, b);
}
int sosinhvien;
int main()
{ int chonChucNang;
    do
    {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang)
        {
        case 1:
        // Gọi hàm kiểm tra số nguyên
        {
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            printf("nhap so can kiem tra: ");
            float songuyen;
            scanf("%f/n", &songuyen);
            if (songuyen == (int)songuyen)
            {
                printf("%f la so nguyen\n", songuyen);
            }
            else
            {
                printf("%f khong phai la so nguyen\n", songuyen);
            }
            break;
        }
        case 2:
        {
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            int a, b;
            printf("Nhap so thu nhat: ");
            scanf("%d", &a);
            printf("Nhap so thu hai: ");
            scanf("%d", &b);
            int ucln = UCLN(a, b);
            int bscnn = BSCNN(a, b);
            printf("UCLN = %d\n", ucln);
            printf("BSCNN = %d\n", bscnn);
            break;
        }
        case 3:
        {
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            int gioBatDau, gioKetThuc;
            int soGio;
            double tien = 0;

            printf("Nhap gio bat dau: ");
            scanf("%d", &gioBatDau);

            printf("Nhap gio ket thuc: ");
            scanf("%d", &gioKetThuc);

            // Kiểm tra giờ hợp lệ
            if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc)
            {
                printf("Gio khong hop le!\n");
                return 0;
            }

            soGio = gioKetThuc - gioBatDau;

            // Tính tiền
            if (soGio <= 3)
            {
                tien = soGio * 150000;
            }
            else
            {
                tien = 3 * 150000 + (soGio - 3) * 150000 * 0.7;
            }

            // Giảm thêm 10% nếu bắt đầu từ 14 -> 17
            if (gioBatDau >= 14 && gioBatDau <= 17)
            {
                tien = tien * 0.9;
            }

            printf("So tien can thanh toan: %.0lf VND\n", tien);

            return 0;
            break;
        }
        case 4:
        { // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            int kwh;
            double tien = 0;

            printf("Nhap so kWh su dung: ");
            scanf("%d", &kwh);

            if (kwh <= 50)
            {
                tien = kwh * 1678;
            }
            else if (kwh <= 100)
            {
                tien = 50 * 1678 +
                       (kwh - 50) * 1734;
            }
            else if (kwh <= 200)
            {
                tien = 50 * 1678 +
                       50 * 1734 +
                       (kwh - 100) * 2014;
            }
            else if (kwh <= 300)
            {
                tien = 50 * 1678 +
                       50 * 1734 +
                       100 * 2014 +
                       (kwh - 200) * 2536;
            }
            else if (kwh <= 400)
            {
                tien = 50 * 1678 +
                       50 * 1734 +
                       100 * 2014 +
                       100 * 2536 +
                       (kwh - 300) * 2834;
            }
            else
            {
                tien = 50 * 1678 +
                       50 * 1734 +
                       100 * 2014 +
                       100 * 2536 +
                       100 * 2834 +
                       (kwh - 400) * 2927;
            }

            printf("So tien phai tra: %.0lf dong\n", tien);

            return 0;
        }
        break;
        case 5:
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            {

                int tien;
                printf("nhap so tien can doi(khong tinh menh gia tram dong): ", tien);
                scanf("%d/n", &tien);
                if (tien > 1000)
                {
                    int to500 = tien / 500000;
                    tien = tien % 500000;
                    int to200 = tien / 200000;
                    tien = tien % 200000;
                    int to100 = tien / 100000;
                    tien = tien % 100000;
                    int to50 = tien / 50000;
                    tien = tien % 50000;
                    int to20 = tien / 20000;
                    tien = tien % 20000;
                    int to10 = tien / 10000;
                    tien = tien % 10000;
                    int to5 = tien / 5000;
                    tien = tien % 5000;
                    int to2 = tien / 2000;
                    tien = tien % 2000;
                    int to1 = tien / 1000;
                    tien = tien % 1000;
                    printf("To 500k: %d\n", to500);
                    printf("To 200k: %d\n", to200);
                    printf("To 100k: %d\n", to100);
                    printf("To 50k: %d\n", to50);
                    printf("To 20k: %d\n", to20);
                    printf("To 10k: %d\n", to10);
                    printf("To 5k: %d\n", to5);
                    printf("To 2k: %d\n", to2);
                    printf("To 1k: %d\n", to1);
                }
                else
                {
                    printf("nhap lai tien voi menh gia nghin dong");
                }
            }
            break;
        case 6:
        { // Gọi hàm tính lãi suất vay ngân hàng
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
            double tienVay;
            double laiThang = 0.05;
            double tongTien;
            printf("Nhap so tien muon vay: ");
            scanf("%lf", &tienVay);
            tongTien = tienVay + tienVay * laiThang * 12;
            printf("Tong tien phai tra: %.0lf\n", tongTien);
        }
        break;
        case 7:
            // Gọi hàm vay tiền mua xe
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            {
                double giaTri = 500000000;
                double phanTramVay;
                double tienVay, tienTraTruoc;
                double laiSuatNam = 0.072;
                int thoiHanNam = 24;
                int soThang;
                double tongTien, tienThang;

                printf("Nhap phan tram vay (vd 80): ");
                scanf("%lf", &phanTramVay);

                // Tính tiền vay
                tienVay = giaTri * phanTramVay / 100;

                // Tính tiền trả trước
                tienTraTruoc = giaTri - tienVay;

                // Số tháng vay
                soThang = thoiHanNam * 12;

                // Tổng tiền phải trả (lãi đơn)
                tongTien = tienVay + tienVay * laiSuatNam * thoiHanNam;

                // Tiền trả mỗi tháng
                tienThang = tongTien / soThang;

                printf("Tien tra truoc: %.0lf VND\n", tienTraTruoc);
                printf("Tien tra hang thang: %.0lf VND\n", tienThang);

                return 0;
            }
            break;
        case 8:
            // Gọi hàm sắp xếp thông tin sinh viên
            printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
            {
                int i, j, n;
                printf("nhap so sinh vien: ");
                scanf("%d", &n);
                char ten[n][50];
                float diem[n];
                for (i = 0; i < n; i++)
                {
                    printf("\nnhap ho va ten sv %d: ", i + 1);
                    scanf("%s", &ten[i]);
                    printf("\nnhap diem: ");
                    scanf("%f", &diem[i]);
                }
                for (i = 0; i < n - 1; i++)
                {
                    for (j = i + 1; j < n - 1; j++)
                    {
                        if (diem[i] < diem[j])
                        {
                            float temp_diem = diem[i];
                            diem[i] = diem[j];
                            diem[j] = temp_diem;

                            char temp_ten[50];
                            strcpy(temp_ten, ten[i]);
                            strcpy(ten[i], ten[j]);
                            strcpy(ten[j], temp_ten);
                        }
                    }
                }
                for (i = 0; i < n; i++)
                {
                    if (diem[i] >= 9)
                        printf("hoc sinh xuat sac");
                    else if (diem[i] >= 8)
                        printf("\nHoc luc: Gioi");
                    else if (diem[i] >= 6.5)
                        printf("\nHoc luc: Kha");
                    else if (diem[i] >= 5)
                        printf("\nHoc luc: Trung binh");
                    else
                        printf("\nHoc luc: Yeu");
                }
                return 0;
            }
            break;
        case 9:
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            int sothunhat,sothuhai;
            printf("nhap so thu nhat ban muon chon tu 1-15:");
            scanf("%d",&sothunhat);
            printf("nhap so thu thu ban muon chon tu 1-15:");
            scanf("%d",&sothuhai);
            srand(time(NULL));
            int x = rand() % 15 + 1;
            printf("So ramdom thu nhat: %d", x);
            int y = rand() % 15 + 1;
            printf("\nSo ramdom thu hai: %d", y);
            if(sothunhat==x,sothuhai==y){
                printf("chuc mung ban da trung giai nhat");
            }
            else if(sothunhat==y,sothuhai==x){
                printf("chuc mung ban da trung giai nhat");
            }
            else if(sothunhat==x,sothuhai!=y){
                printf("chuc mung ban da trung giai nhi");
            }
            else if(sothunhat!=x,sothuhai==y){
                printf("chuc mung ban da trung giai nhi");
            }
            else if(sothunhat==y,sothuhai!=x){
                printf("chuc mung ban da trung giai nhi");
            }
            else if(sothunhat!=y,sothuhai==x){
                printf("chuc mung ban da trung giai nhi");
            }
            else{
                printf("chuc ban may man lan sau");
            }
            break;
        case 10:
            // Gọi hàm tính toán phân số
            printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}