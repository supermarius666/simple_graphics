#include "graphics.h"

t_vec4	*new_vec4(int x, int y, int z, int color)
{
	t_vec4	*vec;

	vec = (t_vec4 *)malloc(sizeof(t_vec4));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = 1;
	vec->color = color;
	return (vec);
}

/*	TODO: Implement advanced cliping
*	point.x >= -point.w && point.x <= point.w &&
*   point.y >= -point.w && point.y <= point.w &&
*   point.z >= 0 && point.z <= point.w
*/
static int	is_on_screen(t_vec4 *vec)
{
	return (vec->x >= 0 && vec->x < WIDTH && vec->y >= 0 && vec->y < HEIGHT);
}


void	draw_vec(t_vec4 *vec, t_data *data)
{
	char	*addr;

	if (is_on_screen(vec))
	{
		addr = data->img.addr + (vec->y * data->img.ll + vec->x * (data->img.bpp / 8));
		*(unsigned int *)addr = vec->color;
	}
}


