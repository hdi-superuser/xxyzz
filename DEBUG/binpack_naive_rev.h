#ifndef BINPACK_NAIVE_H_REV
#define BINPACK_NAIVE_H_REV

void binpack_naive_rev(int m, int n, int k, int a[], int b[]) {
    init_time("binpack_naive");

    rep(i, 1, k) idx[i] = i;
    no_solution = true;

    do {
        if (TLE()) {
            flog << "binpack_naive_rev: TLE" << endl;
            cerr << "binpack_naive_rev: TLE" << endl;
            binpack_naive_tle = true;
            return;
        }

        if(chk_permutation()) break;
    } while (std::next_permutation(idx + 1, idx + k + 1));

    return;
}

#endif //BINPACK_NAIVE_H_REV
