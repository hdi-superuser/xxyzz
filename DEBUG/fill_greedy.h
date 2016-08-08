#ifndef FILL_GREEDY_H_INCLUDED
#define FILL_GREEDY_H_INCLUDED

#include "main_lib.h"

/*
    Fill greedy.
 */

vector <rectangle> rt, rt_result;

int cnt, minX = 1;
bool canarr = false;

bool greater_cmp(rectangle a, rectangle b) {
    return a.a != b.a ? a.a > b.a : a.b > b.b;
}

bool less_cmp(rectangle a, rectangle b) {
    return a.a != b.a ? a.a < b.a : a.b < b.b;
}

void arrange_left() {

}

void arrange_right() {

}

void fill_greedy(int m, int n, int k, int a[], int b[]) {
    rep(i, 1, k) rt.push_back(make_rectangle(a[i], b[i], i));

    cnt = k;    int direct = 1;
    while (cnt) {
        direct = 1 - direct;
        if (direct) arrange_left();
        else arrange_right();
    }
}

#endif // FILL_GREEDY_H_INCLUDED
