#ifndef NAIVE_ALGO_H_INCLUDED
#define NAIVE_ALGO_H_INCLUDED

/*
    Naive algorithm for bin - packing without rotation.
 */

#include "main_lib.h"

int x[N], idx[N], mat[N][N];
bool f = false, fr[N];

void chk_mat() {
    rep(j, 1, k) out(x[j], " ");
    cout << endl;
}

void backtrack(int i) {
    if (f) return;
    if (i > k) { chk_mat(); return; }

    x[i] = idx[i];  backtrack(i + 1);
    x[i] = -idx[i]; backtrack(i + 1);
    x[i] = 0;
}

bool chk_permutation() {
    fill(fr + 1, fr + k + 1, false);

    f = false;
    backtrack(1);

    return f;
}

void binpack_naive(int m, int n, int k, int a[], int b[]) {
    rep(i, 1, k) idx[i] = i;

    do {
        if(chk_permutation()) break;
    } while (std::next_permutation(idx + 1, idx + k + 1));

}

#endif // NAIVE_ALGO_H_INCLUDED
