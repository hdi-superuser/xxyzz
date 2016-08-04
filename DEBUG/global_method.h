#ifndef GLOBAL_METHOD_H_INCLUDED
#define GLOBAL_METHOD_H_INCLUDED

#include "main_lib.h"

/*
    Global method for this solution.
 */

void initializer_data() {
    memset(mat, 0, sizeof mat);
    memset(mat_res, 0, sizeof mat_res);

    no_solution = true;
    finish = false;
}

rectangle make_rectangle(int x, int y, int id) {
    rectangle myrect;
    myrect.a = x;   myrect.b = y;   myrect.idx = id;
    return myrect;
}

regions make_regions(int x1, int y1, int x2, int y2, int clr) {
    regions myreg;
    myreg.x1 = x1;  myreg.x2 = x2;
    myreg.y1 = y1;  myreg.y2 = y2;
    myreg.color = clr;
    return myreg;
}

bool empty(int x1, int y1, int x2, int y2) {
    rep(x, x1, x2) rep(y, y1, y2)
        if (mat[x][y]) return false;
    return true;
}

void put(int x1, int y1, int x2, int y2, int id) {
    rep(x, x1, x2) rep(y, y1, y2)
        mat[x][y] = id;
}

void back_up() {
    no_solution = false;
    rep(x, 1, m) rep(y, 1, n) mat_res[x][y] = mat[x][y];
}

#endif // GLOBAL_METHOD_H_INCLUDED
