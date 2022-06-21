#include <stdio.h>

int main()
{
    int savep[9];
    int rotate_map_f[9] = { 6, 3, 0, 7, 4, 1, 8, 5, 2 };
    int rotate_map_b[9] = { 2, 5, 8, 1, 4, 7, 0, 3, 6 };
    int rubix[7][9] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2 },
        { 3, 3, 3, 3, 3, 3, 3, 3, 3 },
        { 4, 4, 4, 4, 4, 4, 4, 4, 4 },
        { 5, 5, 5, 5, 5, 5, 5, 5, 5 },
        { 6, 6, 6, 6, 6, 6, 6, 6, 6 }
    };
    int n, k, tp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        if (k == 10) {
            for (int i = 0; i < 3; i++) {
                tp = rubix[3][8 - 3 * i];
                rubix[3][8 - 3 * i] = rubix[1][3 * i];
                rubix[1][3 * i] = rubix[4][3 * i];
                rubix[4][3 * i] = rubix[6][3 * i];
                rubix[6][3 * i] = tp;
            }
            for (int i = 0; i < 9; i++)
                savep[i] = rubix[5][i];
            for (int i = 0; i < 9; i++) {
                rubix[5][i] = savep[rotate_map_b[i]];
            }
        }
        if (k == 11) {
            for (int i = 0; i < 3; i++) {
                tp = rubix[3][7 - 3 * i];
                rubix[3][7 - 3 * i] = rubix[1][1 + 3 * i];
                rubix[1][1 + 3 * i] = rubix[4][1 + 3 * i];
                rubix[4][1 + 3 * i] = rubix[6][1 + 3 * i];
                rubix[6][1 + 3 * i] = tp;
            }
        }
        if (k == 12) {
            for (int i = 0; i < 3; i++) {
                tp = rubix[3][6 - 3 * i];
                rubix[3][6 - 3 * i] = rubix[1][2 + 3 * i];
                rubix[1][2 + 3 * i] = rubix[4][2 + 3 * i];
                rubix[4][2 + 3 * i] = rubix[6][2 + 3 * i];
                rubix[6][2 + 3 * i] = tp;
            }
            for (int i = 0; i < 9; i++)
                savep[i] = rubix[2][i];
            for (int i = 0; i < 9; i++) {
                rubix[2][i] = savep[rotate_map_f[i]];
            }
        }
        if (k == 20) {
            for (int i = 0; i < 3; i++) {
                tp = rubix[5][i];
                rubix[5][i] = rubix[4][i];
                rubix[4][i] = rubix[2][i];
                rubix[2][i] = rubix[3][i];
                rubix[3][i] = tp;
            }

            for (int i = 0; i < 9; i++)
                savep[i] = rubix[1][i];
            for (int i = 0; i < 9; i++) {
                rubix[1][i] = savep[rotate_map_f[i]];
            }
        }
        if (k == 21) {
            for (int i = 3; i < 6; i++) {
                tp = rubix[5][i];
                rubix[5][i] = rubix[4][i];
                rubix[4][i] = rubix[2][i];
                rubix[2][i] = rubix[3][i];
                rubix[3][i] = tp;
            }
        }
        if (k == 22) {
            for (int i = 6; i < 9; i++) {
                tp = rubix[5][i];
                rubix[5][i] = rubix[4][i];
                rubix[4][i] = rubix[2][i];
                rubix[2][i] = rubix[3][i];
                rubix[3][i] = tp;
            }
            for (int i = 0; i < 9; i++)
                savep[i] = rubix[6][i];
            for (int i = 0; i < 9; i++) {
                rubix[6][i] = savep[rotate_map_b[i]];
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        printf("%d ", rubix[1][i]);
        if (i % 3 == 2)
            puts("");
    }
    return 0;
}

// 10 表示直欄(column)最左邊向前轉一次。
// 11 表示直欄(column)中間向前轉一次。
// 12 表示直欄(column)最右邊向前轉一次。
// 20 表示橫列(row)最上面向左轉一次。
// 21 表示橫列(row)中間向左轉一次。
// 22 表示橫列(row)最下面向左轉一次。