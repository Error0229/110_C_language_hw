#include<stdio.h>
int main(){
    char a;
    int i = 0, out = 0;
    a = getchar();
    getchar();
    if (a=='H'){
        i=0;
    }
    else if (a=='3'){
        i<<=3;
        i+=1<<3;
    }
    else if (a=='2'){
        i<<=2;
        i+=1<<2;
    }
    else if (a=='1'){
        i<<=1;
        i+=1;
    }
    else out+=1;
    a = getchar();
    getchar();
    if (a=='H'){
        i=0;
    }
    else if (a=='3'){
        i<<=3;
        i+=1<<3;
    }
    else if (a=='2'){
        i<<=2;
        i+=1<<2;
    }
    else if (a=='1'){
        i<<=1;
        i+=1;
    }
    else out+=1;
    a = getchar();
    getchar();
    if (a=='H'){
        i=0;
    }
    else if (a=='3'){
        i<<=3;
        i+=i<<3;
    }
    else if (a=='2'){
        i<<=2;
        i+=i<<2;
    }
    else if (a=='1'){
        i<<=1;
        i+=1;
    }
    else out+=1;
    if (out==3){
        i=0;
        out=0;
    }
    a = getchar();
    getchar();
    if (a=='H'){
        i=0;
    }
    else if (a=='3'){
        i<<=3;
        i+=1<<3;
    }
    else if (a=='2'){
        i<<=2;
        i+=1<<2;
    }
    else if (a=='1'){
        i<<=1;
        i+=1;
    }
    else out+=1;
    if (out==3){
        i=0;
        out=0;
    }
    a = getchar();
    getchar();
    if (a=='H'){
        i=0;
    }
    else if (a=='3'){
        i<<=3;
        i+=1<<3;
    }
    else if (a=='2'){
        i<<=2;
        i+=1<<2;
    }
    else if (a=='1'){
        i<<=1;
        i+=1;
    }
    else out+=1;
    if (out==3){
        i=0;
        out=0;
    }
    printf("%d\n",i&1);
    i>>=1;
    printf("%d\n",i&1);
    i>>=1;
    printf("%d\n",i&1);
    i>>=1;

}
