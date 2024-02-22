#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  double p0;
  double eps;
  int    N;

  double delta;
  int    i;
} SteffensenData;

double
steffensen (double (*g) (double x), SteffensenData *data)
{
  double p, p0, p1, p2, eps, delta;
  int    i, N;

  i   = 1;
  N   = data->N;
  p0  = data->p0;
  eps = data->eps;

  while (i <= N)
    {
      p1 = (*g) (p0);
      p2 = (*g) (p1);
      p  = p0 - (p1 - p0) * (p1 - p0) / (p2 - 2 * p1 + p0);

      delta = fabs (p - p0);
      if (delta < eps)
        goto success;

      i++;
      p0 = p;
    }

  return NAN;

success:
  data->i     = i;
  data->delta = delta;
  return p;
}

double
f (double x)
{
  return x * x * x + 4 * x * x - 10;
}
double
g (double x)
{
  return sqrt (10 / (x + 4));
}

int
main (void)
{

  SteffensenData data = { 1.5, 1e-4, 15, 0, 0 };

  double p = steffensen (&g, &data);
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
