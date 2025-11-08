#include "../includes/cub3d.h"

int check_collision(t_cub3d *data, int new_x, int new_y)
{
	int map_x;
	int map_y;
	int offset = 10;

	map_x = (new_x - offset) / BLOCK_SIZE;
	map_y = (new_y - offset) / BLOCK_SIZE;
	if (data->map[map_y][map_x] == '1')
		return (1);
	map_x = (new_x + offset) / BLOCK_SIZE;
	if (data->map[map_y][map_x] == '1')
		return (1);
	map_y = (new_y + offset) / BLOCK_SIZE;
	if (data->map[map_y][map_x] == '1')
		return (1);
	map_x = (new_x - offset) / BLOCK_SIZE;
	if (data->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int mv_left(t_cub3d *data)
{
	int new_x = data->player.position[0] - 1;
	
	if (!check_collision(data, new_x, data->player.position[1]))
		data->player.position[0] = new_x;
	put_frame(data->mlx, data->mlx_win, *data);
	return (0);
}

int mv_right(t_cub3d *data)
{
	int new_x = data->player.position[0] + 1;
	
	if (!check_collision(data, new_x, data->player.position[1]))
		data->player.position[0] = new_x;
	put_frame(data->mlx, data->mlx_win, *data);
	return (0);
}

int mv_up(t_cub3d *data)
{
	int new_y = data->player.position[1] - 1;
	
	if (!check_collision(data, data->player.position[0], new_y))
		data->player.position[1] = new_y;
	put_frame(data->mlx, data->mlx_win, *data);
	return (0);
}

int mv_down(t_cub3d *data)
{
	int new_y = data->player.position[1] + 1;
	
	if (!check_collision(data, data->player.position[0], new_y))
		data->player.position[1] = new_y;
	put_frame(data->mlx, data->mlx_win, *data);
	return (0);
}

int moves(int keycode, t_cub3d *data)
{
    printf("%d\n", keycode);
    if (keycode == LEFT)
        return (mv_left(data));
    if (keycode == UP)
        return (mv_up(data));
    if (keycode == DOWN)
        return (mv_down(data));
    if (keycode == RIGHT)
        return (mv_right(data));
    return (0);
}