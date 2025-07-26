#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100


int checkFileExists(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp) {
        fclose(fp);
        return 1;
    }
    return 0;
}

void generateSampleData(const char *fileName) {
    FILE *fp = fopen(fileName, "w");
    if (fp) {
        fprintf(fp, "25\n30\n45\n10\n60\n5\n");
        fclose(fp);
        printf("Generated sample data file: %s\n", fileName);
    }
}

size_t loadArrayFromFile(const char *fileName, int arr[]) {
    FILE *fp = fopen(fileName, "r");
    if (!fp) {
        perror("Failed to open file");
        return 0;
    }

    size_t count = 0;
    while (count < MAX_SIZE && fscanf(fp, "%d", &arr[count]) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

void showArray(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void computeStats(const int arr[], size_t size, int *sum, float *avg, int *maxVal, int *minVal) {
    *sum = 0;
    *maxVal = INT_MIN;
    *minVal = INT_MAX;

    for (size_t i = 0; i < size; i++) {
        *sum += arr[i];
        if (arr[i] > *maxVal) *maxVal = arr[i];
        if (arr[i] < *minVal) *minVal = arr[i];
    }

    *avg = (size > 0) ? (float)*sum / size : 0.0f;
}

void saveResultsToFile(const char *fileName, int sum, float avg, int maxVal, int minVal) {
    FILE *fp = fopen(fileName, "w");
    if (!fp) {
        perror("Failed to open results file");
        return;
    }

    fprintf(fp, "Sum: %d\nAverage: %.2f\nMaximum: %d\nMinimum: %d\n", 
            sum, avg, maxVal, minVal);
    fclose(fp);
}

int main() {
    const char *dataFile = "data.txt";

    if (!checkFileExists(dataFile)) {
        generateSampleData(dataFile);
    }

    int arr[MAX_SIZE];
    size_t dataSize = loadArrayFromFile(dataFile, arr);

    if (dataSize == 0) {
        printf("No data found in file. Exiting.\n");
        system("pause");
        return EXIT_FAILURE;
    }

    printf("Data in the array:\n");
    showArray(arr, dataSize);

    int total, maxNum, minNum;
    float mean;
    computeStats(arr, dataSize, &total, &mean, &maxNum, &minNum);

    printf("\nStatistics:\n");
    printf("Sum: %d\n", total);
    printf("Average: %.2f\n", mean);
    printf("Maximum: %d\n", maxNum);
    printf("Minimum: %d\n\n", minNum);

    saveResultsToFile("results.txt", total, mean, maxNum, minNum);
    printf("Results written to results.txt\n");

    system("pause");
    return EXIT_SUCCESS;
}