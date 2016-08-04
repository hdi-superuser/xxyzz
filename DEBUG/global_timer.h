#ifndef GLOBAL_TIMER_H_INCLUDED
#define GLOBAL_TIMER_H_INCLUDED

#include "main_lib.h"

double cl_old;

void init_time(string s) {
    cl_old = clock();
    flog << "excute " << s << "." << endl;
    cerr << "excute " << s << "." << endl;
}

double get_time() {
    return (double) ((clock() - cl_old) / CLOCKS_PER_SEC);
}

bool TLE() {
    return get_time() >= ETM;
}

#endif // GLOBAL_TIMER_H_INCLUDED
