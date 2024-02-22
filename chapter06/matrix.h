#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>

#define MAT_INDEX(A, i, j) (A->n * (i - 1) + (j - 1))
#define MAT_ELEMENT(A, i, j) A->elements[(A->n * (i - 1) + (j - 1))]

typedef struct
{
  size_t m;
  size_t n;
  double elements[];
} Matrix;

Matrix *matrix_new (size_t m, size_t n);
void    matrix_init (Matrix *a, double *elements);
void    matrix_free (Matrix *a);
void    matrix_row_mult (Matrix *a, size_t row, double mult);
void    matrix_row_add (Matrix *a, size_t i, size_t j, double mult);
void    matrix_row_exch (Matrix *a, size_t i, size_t j);
void    matrix_print_aug (Matrix *a, Matrix *b);
void    matrix_print (Matrix *a);

#endif
