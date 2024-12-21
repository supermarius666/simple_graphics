#include "graphics.h"

int	basic_keys(int keycode, t_data *data)
{ 
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->win);
		printf("EXIT PROGRAM!!\n");
        exit(0);
    }
	if (keycode == 43) // '+' key for zoom in
    { 
        data->cam.zoom += 1;        
	}
	if (keycode == 45) // '-' key for zoom out
    { 
        data->cam.zoom -= 1;        
	}
	printf("key: %d\n", keycode);
	return (0);
 }
 