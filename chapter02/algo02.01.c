#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  double a;
  double b;
  double tol;
  int    N;

  double delta;
  int    i;
} BisectionData;

// algorithm 2.1
double
bisection (double (*f) (double x), BisectionData *data)
{
  double a   = data->a;
  double b   = data->b;
  double tol = data->tol;

  int i = 1;
  int N = data->N;

  double fa, fp, p, delta;

  if ((*f) (a) * (*f) (b) >= 0)
    return NAN;

  fa = (*f) (a);

  while (i <= N)
    {
      p  = a + (b - a) / 2.0;
      fp = (*f) (p);

      delta = fabs (b - a) / fabs (fmin (a, b));

      if (fp == 0 || delta < tol)
        goto found;

      if (fa * fp > 0)
        {
          a  = p;
          fa = fp;
        }
      else
        b = p;

      i++;
    }

  return NAN;

found:
  data->i     = i;
  data->delta = delta;
  return p;
}

double
f (double x)
{
  return x * x * x + 4 * x * x - 10;
}

// example 1 in section 2.1
int
main (void)
{

  BisectionData data = { 1, 2, 1e-4, 15, 0, 0 };

  double p = bisection (&f, &data);

  if (isfinite (p))
    {
      printf ("Root f(%f) = %f found after %d steps\n", p, f (p), data.i);
    }
  else
    {
      printf ("Root not found");
    }

  return EXIT_SUCCESS;
}
