#include <stdio.h>

#include "algo06.01.h"
#include "matrix.h"

int
main (void)
{
  size_t  m = 3;
  size_t  n = 3;
  Matrix *a = matrix_new (m, n);
  // clang-format off
  matrix_init (a, (double[16]) {
     1, 1, 1,
     2, 2, 1,
     1, 1, 2,
  });

  Matrix *b = matrix_new (m, 1);
  // clang-format off
  matrix_init (b, (double[4]) {
     4,
     6,
     6
  });
  // clang-format on

  Matrix *x = matrix_new (m, 1);

  printf ("Augmented matrix\n");
  matrix_print_aug (a, b);

  if (!algo06_01 (a, b, x))
    {
      printf ("no unique solution exists\n");
      matrix_print_aug (a, b);
    }
  else
    {
      printf ("x=\n");
      matrix_print (x);
    }

  matrix_free (b);
  matrix_free (a);
  return EXIT_SUCCESS;
}
