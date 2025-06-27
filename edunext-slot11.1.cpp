#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int isFull(int *a, int n);
int isEmpty(int *a, int n);
void checkArray(int *a, int n);
void addValue(int *a, int *n, int value);
int searchValue(int *a, int n, int value);
void removeFirst(int *a, int *n, int value);
void removeAll(int *a, int *n, int value);
void printArray(int *a, int n);
void printAscending(int *a, int n);
void printDescending(int *a, int n);

int main() {
    int a[MAX_SIZE];
    int n = 0;
    int choice, value;
    do {
        printf("\n---Menu---\n\n");
        printf("1. Check Array\n");
        printf("2. Add a value\n");
        printf("3. Search a value\n");
        printf("4. Remove the first existence of a value\n");
        printf("5. Remove all existences of a value\n");
        printf("6. Print out the array\n");
        printf("7. Print out the array in ascending order\n");
        printf("8. Print out the array in descending order\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkArray(a, n);
                break;
            case 2:
                printf("Enter a value to add: ");
                scanf("%d", &value);
                addValue(a, &n, value);
                break;
            case 3:
                printf("Enter a value to search: ");
                scanf("%d", &value);
                {
                  int pos = searchValue(a, n, value);
                  if (pos != -1)
                    printf("Value %d found at position %d.\n", value, pos);
                  else
                    printf("Value %d not found in the array.\n", value);
                }
                break;
            case 4:
                printf("Enter a value to remove: ");
                scanf("%d", &value);
                removeFirst(a, &n, value);
                break;
            case 5:
                printf("Enter a value to remove: ");
                scanf("%d", &value);
                removeAll(a, &n, value);
                break;
            case 6:
                printf("Current array: ");
                printArray(a, n);
                break;
            case 7:
                printf("Array in ascending order: ");
                printAscending(a, n);
                break;
            case 8:
                printf("Array in descending order: ");
                printDescending(a, n);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);
    return 0;
}

int isFull(int *a, int n) {
    if (n >= MAX_SIZE) {
        return 1;
    }
    return 0;
}

int isEmpty(int *a, int n) {
    if (n == 0) {
        return 1;
    }
    return 0;
}

void checkArray(int *a, int n) {
    if (isFull(a, n)) {
        printf("The array is full now.\n");
    } else if (isEmpty(a, n)) {
        printf("The array is empty now.\n");
    } else {
        printf("The array has %d value(s).\n", n);
    }
}

void addValue(int *a, int *n, int value) {
    if (*n >= MAX_SIZE) {
        printf("The array is full, can't add %d into the array.\n", value);
        return;
    }
    a[*n] = value;
    (*n)++;
    printf("Value %d added successfully!\n", value);
}

int searchValue(int *a, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

void removeFirst(int *a, int *n, int value) {
    int pos = searchValue(a, *n, value);
    if (pos == -1) {
        printf("The array does not have that value. No value has been removed.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
    printf("Value %d removed successfully!\n", value);
}

void removeAll(int *a, int *n, int value) {
    int count = 0;
    for (int i = 0; i < *n; ) {
        if (a[i] == value) {
            for (int j = i; j < *n - 1; j++) {
                a[j] = a[j + 1];
            }
            (*n)--;
            count++;
        } else {
            i++;
        }
    }
    if (count > 0) {
        printf("All value %d in the array has been removed.\n", value);
    } else {
        printf("The array does not have that value. No value has been removed.\n");
    }
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printAscending(int *a, int n) {
    int tempArray[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        tempArray[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tempArray[i] > tempArray[j]) {
                int temp = tempArray[i];
                tempArray[i] = tempArray[j];
                tempArray[j] = temp;
            }
        }
    }
    printArray(tempArray, n);
}

void printDescending(int *a, int n) {
    int tempArray[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        tempArray[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tempArray[i] < tempArray[j]) {
                int temp = tempArray[i];
                tempArray[i] = tempArray[j];
                tempArray[j] = temp;
            }
        }
    }
    printArray(tempArray, n);
}