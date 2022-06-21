#include<stdio.h>
void f(int now , int* pts){
	if (now<=1){
		return;
	}
	else if(now&1){
		*pts+=1;
		f((now+1)/2,pts);
	}
	else{
		*pts+=1;
		f(now/2,pts);
	}
	return;
}

int main(){
    int cnt=0,n;
    char ch[20];
    int ans[150];
    do{
    	int k=0,pt=0;	
        scanf("%s",ch);
        int *pts;
        for (int i=0;i<8;i++){
        	if (ch[i]=='1'){
        		k+=(1<<(7-i));
			}
		}
		pts=&pt;
		f(k,pts);
		ans[cnt++]=*pts;
		scanf("%d",&n);
	}while(n!=-1);
	for(int i=0;i<cnt;i++){
		int k=ans[i];
		for (int j=3;j>=0;j--){
			if (k>=(1<<j)){
				printf("1");
				k-=(1<<j);
			}
			else{
				printf("0");
			}
		}
		puts("");
		
	}
}
