#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum scoreType {
    G,
    GPA,
    S
} scoreType_t;
typedef enum gpa {
    gpa_4p3,
    gpa_4p0,
    gpa_3p7,
    gpa_3p3,
    gpa_3p0,
    gpa_2p7,
    gpa_2p3,
    gpa_2p0,
    gpa_1p7,
    gpa_0
} gpa_t;
typedef enum grade {
    ap,
    a,
    am,
    bp,
    b,
    bm,
    cp,
    c,
    cm,
    f
} grade_t;
typedef enum stage_s {
    stage_90to100,
    stage_85to89,
    stage_80to84,
    stage_77to79,
    stage_73to76,
    stage_70to72,
    stage_67to69,
    stage_63to66,
    stage_60to62,
    stage_0to59
} stage_t;
typedef union score_s {
    grade_t grade;
    gpa_t gpa;
    stage_t score;
} score_t;
int main()
{
    score_t student[100][100];
    scoreType_t type[100];
    char name[100][100];
    int scores[10] = { 95, 87, 82, 78, 75, 70, 68, 65, 60, 50 };
    int m, n;
    scanf("%d", &m);
    getchar();
    char s[100];
    for (int i = 0; i < m; i++) {
        memset(s, 0, sizeof(s));
        gets(s);
        if (strcmp(s, "GPA") == 0) {
            type[i] = GPA;
        }
        if (strcmp(s, "G") == 0) {
            type[i] = G;
        }
        if (strcmp(s, "S") == 0) {
            type[i] = S;
        }
    }
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        gets(name[i]);
        for (int j = 0; j < m; j++) {
            memset(s, 0, sizeof(s));
            gets(s);
            if (type[j] == GPA) {
                if (strcmp(s, "4.3") == 0) {
                    student[i][j].gpa = scores[gpa_4p3];
                } else if (strcmp(s, "4.0") == 0) {
                    student[i][j].gpa = scores[gpa_4p0];
                } else if (strcmp(s, "3.7") == 0) {
                    student[i][j].gpa = scores[gpa_3p7];
                } else if (strcmp(s, "3.3") == 0) {
                    student[i][j].gpa = scores[gpa_3p3];
                } else if (strcmp(s, "3.0") == 0) {
                    student[i][j].gpa = scores[gpa_3p0];
                } else if (strcmp(s, "2.7") == 0) {
                    student[i][j].gpa = scores[gpa_2p7];
                } else if (strcmp(s, "2.3") == 0) {
                    student[i][j].gpa = scores[gpa_2p3];
                } else if (strcmp(s, "2.0") == 0) {
                    student[i][j].gpa = scores[gpa_2p0];
                } else if (strcmp(s, "1.7") == 0) {
                    student[i][j].gpa = scores[gpa_1p7];
                } else if (strcmp(s, "0") == 0) {
                    student[i][j].gpa = scores[gpa_0];
                }
            } else if (type[j] == G) {
                if (strcmp(s, "A+") == 0) {
                    student[i][j].grade = scores[ap];
                } else if (strcmp(s, "A") == 0) {
                    student[i][j].grade = scores[a];
                } else if (strcmp(s, "A-") == 0) {
                    student[i][j].grade = scores[am];
                } else if (strcmp(s, "B+") == 0) {
                    student[i][j].grade = scores[bp];
                } else if (strcmp(s, "B") == 0) {
                    student[i][j].grade = scores[b];
                } else if (strcmp(s, "B-") == 0) {
                    student[i][j].grade = scores[bm];
                } else if (strcmp(s, "C+") == 0) {
                    student[i][j].grade = scores[cp];
                } else if (strcmp(s, "C") == 0) {
                    student[i][j].grade = scores[c];
                } else if (strcmp(s, "C-") == 0) {
                    student[i][j].grade = scores[cm];
                } else if (strcmp(s, "F") == 0) {
                    student[i][j].grade = scores[f];
                }
            } else if (type[j] == S) {
                if (strcmp(s, "90-100") == 0) {
                    student[i][j].score = scores[stage_90to100];
                } else if (strcmp(s, "85-89") == 0) {
                    student[i][j].score = scores[stage_85to89];
                } else if (strcmp(s, "80-84") == 0) {
                    student[i][j].score = scores[stage_80to84];
                } else if (strcmp(s, "77-79") == 0) {
                    student[i][j].score = scores[stage_77to79];
                } else if (strcmp(s, "73-76") == 0) {
                    student[i][j].score = scores[stage_73to76];
                } else if (strcmp(s, "70-72") == 0) {
                    student[i][j].score = scores[stage_70to72];
                } else if (strcmp(s, "67-69") == 0) {
                    student[i][j].score = scores[stage_67to69];
                } else if (strcmp(s, "63-66") == 0) {
                    student[i][j].score = scores[stage_63to66];
                } else if (strcmp(s, "60-62") == 0) {
                    student[i][j].score = scores[stage_60to62];
                } else if (strcmp(s, "0-59") == 0) {
                    student[i][j].score = scores[stage_0to59];
                }
            }
        }
    }
    int maxp = 0, maxid;
    double temp = 0.0;
    int vis[100];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[j])
                continue;
            for (int k = 0; k < m; k++) {
                if (type[k] == GPA) {
                    temp += student[j][k].gpa;
                }
                if (type[k] == G) {
                    temp += student[j][k].grade;
                }
                if (type[k] == S) {
                    temp += student[j][k].score;
                }
            }
            if ((int)(temp / m + 0.5) > maxp) {
                maxp = (int)(temp / m + 0.5);
                maxid = j;
            }
            temp = 0;
        }
        printf("%s\n%d\n", name[maxid], maxp);
        vis[maxid] = 1;
        maxp = 0;
        temp = 0.0;
    }
    return 0;
}
