#include <stdio.h>

void displayMatrix(int n, int A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
}

void quickSortDiagonalInPlace(int n, int A[n][n], int left, int right) {
    if (left >= right) return;

    int pivot = A[left][left];
    int i = left;
    int j = right;

    while (i <= j) {
        while (A[i][i] < pivot) i++;
        while (A[j][j] > pivot) j--;

        if (i <= j) {
            int temp = A[i][i];
            A[i][i] = A[j][j];
            A[j][j] = temp;

            i++;
            j--;
        }
    }

    quickSortDiagonalInPlace(n, A, left, j);
    quickSortDiagonalInPlace(n, A, i, right);
}

int main() {
    int n = 0;

    printf("Enter rows and columns (n x n): ");
    scanf("%d", &n);
    int A[n][n]; 

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nBefore:\n");
    displayMatrix(n, A);

    quickSortDiagonalInPlace(n, A, 0, n - 1);

    printf("\nAfter:\n");
    displayMatrix(n, A);

    return 0;
}
