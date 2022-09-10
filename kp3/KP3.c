#include <stdio.h>
#include <math.h>

long double m_eps() {
    long double e = 1;
    long double eps;
    while(1 < (1 + e)){
        eps = e;
        e /= 2;
    }
    return eps;
}

long double func(long double x){
    return log((1 + x) / (1 - x));
}

int main(){
    long double n, a = 0, b = 0.5;
    long double x = a;
    printf("Chislo razbieniy otrezka: ");
    scanf("%Lf", &n);
    long double step = (b-a)/n;
    long double eps = m_eps();
    printf("Epsilon: %.64Lf\n", eps);
    printf("______________________________________________________________________________\n");
    printf("|  x  |  Sum                | ln ((1+x) / (1-x))  | n |  Raznost'            |\n");
    printf("|_____|_____________________|_____________________|___|______________________|\n");

    for(int i = 0; i <= n; i++, x += step){
        int n = 1;
        long double zn_x = x;
        long double sum = 0;

        long double k = 1.0;

        while(((zn_x > eps || zn_x < -eps) && n < 100)) {

            if (n == 1) {
                zn_x = 2*zn_x / k;
            } else {
                zn_x = (k-2)*(zn_x*x*x) / k;
            }

            sum += zn_x;
            n++;
            k += 2;
        }

        printf("|%.3Lf|%.19Lf|%.19Lf|%3d|%.19Lf|\n", x, sum, func(x), n, sum-func(x));
    }

    printf("|_____|_____________________|_____________________|___|______________________|\n");
}
