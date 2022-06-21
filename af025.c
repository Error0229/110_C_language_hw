#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    lower,
    upper,
};
int main()
{
    char s[1000];
    int temp[1000];
    memset(temp, 0, sizeof(temp));
    int k = 0, id = 0, type, count = 1;
    scanf("%d", &k);
    getchar();
    gets(s);
    type = (islower(s[0]) ? lower : upper);
    for (int i = 1; i < (int)strlen(s); i++) {
        if ((type == lower && isupper(s[i])) || (type == upper && islower(s[i]))) {
            temp[id++] = count;
            count = 1;
            type = !type;
        } else {
            count++;
        }
    }

    temp[id++] = count;
    count = 0;
    int maxlen = 0;
    for (int i = 0; i < id; i++) {
        if (temp[i] >= k) {
            count++;
        }
        if (count != 0 && temp[i] != k) {
            maxlen = maxlen > count ? maxlen : count;
            count = 0;
            if (temp[i] > k) {
                count++;
            }
        }
    }
    maxlen = maxlen > count ? maxlen : count;
    printf("%d\n", maxlen * k);
}