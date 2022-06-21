#include<stdio.h>
#define PI 3.14159
int main(){
    double x;
    scanf("%lf",&x);
    printf("%.3f\n%.3f",x*x*PI,2*x*PI);
    return 0;
}
