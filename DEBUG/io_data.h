#ifndef IO_DATA_H_INCLUDED
#define IO_DATA_H_INCLUDED

#include "main_lib.h"

void data_file() {
    freopen(file_in, "r", stdin);
    freopen(file_out, "w", stdout);
}

void import_data() {
    in(m);  in(n);  in(k);
    rep(i, 1, k) { in(a[i]); in(b[i]); }
}

void export_data() {

}

#endif // IO_DATA_H_INCLUDED
