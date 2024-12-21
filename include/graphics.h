#ifndef	GRAPHICS_H
# define GRAPHICS_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# define WIDTH 1280
# define HEIGHT 960
# define MIN_SCALE 1
// # define MAX_SCALE 10
// # define OFFSET_X WIDTH / 2
// # define OFFSET_Y HEIGHT / 4
# define M_PI 3.14159265358979323846


/* matrix 4x4 for transformations */
typedef struct s_matrix
{
	float	**m[4][4];
}	t_matrix;

/* vector 4 */
typedef struct s_vec4
{
	int	x;
	int	y;
	int	z;
	int	w;
	int	color;
}	t_vec4;

/* image struct */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		en;
}	t_img;

/* data stuct */
typedef struct s_data
{
	t_img	img;
	void	*win;
	void	*mlx;
}	t_data;


/* utils */
t_vec4	*new_vec4(int x, int y, int z, int color);

/* draw functions */
void	draw_vec(t_vec4 *vec, t_data *data);
void	draw_line(t_vec4 *start, t_vec4 *end, t_data *data);

/* matrix functions */


/* keys */
int	basic_keys(int keycode, t_data *data);

#endif