#ifndef NAIVE_ALGO_H_INCLUDED
#define NAIVE_ALGO_H_INCLUDED

/*
    Naive algorithm for bin - packing problems.
    Time complexity: O(K!*2^K*K*M*N).
 */

#include "main_lib.h"

int x[N], idx[N];

void chk_mat() {
    rep(j, 1, m) fill(mat[j] + 1, mat[j] + n + 1, 0);

    int cnt = 0;
    rep(j, 1, k) {
        int d, r;
        bool cont = false;

        if (x[j] > 0) d = a[x[j]], r = b[x[j]];
        else d = b[-x[j]], r = a[-x[j]];

        rep(j1, 1, m) {
            if (cont) break;

            rep(j2, 1, n) {
                if (cont) break;
                if (j1 + d - 1 > m || j2 + r - 1 > n) continue;

                if (empty(j1, j2, j1 + d - 1, j2 + r - 1)) {
                    put(j1, j2, j1 + d - 1, j2 + r - 1, x[j]);
                    cnt++;      cont = true;
                }
            }
        }
    }

    finish = (cnt == k);
    if (finish) back_up();
}

void backtrack(int i) {
    if (finish) return;
    if (i > k) { chk_mat(); return; }

    x[i] = idx[i];  backtrack(i + 1);
    x[i] = -idx[i]; backtrack(i + 1);
    x[i] = 0;
}

bool chk_permutation() {
    finish = false;
    backtrack(1);

    return finish;
}

void binpack_naive(int m, int n, int k, int a[], int b[]) {
    rep(i, 1, k) idx[i] = i;
    no_solution = true;

    do {
        if(chk_permutation()) break;
    } while (std::next_permutation(idx + 1, idx + k + 1));

}

#endif // NAIVE_ALGO_H_INCLUDED
