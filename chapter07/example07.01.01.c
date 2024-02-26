#include <stdio.h>
#include <stdlib.h>

#include "algo07.01.h"
#include "matrix.h"

int
main (void)
{
  Matrix *a = matrix_new (4, 4);
  // clang-format off
  matrix_init (a, (double[]) {
    10, -1,  2,  0,
    -1, 11, -1,  3,
     2, -1, 10, -1,
     0,  3, -1,  8
  });
  // clang-format on

  Matrix *b = matrix_new (4, 1);
  // clang-format off
  matrix_init (b, (double[]) {
      6,
     25,
    -11,
     15
  });
  // clang-format on

  Matrix *xo = matrix_new (4, 1);
  // clang-format off
  matrix_init (xo, (double[]) {
    0,
    0,
    0,
    0
  });
  // clang-format on

  Matrix *x = matrix_new (4, 1);

  unsigned int max_iter = 15;
  double       tol      = 1e-3;

  if (algo_07_07 (a, b, x, xo, tol, max_iter))
    matrix_print (x);
  else
    printf ("Maximum number of iterations exceeded\n");

  matrix_free (x);
  matrix_free (xo);
  matrix_free (b);
  matrix_free (a);

  return EXIT_SUCCESS;
}
