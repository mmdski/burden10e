#include <stdio.h>
#include <stdlib.h>

#include "algo06.01.h"
#include "matrix.h"

int
main (void)
{
  size_t  m = 4;
  size_t  n = 4;
  Matrix *a = matrix_new (m, n);
  // clang-format off
  matrix_init (a, (double[16]) {
     1,  1,  0,  3,
     2,  1, -1,  1,
     3, -1, -1,  2,
    -1,  2,  3, -1,
  });

  Matrix *b = matrix_new (m, 1);
  // clang-format off
  matrix_init (b, (double[4]) {
     4,
     1,
    -3,
     4
  });
  // clang-format on

  Matrix *x = matrix_new (m, 1);

  printf ("Augmented matrix\n");
  matrix_print_aug (a, b);

  if (!algo06_01 (a, b, x))
    printf ("no unique solution exists\n");
  else
    {
      printf ("x=\n");
      matrix_print (x);
    }

  matrix_free (b);
  matrix_free (a);
  return EXIT_SUCCESS;
}
