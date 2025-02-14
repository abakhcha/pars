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
