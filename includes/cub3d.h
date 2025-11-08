#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "../minilibx-linux-master/mlx.h"
# include <strings.h>
# include <string.h>
# include <stdio.h>

# define BLOCK_SIZE 60
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

typedef struct s_player
{
	int	position[2];
}	t_player;

typedef struct s_cub3d
{
	char		**map;
	int			map_len[2];
	int			resolution[2];
	t_player	player;
	void		*mlx;
	void		*mlx_win;
}	t_cub3d;

int put_frame(void *mlx, void *mlx_win, t_cub3d data);
int	init_data(t_cub3d *data, char **av);
int moves(int keycode, t_cub3d *data);

#endif