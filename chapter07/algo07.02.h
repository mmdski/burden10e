#ifndef ALGO_07_02_H_
#define ALGO_07_02_H_

#include <stdbool.h>

#include "matrix.h"

bool algo_07_02 (Matrix      *a,
                 Matrix      *b,
                 Matrix      *x,
                 Matrix      *xo,
                 double       tol,
                 unsigned int max_iter);
#endif
