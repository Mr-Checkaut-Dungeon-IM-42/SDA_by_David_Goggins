#include <stdio.h>

int binarySearch(int m, int n, 
    float matrix[m][n], int column, 
    char navigation) {

    int L = 0, R = (navigation == 'c') ? n : m;
    int result = -1;

    while (L < R) {
        int i = (R + L) / 2;
        float elem = (navigation == 'c') ? matrix[i][column] : matrix[m-1][i];
        if (elem >= 0 && elem <= 5) {
            result = i;
            R = i;
        } else if (elem < 0) {
            L = i + 1;
        } else {
            R = i;
        }
    }
    return result;
}

int main() {
    int m, n;

    printf("Type Matrix[row][column]: ");
    scanf("%d %d", &m, &n);
    float matrix[m][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.3f ", matrix[i][j]);
        }
        printf("\n");
    }

    char navigation = 'c'; // r - row, c - column 
    
    int firstColumnIndex = binarySearch(m, n, matrix, 0, navigation);
    if (firstColumnIndex != -1) {
        printf("\nFound element in range [0;5]: %.3f. Coordinates: %d row, 0 column.\n",
               matrix[firstColumnIndex][0], firstColumnIndex);
    } else {
        printf("No elements in range [0;5] found in the first column.\n");
    }


    navigation = 'r';
    int lastRowIndex = binarySearch(m, n, matrix, 0, navigation);
    if (lastRowIndex != -1) {
        printf("\nFound element in range [0;5]: %.3f. Coordinates: %d row, %d column.\n",
               matrix[m - 1][lastRowIndex], m - 1, lastRowIndex);
    } else {
        printf("No elements in range [0;5] found in the last row.\n");
    }

    return 0;
}
