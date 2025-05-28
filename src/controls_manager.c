#include "libft.h"
#include "so_long.h"

int	key_esc(t_vars *vars)
{
	ft_printf("(ESC) ¡Bye! :D\n");
	free_resources(vars);
	exit(1);
}

int	key_w(t_vars *vars)
{
	if (vars->can_move && vars->map[vars->player_pos_row
			- 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row -= 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_s(t_vars *vars)
{
	if (vars->can_move && vars->map[vars->player_pos_row
			+ 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row += 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_a(t_vars *vars)
{
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column - 1] != '1')
	{
		vars->player_pos_column -= 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_d(t_vars *vars)
{
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column + 1] != '1')
	{
		vars->player_pos_column += 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}
