#include <stdio.h>

int main() {
    int money;
    printf("Nhap so dai dien don vi tien te (1: USD, 2: EUR, 3: VND, 4: JPY): ");
    scanf("%d", &money);

    switch (money) {
        case 1:
            printf("USD\n");
            break;
        case 2:
            printf("EUR\n");
            break;
        case 3:
            printf("VND\n");
            break;
        case 4:
            printf("JPY\n");
            break;
        default:
            printf("Gia tri khong hop le. Vui long nhap so tu 1 den 4.\n");
    }

    return 0;
}
