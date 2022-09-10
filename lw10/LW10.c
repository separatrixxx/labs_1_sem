#include <stdio.h>

int rec(int a){
    if (a <= 0) {
        return 0;
    }
    return a + rec(a-1) * (rec(a-3) + 5);
}

int proc(int a){
    return a + 2;
}

int main() {
    int a = 3;

    a = proc(a);

    printf("%d\n", rec(a - 2));

    return 0;
}
