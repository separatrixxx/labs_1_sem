#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef double (*func)(double);

typedef struct {
    double root;
    int iters;
    bool success;
} result;

double Fx_2(double x){
    return cos(x) - exp(-x*x/2) + x - 1;
}
double dFx_2(double x){
    return exp(-x*x/2)*x - sin(x) + 1;
}
double d2Fx_2(double x){
    return -exp(-x*x/2)*(x*x + exp(x*x/2)* cos(x) - 1);
}

double fx_2(double x){
    return exp(-x*x/2) - cos(x) + 1;
}
double dfx_2(double x){
    return sin(x) - exp(-x*x/2)*x;
}


double Fx_3(double x){
    return 1 - x + sin(x) - log(1 + x);
}
double dFx_3(double x){
    return -1/(1+x) + cos(x) - 1;
}
double d2Fx_3(double x){
    return 1/((1+x)*(1+x)) - sin(x);
}
double fx_3(double x){
    return 1 + sin(x) - log(1 + x);
}
double dfx_3(double x){
    return cos(x) - 1/(1+x);
}

result diho(func f, double a, double b){
    result res;
    double delta = pow(2, -26);
    res.iters = 0;
    while (b-a > delta){
        double c = (a+b)/2;
        if (f(a)*f(c) < 0){
            b = c;
        } else {
            a = c;
        }
        res.iters++;
    }
    res.root = (a+b)/2;
    res.success = 1;
    return res;
}

result newton(func f, func df, func d2f, double a, double b){
    result res;
    double x = (a+b)/2;
    if (fabs(f(x)*d2f(x)) >= df(x)*df(x)){
        res.success = 0;
        return res;
    }
    double x1 = x - (f(x)/df(x));
    if (fabs(f(x1)*d2f(x1)) >= df(x1)*df(x1)){
        res.success = 0;
        return res;
    }
    double delta = pow(2, -26);
    res.iters = 1;
    while (fabs(x - x1) > delta){
        x = x1;
        if (fabs(f(x)*d2f(x)) >= df(x)*df(x)){
            res.success = 0;
            return res;
        }
        x1 = x - (f(x)/df(x));
        res.iters++;
    }
    res.root = x1;
    res.success = 1;
    return res;
}

result iters(func f, func fx, func dfx, double a, double b){
    result res;
    double x = (a+b)/2;
    double delta = pow(2, -26);
    if (dfx(x) >= 1){
        res.success = 0;
        return res;
    }
    res.iters = 1;
    double x1 = fx(x);
    while (fabs(x - x1) > delta){
        x = x1;
        if (dfx(x) >= 1){
            res.success = 0;
            return res;
        }
        x1 = fx(x);
        res.iters++;
    }
    res.root = x1;
    res.success = 1;
    return res;
}

int main() {
    
    result x1 = diho(Fx_2, 1, 2), 
    x2 = iters(Fx_2, fx_2, dfx_2, 1, 2), 
    x3 = newton(Fx_2, dFx_2, d2Fx_2, 1, 2);
    
    result x4 = diho(Fx_3, 1, 1.5), 
    x5 = iters(Fx_3, fx_3, dfx_3, 1, 1.5), 
    x6 = newton(Fx_3, dFx_3, d2Fx_3, 1, 1.5);

    printf("_______________________________________________________________________\n");
    printf("| Funciya              | Otrezok| Method     |      Rezultat             \n");
    printf("|____________________________|________|____________|_________________________\n");
    
    if (x1.success == 1){
        printf("| Func var 2                 | [1,2]  | Dihotomiya | %.4lf za %d iteraciy  \n", x1.root, x1.iters);
    } else {
        printf("| Func var 2                 | [1,2]  | Dihotomiya | Method ne primenim  \n");
    }
    if (x2.success == 1){
        printf("|                            |        | Iteraciy   | %.4lf  za %d iteraciy  \n", x2.root, x2.iters);
    } else {
        printf("|                            |        | Iteraciy   | Method ne primenim  \n");
    }
    if (x3.success == 1){
        printf("|                            |        | Newtona    | %.4lf  za %d iteraciy  \n", x3.root, x3.iters);
    } else {
        printf("|                            |        | Ньютона    | Method ne primenim  \n");
    }
    printf("|_________________________________________________________________________\n");
    if (x4.success == 1){
        printf("| Func var 3                 | [1,1.5]| Dihotomiya | %.4lf  za %d iteraciy \n", x4.root, x4.iters);
    } else {
        printf("| Func var 3                | [1,1.5]  | Dihotomiya | Method ne primenim \n");
    }
    if (x5.success == 1){
        printf("|                            |        | Iteraciy   | %.4lf  za %d iteraciy \n", x5.root, x5.iters);
    } else {
        printf("|                            |        | Iteraciy   | Method ne primenim \n");
    }
    if (x6.success == 1){
        printf("|                            |        | Newtona    | %.4lf  za %d iteraciy  \n", x6.root, x6.iters);
    } else {
        printf("|                            |        | Newtona    | Method ne primenim  \n");
    }
    printf("______________________________________________________________________\n");
    
}
