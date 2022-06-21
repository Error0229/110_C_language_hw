#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int savep[9];
    int rotate_map_b[3][9] = { { 2, 5, 8, 1, 4, 7, 0, 3, 6 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 6, 3, 0, 7, 4, 1, 8, 5, 2 } };
    int rubix[7][9];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 9; j++) {
            rubix[i][j] = i;
        }
    }
    int map1[4] = { 3, 1, 4, 6 };
    int map2[4] = { 5, 4, 2, 3 };
    int n, k, tp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        if (k / 10 == 1) {
            int off = k % 10;
            for (int i = 0; i < 3; i++) {
                swap(&rubix[map1[0]][8 - off - 3 * i], &rubix[map1[1]][3 * i]);
                swap(&rubix[map1[1]][3 * i], &rubix[map1[2]][3 * i]);
                swap(&rubix[map1[2]][3 * i], &rubix[map1[3]][3 * i]);
            }
            if (off != 1) {
                for (int i = 0; i < 9; i++)
                    savep[i] = rubix[map2[off]][i];
                for (int i = 0; i < 9; i++) {
                    rubix[map2[off]][i] = savep[rotate_map_b[off][i]];
                }
            }
        } else {
            int off = k % 10;
            for (int i = 0; i < 3; i++) {
                swap(&rubix[map2[0]][i + 3 * off], &rubix[map2[1]][i + 3 * off]);
                swap(&rubix[map2[1]][i + 3 * off], &rubix[map2[2]][i + 3 * off]);
                swap(&rubix[map2[2]][i + 3 * off], &rubix[map2[3]][i + 3 * off]);
            }
            if (off != 1) {
                for (int i = 0; i < 9; i++)
                    savep[i] = rubix[map1[off + 1]][i];
                for (int i = 0; i < 9; i++) {
                    rubix[map1[off + 1]][i] = savep[rotate_map_b[2 - off][i]];
                }
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