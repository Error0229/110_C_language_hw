#include <math.h>
#include <stdio.h>
#include <string.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }

double f1(double x, double a, double (*sq)(double), double (*cu)(double))
{
    return sqrt(a - (*sq)(x));
}
double f2(double x, double a, double (*sq)(double), double (*cu)(double))
{
    return (a * x * x * x + 7.0L * x) / sqrt(a + x);
}
double intergral(double (*f)(double, double, double (*)(double), double (*)(double)), double p, double q, double a, double Err)
{
    // long long n = 2;
    double n = 2.0L;
    double gap, sum = 0.0, temp, x;
    double stk = fabs((q - p) * ((*f)(q, a, square, cube) + (*f)(p, a, square, cube)) / 2.0L);
    temp = stk;
    while (1) {
        x = p;
        gap = (q - p) / (double)(n);
        sum = (fabs((*f)(p, a, square, cube)) + fabs((*f)(q, a, square, cube))) / 2.0L;
        for (long long i = 1; i < n; i++) {
            x += gap;
            sum += fabs((*f)(x, a, square, cube));
        }
        sum = (sum * gap);
        // printf("sum: %.12f temp: %.12f n: %.12f gap: %.12f\n", sum, temp, n, gap);
        if (fabs(sum - temp) > Err) {
            temp = sum;
            n = n * 2.0L;
            sum = 0.0L;
            continue;
        }
        break;
    }
    return sum;
}

int main()
{
    int type, err;
    double a, p, q, Err;

    while (1) {
        scanf("%d", &type);
        if (type == 0)
            break;
        scanf("%lf%lf%lf%d", &a, &p, &q, &err);
        Err = pow(10, -err);
        if (type == 1) {
            printf("%.12f\n", intergral(f1, p, q, a, Err));
        }
        if (type == 2) {
            printf("%.12f\n", intergral(f2, p, q, a, Err));
        }
    }
}