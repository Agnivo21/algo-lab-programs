#include <stdio.h>

void fractionalKnapsack(int n, float capacity, float values[], float weights[]) {
    float ratio[n], temp;
    int i, j;
    float totalValue = 0.0;
    
    // Calculate value-to-weight ratio for each item
    for (i = 0; i < n; i++) {
        ratio[i] = values[i] / weights[i];
    }
    
    // Sort items based on the ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                
                // Swap weights
                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
                
                // Swap values
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    
    // Pick items based on greedy strategy
    for (i = 0; i < n; i++) {
        if (capacity == 0)
            break;
        
        if (weights[i] <= capacity) {
            // Pick the whole item
            totalValue += values[i];
            capacity -= weights[i];
        } else {
            // Pick fractional item
            totalValue += values[i] * (capacity / weights[i]);
            capacity = 0;
        }
    }
    
    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n;
    float capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    float values[n], weights[n];
    
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &values[i]);
    }
    
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &weights[i]);
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    
    fractionalKnapsack(n, capacity, values, weights);
    
    return 0;
}
