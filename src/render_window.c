#include "libft.h"
#include "so_long.h"

static void	put_img(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (vars->map[y][x] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->endtile_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (vars->map[y][x] == ' ' || vars->map[y][x] == 'K' || vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (vars->map[y][x] == '@' || vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collectable_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (vars->map[y][x] == 'x' || vars->map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->endtile_end_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
}

void	render_window(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_rows > i)
	{
		j = 0;
		while (vars->map_columns > j)
		{
			put_img(vars, i, j);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < vars->map_columns)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_ptr, (i++)
			* SPRITE_SIZE, (vars->map_rows) * SPRITE_SIZE);
	if (vars->enemy_exists == 1 && vars->enemy_ptr != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_ptr,
			vars->enemy_pos_column * SPRITE_SIZE, vars->enemy_pos_row
			* SPRITE_SIZE);
	if (vars->player_ptr != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ptr,
			vars->player_pos_column * SPRITE_SIZE, vars->player_pos_row
			* SPRITE_SIZE);
}
