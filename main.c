#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(unsigned int argc, char *argv[])
{
    if (argc != 2)
        return EXIT_FAILURE;
    
    point_t **points;
    unsigned int size;
    
    double value = atof(argv[1]);

    scanf("%u", &size);
    create_points(&points, size);
    print_points(points, size);
    
    free_points(&points, size);
    
    return EXIT_SUCCESS;
}
