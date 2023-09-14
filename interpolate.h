#ifndef INTERPOLATE_H
#define INTERPOLATE_H

#include "point.h"

double interpolate_lagrange(point_t **points, unsigned int size, double x);

double interpolate_newton(point_t **points, unsigned int size, double x);

#endif

