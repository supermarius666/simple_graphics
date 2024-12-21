#include "graphics.h"


void create_scaling_matrix(float matrix[4][4], int sx, int sy, int sz)
{
    matrix[0][0] = sx;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = sy;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = sz;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

void	apply_transformation(t_vec4 *vec, float m[4][4]) 
{
    int x;
    int y;
    int z;
    int w;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	w = vec->w;
    vec->x = (int)(m[0][0] * x + m[0][1] * y + m[0][2] * z + m[0][3] * w);
    vec->y = (int)(m[1][0] * x + m[1][1] * y + m[1][2] * z + m[1][3] * w);
    vec->z = (int)(m[2][0] * x + m[2][1] * y + m[2][2] * z + m[2][3] * w);
    vec->w = (int)(m[3][0] * x + m[3][1] * y + m[3][2] * z + m[3][3] * w);
}






