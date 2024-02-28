#include <stdio.h>
#include <stdlib.h>

#include "algo07.03.h"
#include "matrix.h"

int
main (void)
{
  Matrix *a = matrix_new (3, 3);
  // clang-format off
  matrix_init (a, (double[]) {
    4,  3,  0,
    3,  4, -1,
    0, -1,  4
  });
  // clang-format on

  Matrix *b = matrix_new (3, 1);
  // clang-format off
  matrix_init (b, (double[]) {
     24,
     30,
    -24
  });
  // clang-format on

  Matrix *xo = matrix_new (3, 1);
  // clang-format off
  matrix_init (xo, (double[]) {
    1,
    1,
    1
  });
  // clang-format on

  Matrix *x = matrix_new (3, 1);

  unsigned int max_iter = 15;
  double       tol      = 1e-4;
  double       omega    = 1.25;

  if (algo_07_03 (a, b, x, xo, omega, tol, max_iter))
    matrix_print (x);
  else
    printf ("Maximum number of iterations exceeded\n");

  matrix_free (x);
  matrix_free (xo);
  matrix_free (b);
  matrix_free (a);

  return EXIT_SUCCESS;
}
