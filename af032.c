#include <stdio.h>
#include <stdlib.h>
typedef struct data_s {
    int info[100];
    int cnt;
} data_t;
int cmp(const void* a, const void* b)
{
    data_t* x = (data_t*)a;
    data_t* y = (data_t*)b;
    int xc = x->cnt;
    int yc = y->cnt;
    int i = 0;
    for (i = 1; i <= xc && i <= yc; i++) {
        if (x->info[i] != y->info[i])
            return x->info[i] - y->info[i];
    }
    return xc - yc;
}
int main()
{
    int n, m, j, i;
    data_t data[1000];
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        data[i].cnt = m;
        for (j = 1; j <= data[i].cnt; j++) {
            scanf("%d", &data[i].info[j]);
        }
    }
    qsort(data + 1, n, sizeof(data_t), cmp);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= data[i].cnt; j++) {
            printf("%d ", data[i].info[j]);
        }
        printf("\n");
    }
}