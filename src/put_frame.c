#include "../includes/cub3d.h"

int put_frame(void *mlx, void *mlx_win, t_cub3d data)
{
	int	pixel[2];

	mlx_clear_window(mlx, mlx_win);
	bzero((void *)pixel, sizeof(int) * 2);
	while (pixel[1] < data.resolution[1])
	{
		pixel[0] = 0;
		while (pixel[0] < data.resolution[0])
		{
			if (pixel[0] > data.player.position[0] - 10 && pixel[0] < data.player.position[0] + 10
				&& pixel[1] > data.player.position[1] - 10 && pixel[1] < data.player.position[1] + 10)
				mlx_pixel_put(mlx, mlx_win, pixel[0], pixel[1], 0x00FF0000);
			else if (data.map[pixel[1] / BLOCK_SIZE][pixel[0] / BLOCK_SIZE] == '1')
				mlx_pixel_put(mlx, mlx_win, pixel[0], pixel[1], 0x00FFFFFF);
			pixel[0]++;
		}
		pixel[1]++;
	}
	return (0);
}