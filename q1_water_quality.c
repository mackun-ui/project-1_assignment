#include <stdio.h>
#include <stdlib.h>

/**
 * purpose: reads temperature (temp) and turbidity (turb) from the user,
 * calculates a simplified water-quality index, classifies the water, and
 * prints a formatted monitoring report.
 * Return: 0 Always (Successful)
 */

float calculateIndex(float temp, float turb) {
    float tempDeviation = abs((int)(temp - 25));
    float turbPenalty = turb / 2;
    return 100 - (tempDeviation + turbPenalty);
}

const char* classify(float index) {
    if (index >= 80) {
        return "Good";
    } else if (index >= 60) {
        return "Warning";
    } else {
        return "Critical";
    }
}

int main() {
    float temp, turb;

    printf("Enter temperature (°C): ");
    scanf("%f", &temp);
    printf("Enter turbidity (NTU): ");
    scanf("%f", &turb);

    float index = calculateIndex(temp, turb);

    printf("\n===== WATER QUALITY REPORT =====\n");
    printf("Temperature: %.1f °C\n", temp);
    printf("Turbidity: %.1f NTU\n", turb);
    printf("Index: %.1f\n", index);
    printf("Status: %s\n", classify(index));

    return 0;
}