#include <stdio.h>

int main() {
    int d, m;
    printf("Nhap ngay: ");
    scanf("%d", &d);
    printf("Nhap thang: ");
    scanf("%d", &m);

    switch(m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (d >= 1 && d <= 31)
                printf("Ngay hop le: %02d/%02d\n", d, m);
            else
                printf("Ngay khong hop le.\n");
            break;
        case 4: case 6: case 9: case 11:
            if (d >= 1 && d <= 30)
                printf("Ngay hop le: %02d/%02d\n", d, m);
            else
                printf("Ngay khong hop le.\n");
            break;
        case 2:
            if (d >= 1 && d <= 28)
                printf("Ngay hop le: %02d/%02d\n", d, m);
            else
                printf("Ngay khong hop le.\n");
            break;
        default:
            printf("Thang khong hop le.\n");
    }

    return 0;
}
