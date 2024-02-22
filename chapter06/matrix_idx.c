#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int
main (void)
{
  size_t  m = 4;
  size_t  n = 5;
  Matrix *a = matrix_new (m, n);
  // clang-format off
  double elements[] = {
     1,  1,  0,  3,  4,
     2,  1, -1,  1,  1,
     3, -1, -1,  2, -3,
    -1,  2,  3, -1,  4
  };
  // clang-format on
  matrix_init (a, elements);

  for (size_t i = 1; i <= a->m; ++i)
    {
      for (size_t j = 1; j <= a->n; ++j)
        {
          printf ("(%4zu,%3zu)", i, j);
        }
      printf ("\n");
      for (size_t j = 1; j <= a->n; ++j)
        {
          printf ("%10zu", MAT_INDEX (a, i, j));
        }
      printf ("\n");
    }

  matrix_free (a);
  return EXIT_SUCCESS;
}
