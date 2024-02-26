#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "algo07.01.h"
#include "matrix.h"

bool
algo_07_07 (Matrix      *a,
            Matrix      *b,
            Matrix      *x,
            Matrix      *xo,
            double       tol,
            unsigned int max_iter)
{
  assert (a && b && x && xo);
  assert (tol > 0);
  assert (a->m == a->n);

  assert (a->m == b->m);
  assert (b->n == 1);

  assert (a->m == x->m);
  assert (x->n == 1);

  assert (a->m == xo->m);
  assert (xo->n == 1);

  double sum;
  double norm_inf;
  double abs_diff;

  // step 1
  unsigned int k = 1;

  // step 2
  while (k <= max_iter)
    {
      // step 3
      for (size_t i = 1; i <= a->n; ++i)
        {
          sum = MAT_ELEMENT (b, i, 1);
          for (size_t j = 1; j <= a->n; ++j)
            {
              if (i == j)
                continue;
              sum -= MAT_ELEMENT (a, i, j) * MAT_ELEMENT (xo, j, 1);
            }
          MAT_ELEMENT (x, i, 1) = sum / MAT_ELEMENT (a, i, i);
        }

      // step 4
      norm_inf = 0;
      for (size_t i = 1; i <= x->m; ++i)
        {
          abs_diff = fabs (MAT_ELEMENT (x, i, 1) - MAT_ELEMENT (xo, i, 1));
          if (abs_diff > norm_inf)
            norm_inf = abs_diff;
        }
      if (norm_inf < tol)
        return true;

      // step 5
      k++;

      // step 6
      for (size_t i = 1; i <= x->m; ++i)
        {
          MAT_ELEMENT (xo, i, 1) = MAT_ELEMENT (x, i, 1);
        }
    }

  return false;
}
