#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s {
    char ch;
    struct node_s *ls, *rs;
} node_t;
node_t* new_node(char ch)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->ch = ch;
    node->ls = NULL;
    node->rs = NULL;
    return node;
}
node_t* build_PI(char* P, char* I, int now, int begin, int end)
{
    int root_id = begin;
    char c = P[now];
    node_t* root = new_node(c);
    while (root_id <= end && I[root_id] != c)
        root_id++;
    if (root_id != begin)
        root->ls = build_PI(P, I, now + 1, begin, root_id - 1);
    if (root_id != end)
        root->rs = build_PI(P, I, now + 1 + (root_id - begin), root_id + 1, end);
    return root;
}

node_t* build_OI(char* O, char* I, int now, int begin, int end)
{
    int root_id = begin;
    char c = O[now];
    node_t* root = new_node(c);
    while (root_id >= end && I[root_id] != c)
        root_id--;
    if (root_id != begin)
        root->rs = build_OI(O, I, now - 1, begin, root_id + 1);
    if (root_id != end)
        root->ls = build_OI(O, I, now - 1 - (begin - root_id), root_id - 1, end);
    return root;
}

void print_tree(node_t* root, int n)
{
    node_t* arr[100], *node_now;
    int now = 0, tail = 1;
    arr[0] = root;
    for(now = 0; now < n; now++){
        node_now = arr[now];
        if(node_now->ls != NULL)arr[tail++] = node_now->ls;
        if(node_now->rs != NULL)arr[tail++] = node_now->rs;
        printf("%c", node_now->ch); 
    }
    puts("");
    
}
int main()
{
    char c, P[100], I[100], O[100];
    int p = 0, i = 0, o = 0, k = 0;
    node_t* root = NULL;
    for (k = 0; k < 2; k++) {
        c = getchar();
        getchar();
        switch (c) {
        case 'P':
            p = 1;
            gets(P);
            break;
        case 'I':
            i = 1;
            gets(I);
            break;
        case 'O':
            o = 1;
            gets(O);
            break;
        }
    }
    int len = (int)strlen(I);
    if (p & i)
        root = build_PI(P, I, 0, 0, len - 1);
    else if (o & i)
        root = build_OI(O, I, len - 1, len - 1, 0);
    print_tree(root, len);
}
