#ifndef BINPACK_NAIVE_RANDOM_H_INCLUDED
#define BINPACK_NAIVE_RANDOM_H_INCLUDED

#include "main_lib.h"

bool binpack_naive_random_tle = false;
void binpack_naive_random(int m, int n, int k, int a[], int b[]) {
    init_time("binpack_naive random");

    srand(time(NULL));
    rep(i, 1, k) idx[i] = i;
    no_solution = true;

    do {
        if (TLE()) {
            flog << "binpack_naive random: TLE" << endl;
            cerr << "binpack_naive random: TLE" << endl;
            binpack_naive_random_tle = true;
            return;
        }

        random_shuffle(idx + 1, idx + k + 1);
        if(chk_permutation()) break;
    } while (true);

    return;
}

#endif // BINPACK_NAIVE_RANDOM_H_INCLUDED
