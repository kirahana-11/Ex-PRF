#include <stdio.h>

int main() {
    int rows, cols;
    int i, j;
    
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int arr[100][100];

    printf("Nhap gia tri cho mang 2 chieu:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nMang 2 chieu la:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    int max = arr[0][0];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("\nGia tri lon nhat trong mang la: %d\n", max);

    printf("\nTong cua tung hang:\n");
    for (i = 0; i < rows; i++) {
        int sum = 0;
        for (j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        printf("Hang %d: %d\n", i, sum);
    }

    return 0;
}
