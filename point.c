#include <stdio.h>
#include <stdlib.h>

#include "point.h"

void create_points(point_t ***points, unsigned int size)
{
    *points = (point_t **)malloc(size * sizeof(point_t *));   
    
    for (unsigned int i = 0; i < size; i++)
    {
        (*points)[i] = (point_t *)malloc(sizeof(point_t));
        scanf("%lf %lf", &(*points)[i]->x, &(*points)[i]->y);
    }
}

void print_points(point_t **points, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        printf("%lf %lf\n", points[i]->x, points[i]->y);
}

void free_points(point_t ***points, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        free((*points)[i]);
    free(*points);
}

