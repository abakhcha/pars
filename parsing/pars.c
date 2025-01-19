#include "cub3d.h"

char	**fill_map(int fd)
{

	char	*s1;
	char	*l;
	char	**map;

	if (fd == -1 || !fd)
		error_print("Error::can not open the file\n");
	l = get_next_line(fd);
	if (l == NULL)
		error_print("Error\nempty file \n");
	s1 = calloc(1, 1);
	while (l != NULL)
	{
		if (l[0] == '\n')
			s1 = str_join(s1, "  \n");
		else
			s1 = str_join(s1, l);
		free(l);
		l = get_next_line(fd);
	}
	map = ft_split(s1, '\n');
	free(s1);
	close(fd);
	return (map);
}


void init(t_global *global)
{
	global->no = NULL;
	global->so = NULL;
	global->we = NULL;
	global->ea = NULL;
	global->f = NULL;
	global->c = NULL;
	global->map_height = 0;
	global->map_width = 0;
	global->floor_red = 0;
	global->floor_green = 0;
	global->floor_blue = 0;
	global->ceiling_red = 0;
	global->ceiling_green = 0;
	global->ceiling_blue = 0;
    global->no_flag = 0;
	global->so_flag = 0;
	global->we_flag = 0;
	global->ea_flag = 0;
	global->f_flag = 0;
	global->c_flag = 0;
    global->index = 0;
    global->mapstart = 0;
}

void fill_elements(t_global *global, char *tmp, int x)
{
    if(x == 1)
    {
        global->no_flag += 1;
	    global->no = ft_strdup(tmp);
    }
    else if(x == 2)
    {
        global->so_flag += 1;
	    global->so = ft_strdup(tmp);
    }
    else if(x == 3)
    {
        global->we_flag += 1;
	    global->we = ft_strdup(tmp);
    }
    else if(x == 4)
    {
        global->ea_flag += 1;
	    global->ea = ft_strdup(tmp);
    }
    else if(x == 5)
    {
        global->f_flag += 1;
	    global->f = ft_strdup(tmp);
    }
    else if(x == 6)
    {
        global->c_flag += 1;
	    global->c = ft_strdup(tmp);
    }
}
int all_elements(t_global *global)
{
    if(global->no_flag == 1 && global->so_flag == 1 && global->we_flag == 1 
    && global->ea_flag == 1 && global->f_flag == 1 && global->c_flag == 1)
    {
        return 1;
    }
	return -1;
}
