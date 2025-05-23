#include <stdio.h>

int main() {
    int km;
    long fare = 0;

    printf("Nhap so km da di: ");
    scanf("%d", &km);

    if (km <= 0) {
        printf("Quang duong %d km da di.\n");
    } else if (km == 1) {
        fare = 10000;
    } else if (km <= 30) {
        fare = 10000 + (km - 1) * 8000;
    } else {
        fare = 10000 + 29 * 8000 + (km - 30) * 6000;
    }

    if (km > 0) {
        printf("Tien taxi cho %d km la: %ld VND\n", km, fare);
    }

    return 0;
}
