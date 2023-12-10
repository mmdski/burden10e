#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  double p0;
  double tol;
  int    N;

  int    i;
  double delta;
} FixedPtData;

double
fixed_pt_iter (double (*g) (double x), FixedPtData *data)
{
  int i = 1;

  double p0  = data->p0;
  double tol = data->tol;

  double p, delta;

  while (i <= data->N)
    {
      p     = (*g) (p0);
      delta = fabs (p - p0);

      if (delta < tol)
        goto success;

      p0 = p;

      i++;
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
g1 (double x)
{
  return x - x * x * x - 4 * x * x + 10;
}

double
g2 (double x)
{
  return sqrt (10.0 / x - 4.0 * x);
}

double
g3 (double x)
{
  return 0.5 * sqrt ((10.0 - x * x * x));
}

double
g4 (double x)
{
  return sqrt (10.0 / (4.0 + x));
}

double
g5 (double x)
{
  return x - (x * x * x + 4 * x * x - 10) / (3 * x * x + 8 * x);
}

int
main (void)
{
  FixedPtData data = { 1.5, 1e-9, 30, 0, 0 };

  double p = fixed_pt_iter (&g5, &data);
  if (isfinite (p))
    {
      printf ("Root f(%11.9f) = %e found after %d steps\n", p, f (p), data.i);
    }
  else
    {
      printf ("Root not found\n");
    }

  return EXIT_SUCCESS;
}
