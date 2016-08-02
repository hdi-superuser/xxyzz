#ifndef GLOBAL_METHOD_H_INCLUDED
#define GLOBAL_METHOD_H_INCLUDED

#include "main_lib.h"

/*
    Global method for this solution.
 */

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
