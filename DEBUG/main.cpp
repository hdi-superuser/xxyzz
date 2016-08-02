/*
    Copyright Duy Huynh <huynhduy.idol@gmail.com>
    7-2016

    MIT & BSD LINCESE APLLIED
 */

#include "main_lib.h"

using namespace std;

main( void ) {
    data_file();
    import_data();

    binpack_naive(m, n, k, a, b);
}
