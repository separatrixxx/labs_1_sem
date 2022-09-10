#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long set;


int A = 1040, 
a = 1072, 

E = 1069, 
e = 1101, 

Je = 1045, 
je = 1077, 

Jo = 1025,
jo = 1105,

O = 1054,
o = 1086,

Y = 1067,
y = 1099,

U = 1059,
u = 1091,

Ju = 1070,
ju = 1102,

I = 1048,
i = 1080,

Ja = 1071,
ja = 1103;


int getchar_utf8(){
    int c = getchar();
    int n_bytes;
    
    if (c < 128){
        return c;
    } else {
	    if (c >= 192 && c < 224){
		c = c^192;
		n_bytes = 2;
	    } else if (c >= 224 && c < 240){
		c = c^224;
		n_bytes = 3;
	    } else {
		c = c^240;
		n_bytes = 4;
	    }
	    
	    
	    for (int i = 0; i < n_bytes-1; i++){
	    	int utf8_char = getchar()^128;
		c = c << 6;
		c = utf8_char | c;
	    }
    }
    return c;
}


int letter_to_index(int c){
	if (c>=A && c<=Ja){
		return c-A;
	} else if (c>=a && c<=ja){
		return c-a;
	} else if (c==Jo || c==jo){
		return 32;
	} else {
		return -1;
	}
}

set letter_to_set(int c){
    int idx = letter_to_index(c);
    if (idx == -1){
        return 0;
    }
    return ((set)1) << idx;
}

bool is_sep(int c) {
    return (('\t' <= c && c <= '\r') || c == ' ' || c == EOF || c == ',');
}

bool is_incl(set word, set set_gl) {
    return ((word & set_gl) == set_gl);
}



int main() {
    int c;
    int flag = 0;
    set word = 0;

    set sA = letter_to_set(A);
    set sO = letter_to_set(O);
    set sU = letter_to_set(U);
    set sE = letter_to_set(E);
    set sY = letter_to_set(Y);
    set sI = letter_to_set(I);
    set sJa = letter_to_set(Ja);
    set sJo = letter_to_set(Jo);
    set sJu = letter_to_set(Ju);
    set sJe = letter_to_set(Je);

    set set_gl = sA | sO | sU | sE | sY | sI | sJa | sJo | sJu | sJe;

    do {
        c = getchar_utf8();
        if (!is_sep(c)){
            word = word|letter_to_set(c);
        }
        else if (c == ' ' || c == ',' || c == '\n'){
            if ((word & set_gl) == 0){
                flag = 1;
            } else if ((word & set_gl) != 0) {
                if (is_incl(word, set_gl)) {
                    flag = 2;
                } else {
                    flag = 1;
                }
            }

        } else if (c == EOF){
            if (flag == 2 || is_incl(word, set_gl)) {
                printf("Таких гласных нет\n");
            } else {
                printf("Такие гласные есть\n");
            }
            word = 0;
            flag = 0;
        }
    } while(c != EOF);
    
    
    
    

}
