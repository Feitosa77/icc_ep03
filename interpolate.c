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

/* Ineficiente - Implementacao ingenua */

double dd(point_t **points, unsigned int i, unsigned int j) /* def rec */
{
    if (i == j)
        return points[i]->y;

    double d1, d2;

    d1 = dd(points, i+1, j);
    d2 = dd(points, i, j-1);

    return (d1-d2)/(points[j]->x - points[i]->x);
}

double interpolate_newton(point_t **points, unsigned int size, double x) /* Sem otimizacoes */
{
    double d, num, p = 0.0;

    for (int i = 0; i < size; ++i) 
    {
        d = dd(points, 0, i);

        num = 1;
        for (int j = 0; j < i; ++j)
            num *= (x - points[i]->x);

        p += d*num;
    }

    return p;
}

