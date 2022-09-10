#include <stdio.h>

int abs(int a){
    if (a < 0){
        a = -a;
    }
    return a;
}



int area1(int x, int y) {
    return (abs((x-0)*(0-10)-(-10-0)*(y-10)))/2;
}

int area2(int x, int y) {
    return (abs((x+10)*(0-20)-(-10+10)*(y-20)))/2;
}

int area3(int x, int y) {
    return (abs((x-0)*(20-10)-(-10-0)*(y-10)))/2;
}

int sign(int a)
{
    if (a<0) {
        return -1;
    } else if (a>0) {
        return 1;
    } else {
        return 0;
    }
}

int min(int a, int b)
{
    if (a<b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b)
{
    if (a<b) {
        return b;
    } else {
        return a;
    }
}

int mod(int a, int b){
    if ((a > 0 && b > 0) || (a < 0 && b < 0) || a == (a / b) * b ){
        return a - a / b * b;
    } else {
        return a - b * (a / b - 1);
    }
}

int div(int a, int b){
    return (a - mod(a, b)) / b;
}

int main() {
    int i1, j1, l1;
    int i = 8;
    int j = 15;
    int l = 10;
    int k = 0;
    int u = 0;
    while (k <= 49) {
        i1 = mod(( mod((i+j), (abs(min(j-l, l-k)) +1 )) - k), 20) + 10;
        j1 = max(div((i+j), (2+sign(j*l-i*k))), div((j+l), (2+sign(i*j-l*k))))-10;
        l1 = mod((max(i, j)*min(i, l)), 30);
        i = i1;
        j = j1;
        l = l1;
        if ((area1(i1, j1)+area2(i1, j1)+area3(i1, j1)) == 100 ) {
            printf("YES, k = %d\n", k);
            printf("i = %d\t", i);
            printf("j = %d\t", j);
        } else {
            u += 1;
        }
        k += 1;
    }
    if (u == 50) {
        printf("NO, k = %d\t", k);
        printf("i = %d\t", i);
        printf("j = %d\n", j);
    }
    return 0;
}
