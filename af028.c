#include <stdio.h>
#include <string.h>
typedef struct player_s {
    int id;
    char per[105];
    int pacnt;
    int hits;
    int score;
} player_t;
int main()
{
    player_t player[105];
    int i, j, k, m, scores = 0, outs = 0, out = 0, nowplay = 1, pa, cnt;
    char c;
    for (i = 1; i <= 9; i++) {
        player[i].id = i;
        memset(player[i].per, 0, sizeof(player[i].per));
        scanf("%d", &m);
        getchar();
        for (j = 1; j <= m; j++) {
            c = getchar();
            player[i].per[j] = c;
            getchar();
        }
        player[i].pacnt = 1;
        player[i].hits = 0;
        player[i].score = 0;
    }
    scanf("%d", &k);
    int base[5] = { 0, 0, 0, 0, 0 };

    while (1) {
        cnt = player[nowplay].pacnt++;
        pa = player[nowplay].per[cnt];
        switch (pa) {
        case '1':
            player[base[3]].score++;
            player[nowplay].hits++;
            base[3] = base[2];
            base[2] = base[1];
            base[1] = nowplay;
            break;
        case '2':
            player[base[3]].score++;
            player[base[2]].score++;
            player[nowplay].hits++;
            base[3] = base[1];
            base[2] = nowplay;
            base[1] = 0;
            break;
        case '3':
            player[base[3]].score++;
            player[base[2]].score++;
            player[base[1]].score++;
            player[nowplay].hits++;
            base[3] = nowplay;
            base[2] = 0;
            base[1] = 0;
            break;
        case 'H':
            player[base[3]].score++;
            player[base[2]].score++;
            player[base[1]].score++;
            player[nowplay].score++;
            player[nowplay].hits++;
            base[3] = base[2] = base[1] = 0;
            break;
        case 'O':
            out++;
            outs++;
            if (out == 3) {
                out = 0;
                base[3] = base[2] = base[1] = 0;
            }
            break;
        default:
            break;
        }
        if (outs == k) {
            break;
        }
        nowplay++;
        if (nowplay > 9) {
            nowplay = 1;
        }
    }
    for (i = 1; i <= 9; i++) {
        scores += player[i].score;
    }
    printf("%d\n", scores);
    for (i = 1; i <= 9; i++) {
        printf("%d %d %d\n", player[i].id, player[i].hits, player[i].score);
    }
    return 0;
}