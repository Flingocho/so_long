#include "libft.h"
#include "so_long.h"

static int	alloc_buffer(t_vars *vars)
{
	vars->buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!vars->buffer)
		return (-1);
	vars->fd = open(vars->map_path, O_RDONLY);
	if (vars->fd < 0)
	{
		free(vars->buffer);
		vars->buffer = NULL;
		return (-1);
	}
	vars->bytes_read = read(vars->fd, vars->buffer, BUFF_SIZE);
	if (vars->bytes_read <= 0)
	{
		free(vars->buffer);
		vars->buffer = NULL;
		close(vars->fd);
		return (-1);
	}
	vars->buffer[vars->bytes_read] = '\0';
	close(vars->fd);
	return (1);
}

int	check_map_name(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 4)
		return (-1);
	while (i > 0)
	{
		if (argv[--i] == '.')
			return (ft_strncmp(&argv[i], ".ber", 5) == 0 ? 1 : -1);
	}
	return (-1);
}

int	set_matrix(t_vars *vars)
{
	if (alloc_buffer(vars) == -1)
	{
		if (vars->fd >= 0)
			close(vars->fd);
		if (vars->buffer)
			free(vars->buffer);
		return (-1);
	}
	ft_printf("%s\n", vars->buffer);
	vars->map = ft_split(vars->buffer, '\n');
	if (!vars->map)
	{
		free(vars->buffer);
		return (-1);
	}
	free(vars->buffer);
	return (1);
}

void	calculate_map_size(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_columns = ft_strlen(vars->map[0]);
	while (vars->map[i])
		i++;
	vars->map_rows = i;
}
