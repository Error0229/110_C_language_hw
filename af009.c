#include<stdio.h>
#include<string.h>

int main(){
    int n,k,jg;
    do{
		scanf("%d%d%d",&n,&k,&jg)
        char s[20];
        memset(s,0,sizeof(s));
        for(int i = 0 ; i < n ; i++){
            s[n-i-1] = (char)(((k^(k>>1))&1)+'0');
            k>>=1;
        }
		puts(s);
        
    }while(jg!=-1);
    return 0;
}
