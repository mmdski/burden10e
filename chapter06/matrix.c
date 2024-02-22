#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

Matrix *
matrix_new (size_t m, size_t n)
{
  assert (m && n);

  Matrix *a = malloc (sizeof (Matrix) + sizeof (double) * m * n);

  a->m = m;
  a->n = n;

  return a;
}

void
matrix_init (Matrix *a, double *arr)
{
  assert (a && arr);

  size_t a_size = a->m * a->n;

  for (size_t i = 0; i < a_size; ++i)
    a->elements[i] = arr[i];
}

void
matrix_free (Matrix *a)
{
  free (a);
}

void
matrix_row_mult (Matrix *a, size_t row, double mult)
{
  assert (a);
  assert (1 <= row && row <= a->m);

  for (size_t j = 1; j <= a->n; ++j)
    {
      MAT_ELEMENT (a, row, j) = mult * MAT_ELEMENT (a, row, j);
    }
}

void
matrix_row_add (Matrix *a, size_t i, size_t j, double mult)
{
  assert (a);
  assert (1 <= i && i <= a->m);
  assert (1 <= j && j <= a->m);

  for (size_t k = 1; k <= a->n; ++k)
    {
      MAT_ELEMENT (a, i, k) =
          MAT_ELEMENT (a, i, k) + mult * MAT_ELEMENT (a, j, k);
    }
}

void
matrix_row_exch (Matrix *a, size_t i, size_t j)
{
  assert (a);
  assert (1 <= i && i <= a->m);
  assert (1 <= j && j <= a->m);

  if (i == j)
    return;

  double swp;

  for (size_t k = 1; k <= a->n; ++k)
    {
      swp                   = MAT_ELEMENT (a, j, k);
      MAT_ELEMENT (a, j, k) = MAT_ELEMENT (a, i, k);
      MAT_ELEMENT (a, i, k) = swp;
    }
}

// print augmented matrix
void
matrix_print_aug (Matrix *a, Matrix *b)
{
  for (size_t i = 1; i <= a->m; ++i)
    {
      for (size_t j = 1; j <= a->n; ++j)
        printf ("%10.2f", MAT_ELEMENT (a, i, j));

      printf (" |");

      for (size_t j = 1; j <= b->n; ++j)
        printf ("%10.2f", MAT_ELEMENT (b, i, j));

      printf ("\n");
    }
}

// print a single matrix
void
matrix_print (Matrix *a)
{
  for (size_t i = 1; i <= a->m; ++i)
    {
      for (size_t j = 1; j <= a->n; ++j)
        printf ("%10.2f", MAT_ELEMENT (a, i, j));

      printf ("\n");
    }
}
