#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "interpolate.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return EXIT_FAILURE;
    
    point_t **points;
    unsigned int size;
    
    double value = atof(argv[1]);
    double time_lagrange, time_newton, aux;

    scanf("%u", &size);
    create_points(&points, size);

    /* Interpolacao */
    time_lagrange = timestamp();
        aux = interpolate_lagrange(points, size, value);
    time_lagrange = timestamp() - time_lagrange;

    printf("%lf\n", aux);

    time_newton = timestamp();
        aux = interpolate_newton(points, size, value);
    time_newton = timestamp() - time_newton;

    printf("%lf\n", aux);

    printf("%lf\n%lf\n", time_newton, time_lagrange);
    
    free_points(&points, size);

    return EXIT_SUCCESS;
}
