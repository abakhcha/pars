#include "cub3d.h"


void	check_textures_extention(t_global *global)
{
	if (open(global->no, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->so, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->we, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
	else if (open(global->ea, O_RDWR) == -1)
	{
		free_global(global);
		error_print("Error\ncheck ur textures files\n");
	}
}

void check_extentions_format(t_global *global)
{
	char **tmp;

	tmp = ft_split(global->no,' ');
	if(ft_doublepointerlen(tmp)!= 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!");
	}
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->so,' ');
	if(ft_doublepointerlen(tmp)!= 2)
	{
		free_global(global);
		ft_doublepointerfree(tmp);
		error_print("Error\ncheck your elements!");
	}
	ft_doublepointerfree(tmp);
}

void check_extentions_format2(t_global *global)
{
	char **tmp;

	tmp = ft_split(global->we,' ');
	if(ft_doublepointerlen(tmp)!= 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!");
	}
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->ea,' ');
	if(ft_doublepointerlen(tmp)!= 2)
	{
		ft_doublepointerfree(tmp);
		free_global(global);
		error_print("Error\ncheck your elements!");
	}
	ft_doublepointerfree(tmp);
}

void parse_first_part(t_global *global, int fd)
{    
    // int j = 0;
	global->map = fill_map(fd);
	init(global);
	get_infos_from_map(global->map, global);
	check_extentions_format(global);
	check_extentions_format2(global);
	check_rgb_format(global);
	check_rgb_format1(global);
	store_rgb(global);
    check_emptymap(global);
    check_emptymap2(global);
    get_realmap(global,map_size(global));
    check_for_unwanted_chars(global);
    check_emptyline(global);
    check_walls(global);
    player_exists(global);
	// check_for_textures_extension(global);
	// check_textures_extention(global);
	// exit(1);
    // while(global->real_map[j])
    // {
    //     printf("%s\n",global->real_map[j]);
    //     j++;
    // }
}
