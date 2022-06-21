#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int m = (k+1)/2;
    for (int i = 1 ; i <= k ; i++){
            for(int j = 0 ; j < abs(i-m) ; j++){
                printf(n & 2 ? ".":"");
            }
            for(int j = 0 ; j < m-abs(i-m) ; j++){
                    printf(((n & 1) ^ ((n & 2)>>1) ) || (j == 0)? "*":"**");
            }
            puts("");
    }
    return 0;
}
