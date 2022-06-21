#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int todig(char *str,int *id){
	int k = 0,fl=1;
	if (str[*id]=='-'){
		fl=-1;
		(*id)++;
	}
	while(isdigit(str[*id])){
		k=(k<<3)+(k<<1)+(str[(*id)++]-'0');
	}
	return k*fl;
}
int gcd(int a,int b){
	if (a%b==0)return b;
	else return gcd(b,a%b);
}
int main(){
    int cnt=0,n;
    char a[5000],b[5000],ch,ju,nl;
    scanf("%s%s",a,b);
    printf("y=");
    int x1,y1,x2,y2,*id,idk=0,tpm,dwm,tpb,dwb;
    id = &idk;
    x1=todig(a,id);
    idk+=1;
    y1=todig(a,id);
    idk=0;
    x2=todig(b,id);
    idk+=1;
    y2=todig(b,id);
    tpm = y1-y2;
    dwm = x1-x2;
    tpb = x2*y1-x1*y2;
    dwb = x2-x1;
    if (dwm < 0){
        dwm *= -1;
        tpm *= -1;
    }
    if (dwb < 0){
        dwb *= -1;
        tpb *= -1;
    }
    int gcdm = gcd(abs(tpm),dwm), gcdb = gcd(abs(tpb),dwb);
    tpm/=gcdm,dwm/=gcdm,tpb/=gcdb,dwb/=gcdb;

    if (dwm == 1 && tpm!=0){
        if (abs(tpm)!=1)printf("%d", tpm);
        else if(tpm==-1)printf("-");
        printf("x");
    }

    else if(abs(tpm)>dwm){
        int k =1;
        if (tpm<0)k=-1;
        k*=(abs(tpm)/dwm);
        tpm= abs(tpm)-(abs(tpm)/dwm)*dwm;
        printf("%d(%d/%d)x",k,tpm,dwm);

    }
    else if (tpm != 0){
        printf("%d/%dx",tpm,dwm);
    }
    if (tpb>0 && tpm !=0)printf("+");

    if ((dwb == 1 && tpb!=0) || (abs(tpm)==0)){
        printf("%d", tpb);
    }
    else if(abs(tpb)>dwb){
        int k =1;
        if (tpb<0)k=-1;
        k*=(abs(tpb)/dwb);
        tpb= abs(tpb)-(abs(tpb)/dwb)*dwb;
        printf("%d(%d/%d)",k,tpb,dwb);

    }
    else if (tpb != 0){
        printf("%d/%d",tpb,dwb);
    }

}
