#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{

  double p0;
  double p1;
  double eps;
  int    N;

  double delta;
  int    i;
} SecantData;

double
secant (double (*f) (double), SecantData *data)
{

  double p, p0, p1, eps, q0, q1, delta;
  int    i, N;

  p0  = data->p0;
  p1  = data->p1;
  eps = data->eps;

  q0 = (*f) (p0);
  q1 = (*f) (p1);

  N = data->N;
  i = 2;

  while (i < N)
    {
      p     = p1 - q1 * (p1 - p0) / (q1 - q0);
      delta = fabs (p - p1);
      if (delta < eps)
        goto success;

      i++;

      p0 = p1;
      q0 = q1;
      p1 = p;
      q1 = (*f) (p);
    }

  return NAN;

success:
  data->delta = delta;
  data->i     = i;
  return p;
}

double
f (double x)
{
  return cos (x) - x;
}

int
main (void)
{

  SecantData data = { 0.5, M_PI / 4.0, 1e-5, 15, 0, 0 };

  double p = secant (&f, &data);
  if (isfinite (p))
    {
      printf ("Root f(%11.10f) = %e found after %d steps\n", p, f (p), data.i);
    }
  else
    {
      printf ("Root not found\n");
    }
  return EXIT_SUCCESS;
}
