#include "interpolate.h"

double interpolate_lagrange(point_t **points, unsigned int size, double x) /* Sem otimizacoes */
{
    double l, p = 0.0;

    for (int i = 0; i < size; ++i)
    {
        l = 1;

        for (int j = 0; j < size; ++j) /* Calculo do multiplicador */
        {
            if (j == i) 
                continue;

            l *= (x - points[j]->x)/(points[i]->x - points[j]->x);
        }

        p += points[i]->y * l;
    }

    return p;
}

double interpolate_newton(point_t **points, unsigned int size, double x)
{
    return 0;
}

