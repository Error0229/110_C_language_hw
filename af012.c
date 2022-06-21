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
    
    do{
        int top=0,pt=0,down=0,tr=0;    
        scanf("%s%s%c%c%c%c",a,b,&nl,&ch,&nl,&ju);
        int tpa=0,dwa=0,tpb=0,dwb=0,*id,idk=0;
        id = &idk;
        tpa=todig(a,id);
		idk+=1;
		dwa=todig(a,id);
		idk=0;
		tpb=todig(b,id);
		idk+=1;
		dwb=todig(b,id);
		if (dwa == 0 || dwb == 0){
			puts("ERROR");
			continue;
		}
		int lcm = (dwa*dwb)/gcd(abs(dwa),abs(dwb));
		tpa*=(lcm/dwa);tpb*=(lcm/dwb);
		if (ch == '+'){
			top = tpa+tpb;
			down = lcm;
		}
		else if(ch == '/'){
			top = tpa;
			down = tpb;
		}
		else if(ch == '-'){
			top = tpa-tpb;
			down = lcm;
		}
		else{
			top = tpa * tpb;
			down = lcm*lcm;
		}
		int dec = gcd(abs(top),abs(down));
		dec = dec==0 ? 1:dec;
		top/=dec;down/=dec;
		tr=(top-(top%down))/down;
		if(down<1){
			down*=-1;
			top*=-1;
		}
		if (abs(top)>abs(down)){
			top-=tr*down;
			if (top<0){
				top*=-1;
			}
			if (down == 1 || top == 0)printf("%d\n",tr);
			else printf("%d(%d/%d)\n",tr,top,down);
		}
		else if (down == 1 || top == 0){
			printf("%d\n",tr);
		}
		else {
			printf("%d/%d\n",top,down);
		}
		
        
    }while(ju=='y');
    
}
