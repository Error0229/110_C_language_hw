#include<stdio.h>
#include<string.h>
int main(){
    char ans[10],ipt[10];
    int crt=0,rp=0,flag = 0;
    scanf("%s",ans);
    while(flag<6){
        crt=0,rp=0;
        scanf("%s",ipt);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if (ans[i]==ipt[j]){
                    if(i==j)crt++;
                    else rp++;
                }
            }
        }
        if(crt==4){
            puts("win");
            flag = 229;
        }
        else{
            printf("%dA%dB\n",crt,rp);
        }
        flag++;
    }
	return 0;
}
