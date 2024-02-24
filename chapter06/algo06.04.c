#include <assert.h>
#include <stdbool.h>

#include "matrix.h"

bool
algo06_04 (Matrix *a)
{
  assert (a->m == a->n);

  double mult, diag, sum1, sum2;
  // size_t m = a->m;
  size_t n = a->n;

  // step 1
  if (MAT_ELEMENT (a, 1, 1) == 0.0)
    return false;

  // step 2
  for (size_t j = 2; j <= n; ++j)
    {
      mult                  = MAT_ELEMENT (a, j, 1) / MAT_ELEMENT (a, 1, 1);
      MAT_ELEMENT (a, j, 1) = mult;
    }

  // step 3
  for (size_t i = 2; i < n; ++i)
    {
      // step 4
      diag = MAT_ELEMENT (a, i, i);
      for (size_t k = 1; k < i; ++k)
        {
          diag -= MAT_ELEMENT (a, i, k) * MAT_ELEMENT (a, k, i);
        }
      if (diag == 0.0)
        return false;
      MAT_ELEMENT (a, i, i) = diag;

      // step 5
      for (size_t j = i + 1; j <= n; ++j)
        {
          sum1 = MAT_ELEMENT (a, i, j);
          sum2 = MAT_ELEMENT (a, j, i);
          for (size_t k = 1; k < i; ++k)
            {
              sum1 -= MAT_ELEMENT (a, i, k) * MAT_ELEMENT (a, k, j);
              sum2 -= MAT_ELEMENT (a, j, k) * MAT_ELEMENT (a, k, i);
            }
          MAT_ELEMENT (a, i, j) = sum1;
          MAT_ELEMENT (a, j, i) = sum2 / diag;
        }
    }

  // step 6
  diag = MAT_ELEMENT (a, n, n);
  for (size_t k = 1; k < n; ++k)
    {
      diag -= MAT_ELEMENT (a, n, k) * MAT_ELEMENT (a, k, n);
    }
  MAT_ELEMENT (a, n, n) = diag;

  return true;
}
