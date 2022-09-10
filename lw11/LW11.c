#include <stdio.h>
#include <stdbool.h>


typedef enum {
    STATE_FIND_FIRST_DIGIT,
    STATE_FIRST_DIGIT_IS_TR,
    STATE_FIRST_DIGIT_IS_NOT_TR,
    STATE_LAST_DIGIT_IS_NULL,
    STATE_FIRST_DIGIT_IS_NULL
} state;


bool is_tr (int c) {
    if (c == '0' || c == '1' || c == '2') {
        return true;
    }
    return false;
}

bool is_p (int c) {
    if (c == '+') {
        return true;
    }
    return false;
}

bool is_m (int c) {
    if (c == '-') {
        return true;
    }
    return false;
}

int get_int(char c) {
    return c - '0';
}

bool is_space(char c) {
    return (('\t' <= c && c <= '\r') || c == ' ' || c == EOF);
}

int main() {
    state s = STATE_FIND_FIRST_DIGIT;
    int c;
    int d = 0;
    int p = 0;
    do {
        c = getchar();
        if (s == STATE_FIND_FIRST_DIGIT) {
            if (is_tr(c)) {
                if (c == '0') {
                    d = 0;
                    s = STATE_FIRST_DIGIT_IS_NULL;
                } else {
                    d = get_int(c);
                    s = STATE_FIRST_DIGIT_IS_TR;
                }
            } else if (is_space(c)) {
                s = STATE_FIND_FIRST_DIGIT;
            } else if (is_p(c) && p==0) {
                p = 2;
                s = STATE_FIND_FIRST_DIGIT;
            } else if (is_m(c) && p==0) {
                p = 1;
                s = STATE_FIND_FIRST_DIGIT;
            } else {
                s = STATE_FIRST_DIGIT_IS_NOT_TR;
            }
        } else if (s == STATE_FIRST_DIGIT_IS_TR) {
            if (is_tr(c)) {
                if (c == '0') {
                    d = d*10;
                    s = STATE_LAST_DIGIT_IS_NULL;
                } else {
                    d = d*10 + get_int(c);
                    s = STATE_FIRST_DIGIT_IS_TR;
                }
            } else if (is_space(c)) {
                s = STATE_FIND_FIRST_DIGIT;
            } else {
                s = STATE_FIRST_DIGIT_IS_NOT_TR;
            }
        } else if (s == STATE_FIRST_DIGIT_IS_NOT_TR) {
            p = 0;
            if (is_space(c)) {
                s = STATE_FIND_FIRST_DIGIT;
            } else {
                s = STATE_FIRST_DIGIT_IS_NOT_TR;
            }
        } else if (s == STATE_LAST_DIGIT_IS_NULL) {
            if (c == '0') {
                d = d*10;
                s = STATE_LAST_DIGIT_IS_NULL;
            } else if (is_space(c)) {
                if (p != 1) {
                    printf("%d\n", d);
                    p = 0;
                } else {
                    if (d == 0) {
                        printf("%d\n", d);
                        p = 0;
                    } else {
                        printf("-%d\n", d);
                        p = 0;
                    }
                }
                s = STATE_FIND_FIRST_DIGIT;
            } else if (is_tr(c)){
                d = d*10 + get_int(c);
                s = STATE_FIRST_DIGIT_IS_TR;
            } else {
                s = STATE_FIRST_DIGIT_IS_NOT_TR;
            }
        } else {
            if (is_space(c)) {
                printf("%d\n", d);
                p = 0;
                s = STATE_FIND_FIRST_DIGIT;
            } else if (is_tr(c)){
                d = d*10 + get_int(c);
                s = STATE_FIRST_DIGIT_IS_TR;
            } else {
                s = STATE_FIRST_DIGIT_IS_NOT_TR;
            }
        }
    }
    while (c != EOF);

    return 0;
}