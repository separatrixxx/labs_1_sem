#include <stdio.h>
#include <limits.h>

int ind_matr_max(int matr, int max, int s) {
    if (matr == max) {
        matr = s;
    }
    return matr;
}

int min_matr(int n, int matr[n][n]) {
    int min = INT_MAX;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (matr[i][j] < min) {
                min = matr[i][j];
            }
        }
    }
    return min;
}

int max_matr(int n, int matr[n][n]) {
    int max = INT_MIN;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (matr[i][j] > max) {
                max = matr[i][j];
            }
        }
    }
    return max;
}

int calc_s(int n, int matr[n][n]) {
    int s = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            int p;
            if (matr[j][i] == min_matr(n, matr)) {
                p = 1;
                s += p;
                break;
            }
        }
    }
    return s;
}

int edit_matr(int n, int matr[n][n], int max, int min) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matr[i][j] = ind_matr_max(matr[i][j], max_matr(n, matr), calc_s(n, matr));
        }
    }
    return matr[n][n];
}


void scanmatr(int n, int matr[n][n]) {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf("%d", &matr[i][j]);
        }
    }
}


void printmatr(int n, int matr[n][n]) {

    matr[n][n] = edit_matr(n, matr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != (n - 1)) {
                printf("%d ", matr[i][j]);
            } else {
                printf("%d\n", matr[i][j]);
            }

        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int matr[n][n];

    scanmatr(n, matr);

    printmatr(n, matr);



    return 0;
}