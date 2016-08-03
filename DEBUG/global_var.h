#ifndef GLOBAL_VAR_H_INCLUDED
#define GLOBAL_VAR_H_INCLUDED

#include "main_lib.h"

/*
    Global variable use in this solution.
 */

#define file_in "main.inp"
#define file_out "main.out"
#define N 5001
#define MOD 1000000007
#define inf 0x7fffffff

int m, n, k, a[N], b[N];
int mat_res[N][N], mat[N][N];

bool no_solution, finish;

struct rectangle {
    int a, b, idx;
};

struct regions {
    int x1, y1, x2, y2;
    int hi() { return abs(x2 - x1); }
    int wi() { return abs(y2 - y1); }
    int color = 0;
    int size() {
        return abs(x2 - x1) * abs(y2 - y1);
    }
};

#endif // GLOBAL_VAR_H_INCLUDED
