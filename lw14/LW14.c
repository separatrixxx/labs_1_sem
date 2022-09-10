#include <stdio.h>

void scanMatr(int n, int m, int matr[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

void printMatr(int n, int matr[n][n]) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = b; j < a+1; j++) {
            printf("%d ", matr[j][(n-1)+j-a-b]);
        }
        if (i < n-1) {
            a++;
        } else {
            b++;
        }
    }
    printf("\n");
}

int main() {
    int n;
    int matr[n][n];

    scanMatr(n, n, matr);
    printMatr(n, matr);

    return 0;
}
