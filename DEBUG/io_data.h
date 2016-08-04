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

void message_nosol(string s) {
    flog << s << " status: no solution." << endl;
    cerr << s << " status: no solution." << endl;
}

void export_data() {
    if (no_solution) {
        out(-1);
        cl = clock() - cl;
        fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
        return;
    }

    rep(x, 1, m) {
        rep(y, 1, n) out(mat_res[x][y], " ");
        outln();
    }

    flog << "Check status: AC" << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
}

#endif // IO_DATA_H_INCLUDED
