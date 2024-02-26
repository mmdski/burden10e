#ifndef ALGO_07_01_H_
#define ALGO_07_01_H_

#include <stdbool.h>

#include "matrix.h"

bool algo_07_01 (Matrix      *a,
                 Matrix      *b,
                 Matrix      *x,
                 Matrix      *xo,
                 double       tol,
                 unsigned int max_iter);
#endif
