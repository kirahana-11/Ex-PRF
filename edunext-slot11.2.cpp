#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
    float arr[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMENU:\n");
        printf("1 - Add a value\n");
        printf("2 - Search a value\n");
        printf("3 - Print the array\n");
        printf("4 - Print values in a range\n");
        printf("5 - Print array in ascending order\n");
        printf("Other - Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < MAX) {
                float x;
                printf("Enter a value: ");
                scanf("%f", &x);
                arr[count] = x;
                count++;
                printf("Value added!\n");
            } else {
                printf("Array is full!\n");
            }
        }

        else if (choice == 2) {
            float x;
            int found = 0;
            printf("Enter value to search: ");
            scanf("%f", &x);
            for (int i = 0; i < count; i++) {
                if (arr[i] == x) {
                    printf("Found at position %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Not found.\n");
            }
        }

        else if (choice == 3) {
            printf("Array: ");
            for (int i = 0; i < count; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
        }

        else if (choice == 4) {
            float min, max;
            printf("Enter min and max: ");
            scanf("%f %f", &min, &max);
            printf("Values in range: ");
            for (int i = 0; i < count; i++) {
                if (arr[i] >= min && arr[i] <= max) {
                    printf("%.2f ", arr[i]);
                }
            }
            printf("\n");
        }

        else if (choice == 5) {
            float temp;
            float copy[MAX];
            for (int i = 0; i < count; i++) {
                copy[i] = arr[i];
            }

            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (copy[j] > copy[j + 1]) {
                        temp = copy[j];
                        copy[j] = copy[j + 1];
                        copy[j + 1] = temp;
                    }
                }
            }

            printf("Sorted array: ");
            for (int i = 0; i < count; i++) {
                printf("%.2f ", copy[i]);
            }
            printf("\n");
        }

        else {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}
