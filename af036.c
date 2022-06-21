#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
    int data;
    struct node_s* next;
}node_t;

node_t* new_node(int data){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_front(node_t* head, int data){
    node_t* next_node = head->next;
    node_t* data_node = new_node(data);
    head->next = data_node;
    data_node->next = next_node;
}

void insert_back(node_t* head, int data){
    node_t* current = head;
    node_t* data_node = new_node(data);
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = data_node;
}

void insert_after_target(node_t* head, int target, int data){
    node_t* current = head;
    while(current->next!= NULL && current->data != target){
        current = current->next;
    }
    if(current->data == target){
        node_t* data_node = new_node(data);
        data_node->next = current->next;
        current->next = data_node;
    }
}

void remove_target(node_t* head, int target)
{
    node_t* current = head;
    node_t* prev = NULL;
    while(current->next!= NULL && current->data != target){
        prev = current;
        current = current->next;
    }
    if(current->data == target){
        prev->next = current->next;
        free(current);
    }
}

void remove_first(node_t* head){
    if(head->next!=NULL){
        node_t* temp = head->next->next;
        free(head->next);
        head->next = temp;
    } 
}
void remove_back(node_t* head){
    node_t* current = head;
    node_t* prev = NULL;
    if(current->next!=NULL){
        while(current->next!=NULL){
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
    }
}
void print_list(node_t* head){
    if(head->next == NULL){
        puts("None any node");
    }
    else{
        node_t* current = head->next;
        do{
            printf("%d ",current->data);
            current = current->next;
        }while(current!=NULL);
        puts("");
    }
}
int main(){
    node_t* head = new_node(-1);
    int n, k, i, ins, x, y;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &k);
        insert_back(head, k);
    }
    int flag = 1;
    while(flag){
        scanf("%d", &ins);
        switch(ins){
            case 1 :
                scanf("%d", &x);
                insert_back(head, x);
                break;
            case 2 :
                scanf("%d%d", &x, &y);
                insert_after_target(head, x, y);
                break;
            case 3 :
                scanf("%d", &x);
                remove_target(head, x);
                break;
            case 4 :
                remove_first(head);
                break;
            case 5 :
                remove_back(head);
                break;
            case 6 :
                flag = 0;
                print_list(head);
                break;
            default :
                break;
        }  
    }       
    return 0;
}
