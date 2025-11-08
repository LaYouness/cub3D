#include "../includes/cub3d.h"

static void	init_map(t_cub3d *data)
{
	char	*map_str[] = {"1111111111111111",
						"1000000000000001",
						"1010000000010001",
						"101P000000010001",
						"1000000000000001",
						"1000001111000001",
						"1000000000000001",
						"1000000000000001",
						"1111111111111111"};
	int		i;
	int		j;

	data->map_len[0] = strlen(map_str[0]);
	data->map_len[1] = 9;
	data->map = malloc(sizeof(char *) * (data->map_len[1] + 1));
	i = 0;
	while (i < data->map_len[1])
	{
		data->map[i] = strdup(map_str[i]);
		j = 0;
		while (j < data->map_len[0])
		{
			if (data->map[i][j] == 'P')
			{
				data->player.position[0] = j * BLOCK_SIZE + BLOCK_SIZE / 2;
				data->player.position[1] = i * BLOCK_SIZE + BLOCK_SIZE / 2;
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	data->map[i] = NULL;
}

int	init_data(t_cub3d *data, char **av)
{

	(void)av;
	init_map(data);
    data->resolution[0] = data->map_len[0] * BLOCK_SIZE;
    data->resolution[1] = data->map_len[1] * BLOCK_SIZE;
	return (0);
}