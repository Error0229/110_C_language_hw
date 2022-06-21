#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int end(char *k)
{
    return (int)strlen(k);
}
int main()
{
    char input[150], ins[150], temp1[150], temp2[150];
    memset(input, 0, sizeof(input));
    memset(ins, 0, sizeof(ins));
    memset(temp1, 0, sizeof(temp1));
    memset(temp2, 0, sizeof(temp2));
    gets(input);
    gets(ins);
    int i = 0, id = 0;
    char c;
    for (i = 0; i < end(ins); i++)
    {
        c = ins[i];
        switch (c)
        {
        case '0':
            id = 0;
            break;
        case '$':
            id = end(input);
            break;
        case 'x':
            if (id != end(input))
            {
                strcpy(temp1, input + id + 1);
                if (id > 0)
                    strncpy(temp2, input, id);
                temp2[id] = '\0';
                // printf("temp1:%s\ntemp2:%s %d\n", temp1,temp2,end(temp2));
                strcat(temp2, temp1);
                strcpy(input, temp2);
            }
            break;
        case 's':
            if (id < end(input) - 1)
            {
                char k = input[id];
                input[id] = input[id + 1];
                input[id + 1] = k;
            }
            break;
        case 'i':
            i++;
            char k = ins[i];
            strcpy(temp1, input + id);
            strncpy(temp2, input, id);
            temp2[id] = '\0';
            int w = end(temp2);
            temp2[w + 1] = '\0';
            temp2[w] = k;
            strcat(temp2, temp1);
            strcpy(input, temp2);
            id++;
            break;
        case 'u':
            if (isalpha(input[id]))
                input[id] = toupper(input[id]);
            id++;
            break;
        case '+':
            id++;
            break;
        case '-':
            id--;
            break;
        }
    }
    puts(input);
    return 0;
}