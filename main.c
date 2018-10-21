#include <stdio.h>
#include <mem.h>
#include <memory.h>
#include <stdlib.h>

void menu() {
    printf("\t\tQUAN LY SINH VIEN");
    printf("\n\t(Hay nhan phim 1, 2, 3,4 ,5 de lua chon.)");
    printf("\n1. Them moi sinh vien.");
    printf("\n2. Hien thi danh sach sinh vien.");
    printf("\n3. Luu danh sach sinh vien ra file.");
    printf("\n4. Doc danh sach sinh vien tu file.");
    printf("\n5. Thoat chuong trinh.");
    printf("Nhap lua chon tiep theo");
}

typedef struct {
    char TEN[20];
    char MSV[20];
    int SDT[20];
} sinhvien;
sinhvien thongtinsinhvien[10];

void luudanhsach() {
    FILE *fp = fopen("../danhsachsinhvien.txt", "a+");
    for (int i = 0; i < 1; ++i) {
        fprintf(fp, "%-10s|  %-20s|  %8s\n", thongtinsinhvien[i].TEN, thongtinsinhvien[i].MSV, thongtinsinhvien[i].SDT);
    }
    fclose(fp);
}

void hienThiDanhSach() {
    printf("%-10s|  %-20s|  %8s\n", "MSSV", "TEN", "SDT\n");
    printf("%-10s|  %-20s|  %8s\n", thongtinsinhvien[0].MSV, thongtinsinhvien[0].TEN, thongtinsinhvien[0].SDT);
}

void docDanhSach() {
    char myVar[4000];
    FILE *fp = fopen("../danhsachsinhvien.txt", "a+");
    while (fgets(myVar, 4000, fp) != NULL) {
        printf("%s", myVar);
    }
}

void themMoiSinhVien() {
    printf("Vui long nhap thong tin cac sinh vien\n");
    for (int i = 0; i < 1; i++) {
        printf("Ten sinh vien thu %d:\n", i + 1);
        fgets(thongtinsinhvien[0].TEN, sizeof(thongtinsinhvien[0].TEN) * sizeof(char), stdin);
        if (!strchr(thongtinsinhvien[0].TEN, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        thongtinsinhvien[0].TEN[strlen(thongtinsinhvien[0].TEN) - 1] = ' ';
        printf("SDT sinh vien thu %d:\n", i + 1);
        fgets(thongtinsinhvien[0].SDT, sizeof(thongtinsinhvien[0].SDT) * sizeof(int), stdin);
        if (!strchr(thongtinsinhvien[0].SDT, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        thongtinsinhvien[0].SDT[strlen(thongtinsinhvien[0].SDT) - 1] = ' ';
        printf("MSV cua sinh vien thu %d:\n", i + 1);
        fgets(thongtinsinhvien[0].MSV, sizeof(thongtinsinhvien[0].MSV) * sizeof(char), stdin);
        if (!strchr(thongtinsinhvien[0].MSV, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        thongtinsinhvien[0].MSV[strlen(thongtinsinhvien[0].MSV) - 1] = ' ';
        if (strlen(thongtinsinhvien[0].MSV) < 5) {
            printf("MSV khong du 5 ky tu.Moi nhap lai\n");
            themMoiSinhVien();
        }
    }
}

void luachon() {
   menu();
    int chon;
    scanf("%d", &chon);
    getchar();
    switch (chon) {
        case 1:
            themMoiSinhVien();
            luachon();
            break;
        case 2:
            hienThiDanhSach();
            luachon();
            break;
        case 3:
            luudanhsach();
            luachon();
            break;
        case 4:
            docDanhSach();
            luachon();
            break;
        case 5:
            printf("Thoat chuong trinh\n");
            exit(0);
        default:
            printf("Lua chon khong dung. Thoat chuong trinh\n");
            exit(0);
    }
}

int main() {
    luachon();
    return 0;
}