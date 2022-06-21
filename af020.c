#include<stdio.h>
int main(){
    int n;
    int arr[5][3];
    scanf("%d,",&n);
    for(int i=0;i<4;i++){
        arr[i][0] = 1;
        arr[i][1] = 2;
        arr[i][2] = 4;
    }
    int k;
    for(int t=0;t<n;t++){
        for(int i=0;i<4;i++){
            scanf("%d",&k);
            if(k == 1){
                int temp = 7 - arr[i][0];
                arr[i][0] = arr[i][2];
                arr[i][2] = temp;
            }
            else if(k == 2){
                int temp = 7 - arr[i][2];
                arr[i][2] = arr[i][0];
                arr[i][0] = temp;
            }
            else if(k == 3){
                int temp = 7 - arr[i][1];
                arr[i][1] = arr[i][0];
                arr[i][0] = temp;
            }
            else if(k == 4){
                int temp = 7 - arr[i][0];
                arr[i][0] = arr[i][1];
                arr[i][1] = temp;
            }
            // printf("%d ",arr[i][0]);
        }
        // puts("");
    }
    
    int ans[7] = {0};
    for (int i=0;i<4;i++){
        ans[arr[i][0]]++;
    }
    int mn = 0,flag=0,tmp=0;
    for(int i=1;i<=6;i++){
        if(ans[i]==4){
            puts("18");
            return 0;
        }
        if(ans[i]==2){
            if(flag)flag=6;
            flag += i;
            
        }
        else if(ans[i]==1){
            tmp+=i;
        }
        mn = (ans[i]>mn)?ans[i]:mn;
    }
    if(mn == 1 || mn == 3){
        puts("0");
        return 0;
    }
    if(flag > 6){
        printf("%d\n",2*flag-12);
        return 0;
    }
    printf("%d\n",tmp);
    return 0;

}