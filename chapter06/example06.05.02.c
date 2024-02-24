#include <stdio.h>
#include <stdlib.h>

#include "algo06.04.h"
#include "matrix.h"

int
main (void)
{
  Matrix *a = matrix_new (4, 4);
  // clang-format off
  matrix_init (a, (double[]) {
    1,  1,  0,  3,
    2,  1, -1,  1,
    3, -1, -1,  2,
   -1,  2,  3, -1
  });
  // clang-format on

  printf ("a=\n");
  matrix_print (a);
  if (!algo06_04 (a))
    printf ("Factorization impossible\n");
  else
    {
      printf ("LU=\n");
      matrix_print (a);
    }

  matrix_free (a);
  return EXIT_SUCCESS;
}
