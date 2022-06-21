#include <stdio.h>
#include <stdlib.h>

typedef struct info_s {
    char name[25];
    int age;
    int year;
    int month;
    int day;
} info_t;
typedef struct node_s {
    info_t info;
    struct node_s* next;
} node_t;
node_t* newnode(info_t info)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->info = info;
    node->next = NULL;
    return node;
}
void push(node_t** head, node_t** tail, info_t info)
{
    node_t* node = newnode(info);
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}
info_t pop(node_t** head, node_t** tail, int* flag)
{
    info_t info;
    if (*head == NULL) {
        *flag = 1;
        return info;
    }
    node_t* node = *head;
    info = node->info;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(node);
    return info;
}
void clear(node_t** head, node_t** tail, int* flag)
{
    if (*head == NULL) {
        *flag = 1;
        return;
    }
    node_t* node = *head;
    while (node != NULL) {
        printf("%s %d %d_%d_%d\n", node->info.name, node->info.age, node->info.year, node->info.month, node->info.day);
        *head = (*head)->next;
        free(node);
        node = *head;
    }
    *tail = NULL;
}
int count(node_t** head){
    int cnt = 0;
    node_t* node = *head;
    while (node != NULL) {
        cnt++;
        node = node->next;
    }
    return cnt;
}
void print_all (node_t** head, int* flag) {
    if (*head == NULL){
        *flag = 1;
        return;
    }
    node_t* node = *head;
    while (node != NULL) {
        printf("%s %d %d_%d_%d\n", node->info.name, node->info.age, node->info.year, node->info.month, node->info.day);
        node = node->next;
    }
}
int main()
{
    node_t *head = NULL, *tail = NULL;
    info_t info;
    int cmd, type, flag;
    while (1) {
        flag = 0;
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                scanf("%s %d %d %d %d", info.name, &info.age, &info.year, &info.month, &info.day);
                push(&head, &tail, info);
                break;
            case 2:
                info = pop(&head, &tail, &flag);
                scanf("%d", &type);
                if (flag)
                    puts("The Queue is empty");
                else {
                    switch (type) {
                        case 1:
                            printf("%s\n", info.name);
                            break;
                        case 2:
                            printf("%d\n", info.age);
                            break;
                        case 3:
                            printf("%d_%d_%d\n", info.year, info.month, info.day);
                            break;
                    }
                }
                break;
            case 3:
                clear(&head, &tail, &flag);
                if (flag) {
                    puts("The Queue is empty");
                }
                break;
            case 4:
                print_all(&head, &flag);
                if (flag) {
                    puts("The Queue is empty");
                }
                break;
            case 5:
                printf("%d", count(&head));
                exit(0);
        }
    }
}