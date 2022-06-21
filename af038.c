#include<stdio.h>
#include<stdlib.h>

typedef struct info_s{
    char name[30];
    int age, year, month, day;
}info_t;

typedef struct node_s {
    info_t info;
    struct node_s* next;
}node_t;


node_t* new_node(info_t info) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->info = info;
    node->next = NULL;
    return node;
}

void push(node_t* head, info_t info) {
    node_t* next_node = head->next;
    node_t* info_node = new_node(info);
    head->next = info_node;
    info_node->next = next_node;
}

info_t pop(node_t* head) {
    info_t info = head->next->info;
    node_t* temp = head->next->next;
    free(head->next);
    head->next = temp;
    return info;
}

void info_scan(info_t* info) {
    scanf("%s%d%d%d%d", info->name, &info->age, &info->year, &info->month, &info->day);
}

int count(node_t* head){
    int cnt = 0;
    while(head->next!=NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void print_list(node_t* head) {
    if (head->next == NULL) {
        puts("The Stack is empty");
    }
    else {
        node_t* current = head->next;
        info_t info = current->info;
        do {
            info = current->info;
            printf("%s ", info.name);
            printf("%d ", info.age);
            printf("%d_%d_%d\n", info.year, info.month, info.day);
            current = current->next;
        } while (current!=NULL);
    }
}

int main(){
    info_t none, info;
    node_t* head = new_node(none);
    int flag = 1, ins, var;
    while(flag){
        scanf("%d", &ins);
        switch(ins){
            case 1 :
                info_scan(&info);
                push(head,info);
                break;
            case 2 :
                scanf("%d", &var);
                if(head->next == NULL){
                    puts("The Stack is empty");
                    break;
                }
                info = pop(head);
                switch(var) {
                    case 1 :
                        printf("%s\n", info.name);
                        break;
                    case 2 :
                        printf("%d\n", info.age);
                        break;
                    case 3 :
                        printf("%d_%d_%d\n", info.year, info.month, info.day);
                        break;
                    default :
                        break;
                }
                break;
            case 3 :
                if(head->next == NULL){
                    puts("The Stack is empty");
                    break;
                }
                while(head->next != NULL){
                    info = pop(head);
                    printf("%s ", info.name);
                    printf("%d ", info.age);
                    printf("%d_%d_%d\n", info.year, info.month, info.day);
                }
                break;
            case 4 :
                print_list(head);
                break;
            case 5 :
                flag = 0;
                printf("%d\n",count(head));
                break;
            default :
                break;
        }  
    }       
    
    return 0;
}
