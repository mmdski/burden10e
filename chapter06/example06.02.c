#include <stdio.h>

#include "algo06.01.h"
#include "matrix.h"

int
main (void)
{
  Matrix *a = matrix_new (4, 4);
  // clang-format off
  matrix_init (a, (double[]) {
    1, -1, 2, -1,
    2, -2, 3, -3,
    1,  1, 1,  0,
    1, -1, 4,  3
  });
  // clang-format on

  Matrix *b = matrix_new (4, 1);
  // clang-format off
  matrix_init (b, (double[]) {
     -8,
    -20,
     -2,
      4
  });
  // clang-format on

  Matrix *x = matrix_new (4, 1);

  printf ("ax = b\n");
  matrix_print_aug (a, b);

  algo06_01 (a, b, x);

  printf ("x = \n");
  matrix_print (x);

  matrix_free (x);
  matrix_free (b);
  matrix_free (a);
  return 0;
}
