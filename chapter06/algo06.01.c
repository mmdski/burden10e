#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "algo06.01.h"

// algorithm 6.1
// gaussian elimination with backward substitution
bool
algo06_01 (Matrix *a, Matrix *b, Matrix *x)
{
  assert (a->m == b->m);
  assert (b->n == 1);    // b is a column vector
  assert (a->m == a->n); // a is square
  assert (a->n == x->m);

  double mult;
  double sum;
  size_t m = a->m;
  size_t n = a->n;
  size_t p;

  for (size_t i = 1; i <= n; ++i)
    {
      p = i;
      while (p < m && MAT_ELEMENT (a, p, i) == 0.0)
        {
          p++;
        }
      if (MAT_ELEMENT (a, p, i) == 0.0)
        return false;
      else if (p != i)
        {
          matrix_row_exch (a, i, p);
          matrix_row_exch (b, i, p);
        }

      for (size_t j = i + 1; j <= n; ++j)
        {
          mult = MAT_ELEMENT (a, j, i) / MAT_ELEMENT (a, i, i);
          matrix_row_add (a, j, i, -mult);
          matrix_row_add (b, j, i, -mult);
        }
    }

  if (MAT_ELEMENT (a, n, n) == 0)
    return false;

  MAT_ELEMENT (x, n, 1) = MAT_ELEMENT (b, n, 1) / MAT_ELEMENT (a, n, n);

  for (size_t i = n - 1; i > 0; i--)
    {
      sum = MAT_ELEMENT (b, i, 1);
      for (size_t j = i + 1; j <= n; ++j)
        sum -= MAT_ELEMENT (a, i, j) * MAT_ELEMENT (x, j, 1);

      MAT_ELEMENT (x, i, 1) = sum / MAT_ELEMENT (a, i, i);
    }

  return true;
}
