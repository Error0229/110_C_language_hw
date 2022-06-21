#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
    char* __word;
    int __count;
};
int cmp(const void* a, const void* b)
{
    int ac = ((struct data*)a)->__count, bc = ((struct data*)b)->__count;
    char *acp = ((struct data*)a)->__word, *bcp = ((struct data*)b)->__word;
    return ac == bc ? (strlen(acp) == strlen(bcp) ? strcmp(acp, bcp) : strlen(acp) - strlen(bcp))
                    : bc - ac;
}
int main()
{
    char strs[500][100];
    char s[500], P[50], Q[50];
    memset(strs, 0, sizeof(strs));
    memset(s, 0, sizeof(s));
    memset(P, 0, sizeof(P));
    memset(Q, 0, sizeof(Q));
    gets(s);
    char dlm[2] = " ";
    char* tok;
    tok = strtok(s, dlm);
    int id = 0;
    while (tok != NULL) {
        strcpy(strs[id++], tok);
        tok = strtok(NULL, dlm);
    }
    gets(P);
    gets(Q);
    for (int i = 0; i < id; i++) {
        if (strcmp(strs[i], P) == 0) {
            printf("%s ", Q);
        } else {
            printf("%s ", strs[i]);
        }
    }
    puts("");
    for (int i = 0; i < id; i++) {
        if (strcmp(strs[i], P) == 0) {
            printf("%s ", Q);
        }
        printf("%s ", strs[i]);
    }
    puts("");
    for (int i = 0; i < id; i++) {
        if (strcmp(strs[i], P) == 0) {
            continue;
        }
        printf("%s ", strs[i]);
    }
    puts("");
    struct data __data[100];
    int flag[100], ord = 0;
    memset(flag, 0, sizeof(flag));
    memset(__data, 0, sizeof(__data));
    for (int i = 0; i < id; i++) {
        if (flag[i] == 1)
            continue;
        __data[ord].__word = strs[i];
        __data[ord].__count = 1;
        for (int j = i + 1; j < id; j++) {
            if (strcmp(strs[i], strs[j]) == 0) {
                __data[ord].__count++;
                flag[j] = 1;
            }
        }
        ord++;
    }
    qsort(__data, ord, sizeof(struct data), cmp);
    for (int i = 0; i < ord; i++) {
        printf("%s %d\n", __data[i].__word, __data[i].__count);
    }
    return 0;
}