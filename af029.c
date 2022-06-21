#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
typedef struct process_s {
    int mac;
    int time;
} process_t;
typedef struct work_s {
    process_t process[105];
    int pcs_cnt;
    int pcs_tot;
    int pcs_time;
} work_t;
int main()
{
    int N, M, i, P, j, tot_time = 0, now, time_tmp, min_mac;
    process_t pcs_now;
    work_t work[105];
    int machine[105];
    memset(machine, 0, sizeof(machine));
    memset(work, 0, sizeof(work));
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &P);
        for (j = 0; j < P; j++) {
            scanf("%d %d", &work[i].process[j].mac, &work[i].process[j].time);
        }
        work[i].pcs_cnt = 0;
        work[i].pcs_tot = P;
        work[i].pcs_time = 0;
    }
    while (1) {
        int min_time = 1000000, min_work = -1, flag = 1;
        for (i = 0; i < M; i++) {
            if (work[i].pcs_cnt < work[i].pcs_tot)
                flag = 0;
        }
        if (flag)
            break;
        for (i = 0; i < M; i++) {
            if (work[i].pcs_cnt == work[i].pcs_tot)
                continue;
            now = work[i].pcs_cnt;
            pcs_now = work[i].process[now];
            time_tmp = pcs_now.time + max(work[i].pcs_time, machine[pcs_now.mac]);
            if (min_time > time_tmp) {
                min_time = time_tmp;
                min_work = i;
                min_mac = pcs_now.mac;
            }
        }
        machine[min_mac] = min_time;
        work[min_work].pcs_cnt++;
        work[min_work].pcs_time = min_time;
    }
    for (int i = 0; i < M; i++) {
        tot_time += work[i].pcs_time;
    }
    printf("%d\n", tot_time);
}