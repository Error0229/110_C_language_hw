#include<stdio.h>
int main(){
    double a,b;
    char ch[20];
    for (int i = 0 ; i < 6 ; i++){
        scanf("%s",&ch);
        double k = 0;
        if (*ch == 'A'){
            k = 1;
        }
        else if(*ch == '2'){
            k = 2;
        }
        else if(*ch == '3'){
            k = 3;
        }
        else if(*ch == '4'){
            k = 4;
        }
        else if(*ch == '5'){
            k = 5;
        }
        else if(*ch == '6'){
            k = 6;
        }
        else if(*ch == '7'){
            k = 7;
        }
        else if(*ch == '8'){
            k = 8;
        }
        else if(*ch == '9'){
            k = 9;
        }
        else if(*ch == '1'){
            k = 10;
        }
        else{
            k = 0.5;
        }
        a = i < 3 ? a + k : a;
        b = i > 2 ? b + k : b;
    }
    a = a > 10.5 ? 0 : a;
    b = b > 10.5 ? 0 : b;
    printf("%.1f\n%.1f\n",a,b);
    printf("%s",(a > b ? "A wins." : (a < b ? "B wins." : "It's a tie.") ));
}
