#include <stdio.h>
#include <stdlib.h>
typedef struct gate_s {
    int *input_a, *input_b, *output;
    int (*operation)(struct gate_s*);
} gate_t;
int gate_and(gate_t* g)
{
    return (*g->input_a) & (*g->input_b);
}
int gate_or(gate_t* g)
{
    return (*g->input_a) | (*g->input_b);
}
int gate_xor(gate_t* g)
{
    return (*g->input_a) ^ (*g->input_b);
}
int gate_not(gate_t* g)
{
    return !(*g->input_a);
}
int gate_empty(gate_t* g)
{
    return *g->input_a;
}
gate_t* gate_init(int* input_a, int* input_b, int (*operation)(gate_t*))
{
    gate_t* g = (gate_t*)malloc(sizeof(gate_t));
    g->input_a = input_a;
    g->input_b = input_b;
    g->output = (int*)malloc(sizeof(int));
    g->operation = operation;
    return g;
}

int (*check(char c))(gate_t*)
{
    switch (c) {
    case 'A':
        return gate_and;
    case 'O':
        return gate_or;
    case 'X':
        return gate_xor;
    case 'N':
        return gate_not;
    case 'E':
        return gate_empty;
    }
    return NULL;
}
int main()
{
    int I1, I2, I3, I4, O1, O2, O3;
    char s[20];
    gets(s);
    I1 = s[0] - '0';
    I2 = s[2] - '0';
    I3 = s[4] - '0';
    I4 = s[6] - '0';
    gets(s);
    gate_t* A = gate_init(&I1, &I2, check(s[0]));
    *A->output = A->operation(A);

    gate_t* B = gate_init(A->output, NULL, check(s[2]));
    gate_t* C = gate_init(A->output, &I3, check(s[4]));
    *B->output = B->operation(B);
    *C->output = C->operation(C);

    gate_t* D = gate_init(B->output, C->output, check(s[6]));
    gate_t* E = gate_init(C->output, &I4, check(s[8]));
    *D->output = D->operation(D);
    *E->output = E->operation(E);

    gate_t* F = gate_init(D->output, E->output, check(s[10]));
    *F->output = F->operation(F);

    O1 = *B->output;
    O2 = *D->output;
    O3 = *F->output;
    printf("%d,%d,%d\n", O1, O2, O3);
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);
    // i give freedom to the memory , but who will give me freedom?
    return 0;
}