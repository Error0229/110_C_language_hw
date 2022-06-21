#include<stdio.h>
int main(){
    double month_fee[3][6]={{183, 0.08, 0.1393, 0.1349, 1.1287, 1.4803}, {383, 0.07, 0.1304, 0.1207, 1.1127, 1.2458}, {983, 0.06, 0.1087, 0.1018, 0.9572, 1.1243}};
    double nal_v,net_v,cal_v,nal_m,net_m;
    int total = 1e9,best_plan = 0;
    scanf("%lf%lf%lf%lf%lf",&nal_v,&net_v,&cal_v,&nal_m,&net_m);
    for(int i = 0 ; i < 3 ; i++ ){
        int fees = (int)(nal_v*month_fee[i][1]+net_v*month_fee[i][2]+cal_v*month_fee[i][3]+nal_m*month_fee[i][4]+net_m*month_fee[i][5]);
        fees = month_fee[i][0] > fees ? month_fee[i][0] : fees;
        if (fees < total){
            total = fees;
            best_plan = month_fee[i][0];
        }

    }
    printf("%d\n",best_plan);

    return 0;
}

