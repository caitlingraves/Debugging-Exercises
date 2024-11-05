#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Crop {
    char name[20];
    int yield;  // Yield per acre
    int acres;
};

int calculateTotalYield(struct Crop* crops, size_t size) {
    int totalYield = 0;
    for (size_t i = 0; i <= size; ++i) {  // Intentional off-by-one error
        totalYield += crops[i].yield * crops[i].acres;
    }
    return totalYield;
}

void printHarvestReport(struct Crop* crops, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("Crop: %s, Total Yield: %d bushels\n", crops[i].name, crops[i].yield * crops[i].acres);
    }
}

int main() {
    struct Crop crops[] = {
        {"Pumpkins", 15, 10},
        {"Corn", 30, 20},
        {"Wheat", 25, 25}
    };
    size_t size = sizeof(crops) / sizeof(crops[0]);

    printf("Fall Harvest Report:\n");
    printHarvestReport(crops, size);

    int totalYield = calculateTotalYield(crops, size);  // Check for issues in total yield calculation
    printf("Total Harvest Yield: %d bushels\n", totalYield);

    // Memory issue: allocate dynamically but never free
    int* estimatedProfit = (int*)malloc(sizeof(int));
    *estimatedProfit = totalYield * 3;  // Assume $3 per bushel
    printf("Estimated Profit: $%d\n", *estimatedProfit);

    // Uncomment the line below to prevent the memory leak
    // free(estimatedProfit);

    return 0;
}
