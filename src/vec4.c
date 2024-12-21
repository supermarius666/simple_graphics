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

void	draw_line(t_vec4 *start, t_vec4 *end, t_data *data)
{
	int			er[2];
	t_vec4		curr;

	curr.x = start->x;
	curr.y = start->y;
	curr.z = 0;
	curr.color = 0x86a97b;
	er[0] = abs(end->x - start->x) - abs(end->y - start->y);
	while (curr.x != end->x || curr.y != end->y)
	{
		if (is_on_screen(&curr))
			draw_vec(&curr, data);
		er[1] = 2 * er[0];
		if (er[1] > -abs(end->y - start->y))
		{
			er[0] -= abs(end->y - start->y);
			curr.x += (start->x < end->x);
			curr.x -= (end->x < start->x);
		}
		if (er[1] < abs(end->x - start->x))
		{
			er[0] += abs(end->x - start->x);
			curr.y += (start->y < end->y);
			curr.y -= (end->y < start->y);
		}
	}
}


