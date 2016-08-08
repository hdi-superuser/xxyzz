#ifndef BINPACK_NAIVE_H_REV_INCLUDED
#define BINPACK_NAIVE_H_REV_INCLUDED

int d[N];
void binpack_naive_rev(int m, int n, int k, int a[], int b[]) {
    init_time("binpack_naive");

    rep(i, 1, k) d[i] = i;
    no_solution = true;

    do {
        if (TLE()) {
            flog << "binpack_naive_rev: TLE" << endl;
            cerr << "binpack_naive_rev: TLE" << endl;
            binpack_naive_tle = true;
            return;
        }
        rep(i, 1, k) idx[i] = d[i];
        reverse(idx + 1, idx + k + 1);
        if(chk_permutation()) break;
    } while (std::next_permutation(d + 1, d + k + 1));

    return;
}

#endif //BINPACK_NAIVE_H_REV_INCLUDED
