#include <stdio.h>



int decr(int a) {
    if (a % 2 == 0 && a != 0) {
        return a - 1;
    } else if (a % 2 != 0 && a != 0) {
        return a;
    }
    return 9;
}

int decrm(int a) {
    if (a % 2 == 0 && a != 0) {
        return a + 1;
    } else if (a % 2 != 0 && a != 0) {
        return a;
    }
    return -9;
}


int vc(int a) {
    int b;
    int c = 0;
    int k = 1;
    while (a >= 10) {
        k *= 10;
        a = a / 10;
        b = a % 10;
        b = decr(b);
        c = c + b*k;
    }
    return c;
}


int vcm(int a) {
    int b;
    int c = 0;
    int k = 1;
    while (a <= -10) {
        k *= 10;
        a = a / 10;
        b = a % 10;
        b = decrm(b);
        c = c + b*k;
    }
    return c;
}


int proc(int a) {
    int d;
    if (a > 0) {
        d = a % 10;
        int c = vc(a);
        c = c + decr(d);
        return c;
    } else if (a < 0) {
        d = a % 10;
        int c = vcm(a);
        c = c + decrm(d);
        return c;
    }
    return 9;
}


int main() {
    int a;

    while (scanf("%d", &a) != EOF) {
        printf("%d\n", proc(a));
    }

    return 0;
}
