#include<stdio.h>
int check(int a, int b, int arr[5][105]){
    for(int i = 0 ; i < 100 ; i++){
        if (arr[a][i] == 1 && arr[b][i] == 1){
            return i;
        }
    }
    return -1;
}
int main(){
    int k,cls;
    int ar [5][105];
    for (int i = 0 ; i < 100 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            ar[j][i] = 0;
        }
    }
    for (int i = 0 ; i < 3 ; i++){
        scanf("%d",&ar[i][100]);
        scanf("%d",&k);
        for (int j = 0 ; j < k ; j++){
            scanf("%d",&cls);
            ar[i][cls]=1;
        }
    }
    int res = check(0,1,ar);
    if (res!=-1){
        printf("%d and %d conflict on %d\n",ar[0][100],ar[1][100],res);
        return 0;
    }
    res = check(0,2,ar);
    if (res!=-1){
        printf("%d and %d conflict on %d\n",ar[0][100],ar[2][100],res);
        return 0;
    }
    res = check(1,2,ar);
    if (res!=-1){
        printf("%d and %d conflict on %d\n",ar[1][100],ar[2][100],res);
        return 0;
    }
    return 0;
}

