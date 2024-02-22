#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  double p0;
  double tol;
  int    N;

  double delta;
  int    i;
} NewtonData;

double
newton (double (*f) (double x), double (*f_prime) (double x), NewtonData *data)
{

  double p, p0, delta, tol;
  int    N, i;

  i   = 1;
  N   = data->N;
  p0  = data->p0;
  tol = data->tol;

  while (i <= N)
    {
      p     = p0 - (*f) (p0) / (*f_prime) (p0);
      delta = fabs (p - p0);
      if (delta < tol)
        goto success;

      i++;
      p0 = p;
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

double
f_prime (double x)
{
  return -sin (x) - 1;
}

// example 1 from section 2.3
int
main (void)
{
  NewtonData data = { M_PI / 4.0, 1e-4, 15, 0, 0 };

  double p = newton (&f, &f_prime, &data);
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
