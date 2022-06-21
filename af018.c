#include<stdio.h>
#include<string.h>
int main(){
    char str[500];
    int arr[500],m,ans=0,dec_set[20];
    memset(arr,0,sizeof(arr));
    memset(str,0,sizeof(str));
    memset(dec_set,0,sizeof(dec_set));
    
    scanf("%s%d",str,&m);
    int s_len = (int)strlen(str);

    for(int i=0;i<s_len;i++){
        arr[i+1] = str[i]-'0';
    }
    for(int i = 1; i <= m - 1;i++){ 
        dec_set[arr[i]] += 1;
    }
    for(int i = m ; i <= s_len ; i++){
        dec_set[arr[i]] += 1;
        int flag = 0;
        for(int j = 0 ; j < 10 ; j++){
            if (dec_set[j] > 1 ){
                flag = 1;
            }
        }
        if (flag == 0){
            ans++;
        }
        dec_set[arr[i-m+1]] -= 1;
        
    }
    printf("%d\n",ans);
}