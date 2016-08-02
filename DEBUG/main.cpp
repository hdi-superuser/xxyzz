#include "main_lib.h"

using namespace std;

/*
    The MIT License (MIT) applied
    Copyright (c) <2016> <huynhduy.idol@gmail.com>
 */

main( void ) {
    data_file();
    import_data();
    if (!ok_s(m, n, k, a, b)) outbrk(-1);

    binpack_naive(m, n, k, a, b);
    export_data();
}
