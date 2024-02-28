#ifndef ALGO_07_03_H_
#define ALGO_07_03_H_

#include <stdbool.h>

#include "matrix.h"

bool algo_07_03 (Matrix      *a,
                 Matrix      *b,
                 Matrix      *x,
                 Matrix      *xo,
                 double       omega,
                 double       tol,
                 unsigned int max_iter);
#endif
