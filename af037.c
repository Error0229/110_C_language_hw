#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
    int data;
    struct node_s* next;
}node_t;

node_t* new_node(int data) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_front(node_t* head, int data) {
    node_t* next_node = head->next;
    node_t* data_node = new_node(data);
    head->next = data_node;
    data_node->next = next_node;
}

void insert_back(node_t* head, int data) {
    node_t* current = head;
    node_t* data_node = new_node(data);
    while (current->next!=NULL) {
        current = current->next;
    }
    current->next = data_node;
}

void add_by_order(node_t* head, int order, int data) {
    node_t* current = head;
    int cnt = -1;
    while (cnt != order) {
        if (current->next == NULL) {
            current->next = new_node(0);
        }
        current = current->next;
        cnt++;
    }
    current->data += data;
}

void poly_input(node_t* head) {
    int i, x = 0, neg = 0, flag = 0;
    char s[100], c;
    gets(s);
    for(i = 0; s[i]!='\0'; i++){
        c = s[i];
        if (c == '-') neg = 1;
        if ('0' <= c && c <= '9') x = x * 10 + (c ^ '0'), flag = 1;
        if (('0' > c || c > '9') && flag) {
            if(neg) x = -x;
            insert_front(head,x);
            flag = neg = x = 0;
        }
    } 
    if(flag){
        if(neg) x = -x;
        insert_front(head,x);
    }
}

void list_clear(node_t* head) {
    node_t* prev = NULL;
    node_t* current = head->next;
    while (current!=NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
    head->next = NULL;
}
void poly_plus(node_t* p1, node_t* p2, node_t* res) {
    list_clear(res);
    node_t* c1 = p1->next;
    node_t* c2 = p2->next;
    node_t* r = res;
    int c1_d, c2_d;
    do {
        c1_d = c1 == NULL ? 0 : c1->data;
        c2_d = c2 == NULL ? 0 : c2->data;
        insert_back(r, c1_d + c2_d);
        if(c1 != NULL) c1 = c1->next;
        if(c2 != NULL) c2 = c2->next;
    } while (c1!=NULL || c2 !=NULL);
}

void poly_mul(node_t* p1, node_t* p2, node_t* res) {
    list_clear(res);
    node_t* c1 = p1->next;
    node_t* c2 = p2->next;
    node_t* r = res;
    int c1_d, c2_d, i, j;
    for (i = 0, c1 = p1->next; c1 != NULL; i++, c1 = c1->next) {
        c1_d = c1->data;
        for (j = 0, c2 = p2->next; c2!= NULL; j++, c2 = c2->next) {
            c2_d = c2->data;
            add_by_order(r, i + j, c1_d * c2_d);
        }
    }
}

void poly_sub(node_t* p1, node_t* p2, node_t* res) {
    list_clear(res);
    node_t* c1 = p1->next;
    node_t* c2 = p2->next;
    node_t* r = res;
    int c1_d, c2_d;
    do {
        c1_d = c1 == NULL ? 0 : c1->data;
        c2_d = c2 == NULL ? 0 : c2->data;
        insert_back(r, c1_d - c2_d);
        if(c1 != NULL) c1 = c1->next;
        if(c2 != NULL) c2 = c2->next;
    } while (c1!=NULL || c2 !=NULL);
}

void rec_print_poly(node_t* cur, int power,int *f){
    if (cur != NULL) {
        rec_print_poly(cur->next, power + 1, f);
        int val = cur->data;
        if (cur->next != NULL && val > 0 && (*f)) printf("+");
        (*f) |= val;
        if (val == -1 && power > 0) printf("-");
        if (abs(val) > 1 || (abs(val)>0 && power  == 0)) printf("%d",val);
        if (val != 0 && power > 0) printf("x");
        if (val != 0 && power > 1) printf("^%d",power);
    }
}

void poly_print(node_t* poly) { //actually i dont want to do this
    int flag = 0;
    rec_print_poly(poly->next,0,&flag);
    if(flag == 0) printf("0");
    printf("\n");
}

int main(){
    node_t* poly_1 = new_node(-1);
    node_t* poly_2 = new_node(-1);
    node_t* result = new_node(-1);
    
    poly_input(poly_1);
    poly_input(poly_2);
    
    poly_plus(poly_1, poly_2, result);
    poly_print(result);
    
    poly_sub(poly_1, poly_2, result);
    poly_print(result);
    
    poly_mul(poly_1, poly_2, result);
    poly_print(result);
    
    return 0;
}
