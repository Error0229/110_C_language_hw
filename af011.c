#include<stdio.h>
int f(int now ,int arr[512]){

	if (arr[now]!=0){
		return arr[now];
	}
    if (now<=1){
        return 0;
    }
    else if(now&1){
    	arr[now]+=1+f((now+1)/2,arr);
    }
    else{
        arr[now]+=1+f(now/2,arr);
    }
    return arr[now];
}

int main(){
    int cnt=0,n;
    char ch[20];
    int ans[150],arr[512];
    for(int i= 0 ; i < 512;i++)arr[i]=0;
    do{
        int k=0,pt=0;    
        scanf("%s",ch);
        int *pts;
        for (int i=0;i<8;i++){
            if (ch[i]=='1'){
                k+=(1<<(7-i));
            }
        }
        for(int j= 1 ;j<=k;j++){
        	pt+=f(j,arr);
		}
        ans[cnt++]=pt;
        scanf("%d",&n);
    }while(n!=-1);
    for(int i=0;i<cnt;i++){
        int k=ans[i];
        for (int j=10;j>=0;j--){
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
