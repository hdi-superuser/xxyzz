#include "main_lib.h"

using namespace std;

/*
    The MIT License (MIT) applied
    Copyright (c) <2016> <huynhduy.idol@gmail.com>
 */

void _auto() {
    data_file();    import_data();

    if (!ok_s(m, n, k, a, b)) { message_nosol("check area"); outbrk(-1); }

    queue_greedy(m, n, k, a, b);
    if (finish && ok_rect()) { export_data(); exit(0); }
    else if (!queue_greedy_tle) message_nosol("queue_greedy");

    initializer_data();
    simple_greedy(m, n, k, a, b);
    if (finish && ok_rect()) { export_data(); exit(0); }
    else if (!simple_greedy_tle) message_nosol("simple_greedy");

    initializer_data();
    binpack_naive(m, n, k, a, b);
    if (finish && ok_rect()) { export_data(); exit(0); }
    else if (!binpack_naive_tle) message_nosol("binpack_naive");

    initializer_data();
    binpack_naive_rev(m, n, k, a, b);
    if (finish && ok_rect()) { export_data(); exit(0); }
    else if (!binpack_naive_tle) message_nosol("binpack_naive_rev");

    export_data();
    return;
}

main( void ) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cl = clock();
    _auto();

    return 0;
}
