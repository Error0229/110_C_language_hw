#include <stdio.h>
#include <string.h>

int hash(char* s) // CRC variant copy from internet
{
    int h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int highorder = h & 0xf8000000; // extract high-order 5 bits from h
                                        // 0xf8000000 is the hexadecimal representation
                                        //   for the 32-bit number with the first five
                                        //   bits = 1 and the other bits = 0
        h = h << 5; // shift h left by 5 bits
        h = h ^ (highorder >> 27); // move the highorder 5 bits to the low-order
                                   //   end and XOR into h
        h = h ^ (int)s[i]; // XOR h and ki
    }
    return h;
}
int main()
{
    char s[100];
    memset(s, 0, sizeof(s));
    int data[100], n;
    memset(data, 0, sizeof(data));
    char dlm[2] = " ";
    gets(s);
    char* tok;
    tok = strtok(s, dlm);
    int id = 0;
    while (tok != NULL) {
        int fl = 0;
        for (int i = 0; i < id; i++) {
            if (hash(tok) == data[i]) {
                fl = 1;
                break;
            }
        }
        if (fl == 0) {
            data[id++] = hash(tok);
        }
        tok = strtok(NULL, dlm);
    }
    scanf("%d", &n);
    getchar();
    int input[100][100];
    memset(input, 0, sizeof(input));
    for (int i = 0; i < n; i++) {
        int input_id = 0;
        memset(s, 0, sizeof(s));
        gets(s);
        tok = strtok(s, dlm);
        while (tok != NULL) {
            int fl = 0;
            for (int j = 0; j < input_id; j++) {
                if (hash(tok) == input[i][j]) {
                    fl = 1;
                    break;
                }
            }
            if (fl == 0) {
                input[i][input_id++] = hash(tok);
            }
            tok = strtok(NULL, dlm);
        }
    }
    int sum = 0, modn = 1000000007, ans = 0;
    for (int i = 0; i < id; i++) {

        sum += (data[i] % modn);
        sum %= modn;
    }
    for (int i = 0; i < n; i++) {
        int ind = 0, sumi = 0;
        while (input[i][ind] != 0) {
            sumi += (input[i][ind] % modn);
            sumi %= modn;
            ind++;
        }
        for (int j = i; j < n; j++) {
            int sumj = 0;
            ind = 0;
            while (input[j][ind] != 0) {
                sumj += (input[j][ind] % modn);
                sumj %= modn;
                ind++;
            }
            if ((sumj + sumi) % modn == sum) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}