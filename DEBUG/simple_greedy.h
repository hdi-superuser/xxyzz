#ifndef SIMPLE_GREEDY_H_INCLUDED
#define SIMPLE_GREEDY_H_INCLUDED

#include "main_lib.h"

/*
    Simple greedy method without rotation.
 */

rectangle rect[N];

void arrange() {
    int cnt = 0;
    rep(i, 1, k) {
        bool cont = false;

        rep(j1, 1, m) {
            if (cont) break;

            rep(j2, 1, n) {
                if (cont) break;
                if (j1 + rect[i].a - 1 > m || j2 + rect[i].b - 1 > n) continue;

                if (empty(j1, j2, j1 + rect[i].a - 1, j2 + rect[i].b - 1)) {
                    put(j1, j2, j1 + rect[i].a - 1, j2 + rect[i].b - 1, rect[i].idx);
                    cnt++;  cont = true;
                }
            }
        }
    }

    finish = (cnt == k);
}

void cover_data(int a[], int b[]) {
    rep(i, 1, k) {
        rect[i].a = a[i];
        rect[i].b = b[i];
        rect[i].idx = i;
    }
}

bool less_than(rectangle a, rectangle b) {
    return a.a * a.b < b.a * b.b;
}

bool greater_than(rectangle a, rectangle b) {
    return a.a * a.b > b.a * b.b;
}

void simple_greedy(int m, int n, int k, int a[], int b[]) {
    cover_data(a, b);

    sort(rect + 1, rect + k + 1, less_than);
    finish = false;

    arrange();
    if (finish) { back_up(); return; }

    sort(rect + 1, rect + k + 1, greater_than);
    finish = false;

    arrange();
    if (finish) { back_up(); return; }
}

#endif // SIMPLE_GREEDY_H_INCLUDED
