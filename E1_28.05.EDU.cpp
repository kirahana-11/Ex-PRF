#include <stdio.h>
int main(){
    int x;
	int sum=0;
    do {
        printf("Nhap so nguyen(0 de ket thuc):");
        scanf("%d", &x);
        sum += x;
    } while (x != 0);
    printf("Tong cac so nguyen la: %d\n",sum);
    return 0;
}
