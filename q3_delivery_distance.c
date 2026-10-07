#include <stdio.h>

/**
 * purpose: stores delivery route distances in an array and analyses them:
 * total, average, longest route, routes above a limit, and a recursive
 * sum
 * Return: 0 Always (Successful)
 */

#define MAX_ROUTES 100

int calculateTotal(int distances[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++) {
        total += distances[i];
    }
    return total;
}

double calculateAverage(int distances[], int n) {
    return (double) 
    calculateTotal(distances, n) /n;
}

int findLongest(int distances[], int n) {
    int i;
    int longest = distances[0];

    for (i = 1; i < n; i++) {
        if (distances[i] > longest) {
            longest = distances[i];
        }
    }
    return longest;
}

int countAboveLimit(int distances[], int n, int limit) {
    int i;
    int count = 0;

    for (i = 0; i < n; i++) {
        if (distances[i] > limit) {
            count++;
        }
    }
    return count;
}

int recursiveSum(int distances[], int n) {
    if (n == 0) {
        return 0;
    }
    return distances[n - 1] + recursiveSum(distances, n - 1);
}

int main() {
    int distances[MAX_ROUTES];
    int n;
    int i;
    int limit;

    printf("Number of routes (1-%d): ", MAX_ROUTES);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_ROUTES) {
        printf("Invalid number of routes.\n");
        return 1;
    }

    printf("Enter the %d distances (km): ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &distances[i]);
    }

    printf("Distance limit: ");
    scanf("%d", &limit);

    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", calculateTotal(distances, n));
    printf("Average distance: %.2f km\n", calculateAverage(distances, n));
    printf("Longest route: %d km\n", findLongest(distances, n));

    printf("Routes above %d km: %d\n", limit, countAboveLimit(distances, n, limit));
    printf("Routes above 30 km: %d\n", countAboveLimit(distances, n, 30));

    printf("\nRecursive sum: %d km\n", recursiveSum(distances, n));

    return 0;
}