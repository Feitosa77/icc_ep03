#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

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
    double interval[2]; /* [min, max] */

    scanf("%u", &size);
    create_points(&points, size);
    get_interval(points, size, interval);

    if (value < interval[0] || value > interval[1]) { 
        fprintf(stderr, "Valor xe invalido\n");
        return EXIT_FAILURE;
    }

    double time_lagrange, time_newton, aux;

    LIKWID_MARKER_INIT;

    char MARKER_NAME[] = "MarkerL";

    /* Interpolacao */
    LIKWID_MARKER_START(MARKER_NAME);
        time_lagrange = timestamp();
            aux = interpolate_lagrange(points, size, value);
        time_lagrange = timestamp() - time_lagrange;
    LIKWID_MARKER_STOP(MARKER_NAME);

    printf("%lf\n", aux);

    MARKER_NAME[6] += 2; /* MARKER_NAME := "MarkerN" */

    
    LIKWID_MARKER_START(MARKER_NAME);
        time_newton = timestamp();
            aux = interpolate_newton(points, size, value);
        time_newton = timestamp() - time_newton;
    LIKWID_MARKER_STOP(MARKER_NAME);

    LIKWID_MARKER_CLOSE;

    printf("%lf\n", aux);

    printf("%lf\n%lf\n", time_newton, time_lagrange);
    
    free_points(&points, size);

    return EXIT_SUCCESS;
}
