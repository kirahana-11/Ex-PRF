#include <stdio.h>
#define MAX_SIZE 100

void inputData(int arr[], int *size) {
    printf("Enter the size of the array(max 100):");
    scanf("%d",size);
    if (*size <= MAX_SIZE) {
        printf("Enter %d elements:\n",*size);
        for (int i = 0; i <*size; i++) {
            printf("Number %d: ", i);
            scanf("%d", &arr[i]);
        }
        printf("Data input successful\n");
        } else {
        printf("Size exceeds maximum limit of 100\n");
        *size = 0;
    }
}
void inputArray(int arr[], int*size){
    printf("Enter the size of the array (max 100):");
    scanf("%d", size);
    if (*size <= MAX_SIZE) {
        printf("Enter %d elements:\n", *size);
        for (int i = 0; i < *size; i++) {
            printf("Number %d: ", i);
            scanf("%d", &arr[i]);
        }
        printf("Data input successful!\n");
    } else {
        printf("Size exceeds maximum limit of 100!\n");
        *size = 0;
    }
}

void displayArray(int arr[], int size) {
    if (size > 0) {
        printf("Display array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No data to display. Please input data first!\n");
    }
}

void searchNumber(int arr[], int size) {
    int target;
    if (size > 0) {
        printf("Search for a number:\n");
        printf("Enter the number to search for: ");
        scanf("%d", &target);
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                printf("The number %d is found at index %d\n",target,i);
                return;
            }
        }
        printf("Number %d not found in the array!\n",target);
    }else{
        printf("No data to search. Please input data first!\n");
    }
}

void calculateStatistics(int arr[],int size){
    if (size > 0) {
        int sum = 0, max = arr[0], min = arr[0];
        for (int i = 0; i<size; i++) {
            sum += arr[i];
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }
        float average = (float)sum / size;
        printf("Calculate statistics (Sum, Average, Max, Min):\n");
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
        printf("Max: %d\n",max);
        printf("Min: %d\n",min);
    } else {
        printf("No data to calculate. Please input data first\n");
    }
}
void reverseArray(int arr[], int size) {
    if (size > 0) {
        int temp;
        for (int i = 0; i < size / 2; i++) {
            temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
        printf("Reversed array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No data to reverse. Please input data first!\n");
    }
}
int main() {
    int arr[MAX_SIZE], size = 0, choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Input data\n");
        printf("2. Display array\n");
        printf("3. Search for a number\n");
        printf("4. Calculate statistics (Sum, Average, Max, Min)\n");
        printf("5. Reversed array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                inputData(arr, &size);
                break;
            case 2: 
                if (size > 0) {
                    displayArray(arr, size);
                } 
				else {
                    printf("No data to display. Please input data first\n");
                }
                break;
            case 3:
                searchNumber(arr, size);
                break;
            case 4: 
                calculateStatistics(arr, size);
                break;
            case 5:
                reverseArray(arr, size);
                break;
            case 6:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice. Try again\n");
        }
    } while (choice != 6);
    return 0;
}