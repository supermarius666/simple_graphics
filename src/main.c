#include "graphics.h"

int main(void)
{
	t_data	data;
	t_vec4	*vec1;
	// float	mat[4][4];
	// t_vec4	*vec2;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Graphics");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.ll, &data.img.en);


	vec1 = new_vec4(WIDTH/2, HEIGHT/2, 0,  0x00FF0000);
	// vec2 = new_vec4(WIDTH, HEIGHT, 0,  0x86a97b);

	data.cam.zoom = 1;
	

	draw_square(vec1, 100, &data);
	// draw_vec(vec2, &data);
	//draw_line(vec1, vec2, &data);

	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, basic_keys, &data);
	mlx_loop(data.mlx);
}