#include "graphics.h"

int	basic_keys(int keycode, t_data *data)
 {

    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->win);
		printf("EXIT PROGRAM!!\n");
        exit(0);
    }
	return (0);
 }