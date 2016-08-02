#ifndef CHK_S_H_INCLUDED
#define CHK_S_H_INCLUDED

#include "main_lib.h"

bool ok_s(int m, int n, int k, int a[], int b[]) {
    int are = 0;
    rep(i, 1, k) are += a[i] * b[i];
    return are <= m * n;
}

#endif // CHK_S_H_INCLUDED
