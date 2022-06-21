#include<stdio.h>
#include<string.h>
void rec(int n,int offx,int offy,int ans[],int ori_n){
    char c = getchar();
    if(c =='2'){
        rec(n/2,offx,offy,ans,ori_n);
        rec(n/2,offx,offy+(n/2),ans,ori_n);
        rec(n/2,offx+(n/2),offy,ans,ori_n);
        rec(n/2,offx+(n/2),offy+(n/2),ans,ori_n);
    }
    else if(c == '1'){
        for(int i = offx; i < offx+n; i++){
            for(int j = offy; j < offy+n; j++){
                ans[ori_n*i+j] = 1;
            }
        }
    }
    return;
}
int main(){
    char c;
    while((c=getchar()) && c!='\n');
    int n=0,flag=0;
    int ans[500000];
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    rewind(stdin);        // something wont work with keyboard input
    rec(n,0,0,ans,n);
    for(int i = 0;i< 500000;i++){
        if(ans[i]){
            printf("%d,%d\n",i/n,i%n);
            flag=1;
        }
    }
    if(!flag){
        puts("all white");
    }
    return 0;
}