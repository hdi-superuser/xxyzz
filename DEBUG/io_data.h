#ifndef IO_DATA_H_INCLUDED
#define IO_DATA_H_INCLUDED

#include "main_lib.h"

/*
    Process data, input, output.
 */

void data_file() {
    freopen(file_in, "r", stdin);
    freopen(file_out, "w", stdout);
}

void import_data() {
    in(m);  in(n);  in(k);
    rep(i, 1, k) { in(a[i]); in(b[i]); }
}

void export_data() {
    if (no_solution) outbrk(-1);

    rep(x, 1, m) {
        rep(y, 1, n) out(mat_res[x][y], " ");
        outln();
    }
}

#endif // IO_DATA_H_INCLUDED
