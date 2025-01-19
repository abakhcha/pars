#include "cub3d.h"

int	checkextention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}

int main(int ac ,char **av)
{
	t_global *global;
	int		fd;


	if (ac != 2)
		error_print("Error\ncheck your arguments\n");
    
	global = (t_global *)malloc(sizeof(t_global));
	// s_map->player = malloc(sizeof(t_pl));
	// s_map->textures = malloc(sizeof(t_textures));
	fd = open(av[1], O_RDONLY, 0777);
	if (checkextention(av[1]) == -1)
		error_print("Error\nextention error \n");
	else if (fd == -1)
		error_print("Error\nFile not found\n");
	else
		parse_first_part(global, fd);

    exit(1);
	// seconde_part(data, s_map);
}