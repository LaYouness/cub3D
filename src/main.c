#include "../includes/cub3d.h"

int key_press(int keycode, void *param)
{
	t_cub3d *data;
	
	data = (t_cub3d *)param;
	return (moves(keycode, data));
}

int	leave(void *param)
{
	t_cub3d *data;
	int i;

	data = param;
	i = 0;
	while (i < data->map_len[1] && data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int main(int ac ,char **av)
{
	t_cub3d data;

	if (ac != 1)
		return (1);
	(void)av;
	if (init_data(&data, av))
		return (1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.resolution[0], data.resolution[1], "cub3d");
	put_frame(data.mlx, data.mlx_win, data);
	mlx_hook(data.mlx_win,2, 1L<<0, key_press, &data);
	mlx_hook(data.mlx_win,17, 1L<<0, leave, &data);
	mlx_loop(data.mlx);
	return (0);
}
