#include<stdio.h>
int main(){
    double x,y,h1,h2;
    scanf("%lf%lf%lf%lf",&h1,&h2,&x,&y);
    printf("%.1f\n%.1f\n%.1f",x*(h1+h2)*0.92-y*0.05,y*0.05,x*(h1+h2)*0.08);
}
