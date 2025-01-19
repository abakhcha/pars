#include "cub3d.h"

void check_emptymap(t_global *global)
{
    int i = global->index;
    int z = 0;
    char *tmp;

    while(global->map[i])
    {
        tmp = ft_strtrim(global->map[i]);
        if(tmp[0] == '1')//must stream it
        {
            z += 1;
            global->mapstart = i;
            free(tmp);
            break;
        }
        else if(tmp[0] != '\0')
        {
            free(tmp);
            error_print("Error\ncheck the file that contains the map");
        }
        free(tmp);
        i++;
    }
    if(z == 0)
    {
        free(tmp);
        error_print("Error\nmap does not exitst or walls != 1");
    }
}
void check_emptymap2(t_global *global)
{
    int i = ft_doublepointerlen(global->map) - 1;
    int z = 0;
    char *tmp;

    while(i >= global->mapstart)
    {
        tmp = ft_strtrim(global->map[i]);
        if(tmp[0] == '1')
        {
            z += 1;
            global->mapend = i;
            free(tmp);
            break;
        }
        else if(tmp[0] != '\0')
        {
            free(tmp);
            error_print("Error\ncheck the file that contains the map");
        }
        free(tmp);
        i--;
    }
    if(z == 0)
    {
        free(tmp);
        error_print("Error\nmap does not exitst or walls problem");
    }
}

void player_exists(t_global *global)
{
	int	i;
	int	j;
    int def;

	i = 0;
    def = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if ( global->real_map[i][j] == 'N' || global->real_map[i][j] == 'S'
				|| global->real_map[i][j] == 'W' || global->real_map[i][j] == 'E')
            {    
                def += 1;
            }
			j++;
		}
		i++;
	}
    if(def != 1)
        error_print("Error\ncheck the player\n");
}

void	check_for_unwanted_chars(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if (global->real_map[i][j] != '1' && global->real_map[i][j] != '0'
				&& global->real_map[i][j] != 'N' && global->real_map[i][j] != 'S'
				&& global->real_map[i][j] != 'W' && global->real_map[i][j] != 'E'
				&& global->real_map[i][j] != ' ')
				error_print("Error\nUnwanted character in map\n");
			j++;
		}
		i++;
	}
}