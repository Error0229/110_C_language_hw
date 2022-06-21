#include <stdio.h>
#include <string.h>
typedef struct task_s {
    int pTask[105];
    int pNo;
    int day;
    int able;
} task_t;
task_t input(int i)
{
    int j, m;
    task_t tk;
    memset(tk.pTask, 0, sizeof(tk.pTask));
    tk.pNo = i;
    scanf("%d", &tk.day);
    scanf("%d", &m);
    for (j = 1; j <= m; j++) {
        scanf("%d", &tk.pTask[j]);
    }
    if (m == 0)
        tk.able = 1;
    else
        tk.able = 0;
    return tk;
}
void solve()
{
    task_t task[105];
    int i, k, ans = 0, min_id, min_day;
    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        task[i] = input(i);
    }
    while (1) {
        min_id = 0, min_day = 1000000000;
        for (i = 1; i <= k; i++) {
            if (task[i].able == 1 && task[i].day < min_day) {
                min_id = i;
                min_day = task[i].day;
            }
        }
        if (min_id == 0)
            break;
        ans += min_day;
        for (int i = 1; i <= k; i++) {
            if (task[i].able == 1) {
                task[i].day -= min_day;
            }
        }
        task[min_id].able = -1;
        for (i = 1; i <= k; i++) {
            if (task[i].able == 0) {
                int id = 1, flag = 1;
                while (task[i].pTask[id] != 0) {
                    if (task[i].pTask[id] == min_id) {
                        task[i].pTask[id] = -1;
                    }
                    if (task[i].pTask[id] > 0)
                        flag = 0;
                    id++;
                }
                if (flag)
                    task[i].able = 1;
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        solve();
    }
    return 0;
}