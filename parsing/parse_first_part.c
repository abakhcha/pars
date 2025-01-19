#include "cub3d.h"

void free_global(t_global *global)
{
	if(global->real_map)
        ft_doublepointerfree(global->real_map);
	if(global->map)
        ft_doublepointerfree(global->map);
	if(global->no)
        free(global->no);
	if(global->so)
        free(global->so);
	if(global->we)
        free(global->we);
	if(global->ea)
        free(global->ea);
	if(global->f)
        free(global->f);
	if(global->c)
        free(global->c);
    free(global);
}

size_t	ft_countwords(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

size_t	ft_getwordlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

void	ft_freearray(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, ft_getwordlen(s + j, c));
		if (!*(array + i))
		{
			ft_freearray(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}
// char	*ft_strtrim_free(char *str)
// {
// 	char	*tmp;

// 	if (!str)
// 		return (NULL);
// 	tmp = ft_strtrim(str);
// 	free(str);
// 	return (tmp);
// }

char	*my_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1 == 0)
		s1 = "";
	x = 0;
	y = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (x < (int)ft_strlen(s1))
	{
		x[str] = x[s1];
		x++;
	}
	while (y < (int)ft_strlen(s2))
		x++[str] = y++[s2];
	x[str] = '\0';
	return (str);
}

char	*free_join(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp1;

	tmp = s1;
	tmp1 = my_strjoin(tmp, s2);
	free(s1);
	return (tmp1);
}

char	*ft_strneww(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > (int)ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = ft_strneww(len);
	if (!str)
		return (NULL);
	j = start;
	str[len] = '\0';
	while (len-- && s[j])
		str[i++] = s[j++];
	return (str);
}

void	ft_doublepointerfree(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	negative;
	int i;

	negative = 1;
	i = 0;
	res = 0;
	while(str[i])
	{
		if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r' && (str[i] < '0' || str[i] > '9'))
			error_print("Error\nmixed int and chars\n");
		i++;
	}
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

char	**doublepointercopy(char **map)
{
	int		i;
	char	**test;

	i = 0;
	while (map[i])
		i++;
	test = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		test[i] = ft_strdup(map[i]);
		i++;
	}
	test[i] = NULL;
	ft_doublepointerfree(map);
	return (test);
}

void	error_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit(1);
}



int	is_space(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

char	*ft_strtrim(char *s1)
{
	size_t	start;
	size_t	end;
	char	*dup;

	if (!s1)
		return (NULL);
	start = 0;
	if (!s1[start])
	{
		dup = ft_strdup("");
		return (dup);
	}
	while (s1[start] && is_space(s1[start]) != 0)
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && is_space(s1[end]) != 0)
		end--;
	dup = (char *)malloc(end - start + 2);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1 + start, end - start + 2);
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i < (dstsize - 1)) && src[i] && dstsize > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	s2 = (char *)malloc((size + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}






/**************   additional functions ****************/


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

// void	check_border_top(t_map *s_map)
// {
// 	int	i;

// 	i = 0;
// 	while (s_map->map[0] && s_map->map[0][i])
// 	{
// 		if (s_map->map[0][i] != '1' && s_map->map[0][i] != ' ')
// 			ft_error("Error\nMap error\n", "");
// 		i++;
// 	}
// }

// void	get_map(t_map *s_map)
// {
// 	int	i;

// 	i = 0;
// 	while (s_map->map[i])
// 		i++;
// 	s_map->height = i;
// 	s_map->map_copy = (char **)ft_calloc(s_map->height + 1, sizeof(char *));
// 	i = 0;
// 	while (s_map->map[i])
// 	{
// 		s_map->map_copy[i] = ft_strdup(s_map->map[i]);
// 		i++;
// 	}
// }
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
void get_infos_from_map(char **str, t_global *global)
{
    int flag;
    int j;
    char *tmp;
    
    j = 0;
    flag = 0;
    while(str[j])
    {
        if(all_elements(global) == 1)
        {
            global->index = j;
            break;
        }
        tmp = ft_strtrim(str[j]);
        if (ft_strncmp(tmp, "NO", 2) == 0)
        {
            fill_elements(global, tmp, 1); 
            free(tmp);
        }
        else if (ft_strncmp(tmp, "SO", 2) == 0)
        {
            fill_elements(global, tmp, 2); 
            free(tmp);
        }
        else if (ft_strncmp(tmp, "WE", 2) == 0)
        {
            fill_elements(global, tmp, 3); 
            free(tmp);
        }
        else if (ft_strncmp(tmp, "EA", 2) == 0)
        {
            fill_elements(global, tmp, 4); 
            free(tmp);
        }
        else if (ft_strncmp(tmp, "F", 1) == 0)
        {
            fill_elements(global, tmp, 5); 
            free(tmp);
        }
        else if (ft_strncmp(tmp, "C", 1) == 0)
        {
            fill_elements(global, tmp, 6);
            free(tmp);
        }
        else if(ft_strlen(tmp) != 0)
            error_print("Error\nchek the lines between elements");
        else
            free(tmp);
        j++;
    }
}

int map_size(t_global *global)
{
    int i;
    int size;

    size = 0;
    i = global->index;
    while(global->map && global->map[i])
    {
        i++;
        size++;
    }
    return (size);
}
int	ft_doublepointerlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// char **map_trim(t_global *global, int i)
// {
//     int last_index;
//     int start_index;
//     char **tmp;
//     int j;
    
//     last_index = i;
//     start_index = 0;
//     tmp = NULL;
//     j = 0;
//     // while(!ft_strtrim(global->real_map[last_index]))
//     //     last_index--;
//     while(!ft_strtrim(global->real_map[last_index]))
//     {
//         start_index++;
//     }
//     printf("=%s=\n",global->real_map[last_index]);
//     while(last_index < start_index)
//     {
//         tmp[j] = ft_strdup(global->real_map[start_index]);
//         start_index++;
//         j++;
//     }
//     return tmp;
// }

void get_realmap(t_global *global, int size)
{
	int		i;
	int		j;

	j = 0;
	global->real_map = malloc((size + 1) * sizeof(char *));
	if (!global->real_map)
		error_print("alloc erro\n");
	i = global->mapstart;
	while (global->map[i] && i <= global->mapend)
	{
		global->real_map[j] = ft_strdup(global->map[i]);
		i++;
		j++;
	}
	global->real_map[j] = (NULL);
    // global->real_map = map_trim(global,j--);
}

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

int	chek_walls2(t_global *global, int i, int j)
{
	if ((global->real_map[i][j] == '0'
		|| global->real_map[i][j] == 'E'
		|| global->real_map[i][j] == 'W'
		|| global->real_map[i][j] == 'N'
		|| global->real_map[i][j] == 'S')
		&& (j == 0 || i == 0 || global->real_map[i + 1] == NULL
		|| global->real_map[i][j + 1] == '\0'
		|| global->real_map[i - 1][j] == ' '
		|| global->real_map[i + 1][j] == ' '
		|| global->real_map[i][j - 1] == ' '
		|| global->real_map[i][j + 1] == ' '))
		return (1);
	return (-1);
}

void	check_walls(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (global->real_map[i])
	{
		j = 0;
		while (global->real_map[i][j])
		{
			if (chek_walls2(global, i, j) == 1)
			{
				error_print("Error\ncheck ur walls pls\n");
			}
			if (global->real_map[i][j] == '0'
				&& (!global->real_map[i][j + 1]
				|| !global->real_map[i - 1][j]
				|| !global->real_map[i + 1][j]
				|| !global->real_map[i][j - 1]))
			{
				{
					error_print("Error\ncheck ur walls pls\n");
				}
			}
			j++;
		}
		i++;
	}
}

void check_emptyline(t_global *global)
{
	int	i;
	char *tmp;

	i = 0;
	while (global->real_map[i])
	{
		tmp = ft_strtrim(global->real_map[i]);
        if(tmp[0] == '\0')
        {
            free(tmp);
            error_print("Error\nemptyline\n");
        }
        free(tmp);
	    i++;
	}
}
int	rgb_format(char *str)
{
	int	def;
	int	i;

	i = 1;
	def = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else if (str[i] == ','
			&& ((str[i - 1] >= '0'
					&& str[i - 1] <= '9')
				|| str[i - 1] == ' '))
		{
			def += 1;
			i++;
		}
		else
			break ;
	}
	if (str[i] == '\0' && def == 2)
		return (1);
	return (-1);
}
// void check_rgb_format(t_global *global)
// {
// 	char **tmp1;
// 	int i;
// 	char **tmp2;

// 	i = 0;
// 	if(rgb_format(global->c + 1) == -1)
// 		error_print("Error\nCheck ur rgb format");
// 	tmp1 = ft_split(global->c + 1 , ',');
// 	while(tmp1[i])
// 	{
// 		if(ft_atoi(tmp1[i]) > 255)
// 			error_print("Error\nCheck ur rgb");
// 		tmp2 = ft_split(tmp1[i], ' ');
// 		if(ft_doublepointerlen(tmp2) != 1)
// 		{
// 			error_print("Error\nCheck ur rgb format");
// 		}
// 		i++;
// 	}
// }
void check_rgb_format(t_global *global)
{
    char **tmp1;
    int i;
    char **tmp2;
    i = 0;

    if (rgb_format(global->c + 1) == -1)
	{
		free_global(global);
        error_print("Error\nCheck your RGB format");
	}
    tmp1 = ft_split(global->c + 1, ',');
    while (tmp1[i])
    {
        if (ft_atoi(tmp1[i]) > 255)
        {
            ft_doublepointerfree(tmp1);
            error_print("Error\nCheck your RGB values");
        }
        tmp2 = ft_split(tmp1[i], ' ');
        if (!tmp2)
        {
            ft_doublepointerfree(tmp1);
            error_print("Error\nMemory allocation failed");
        }
        if (ft_doublepointerlen(tmp2) != 1)
        {
            ft_doublepointerfree(tmp2);
            ft_doublepointerfree(tmp1);
            error_print("Error\nCheck your RGB format");
        }
        ft_doublepointerfree(tmp2);
        i++;
    }
    ft_doublepointerfree(tmp1);
}


// void check_rgb_format1(t_global *global)
// {
// 	char **tmp1;
// 	int i;
// 	char **tmp2;

// 	i = 0;
// 	if(rgb_format(global->f + 1) == -1)
// 		error_print("Error\nCheck ur rgb format");
// 	tmp1 = ft_split(global->f + 1 , ',');
// 	while(tmp1[i])
// 	{
// 		if(ft_atoi(tmp1[i]) > 255)
// 			error_print("Error\nCheck ur rgb");
// 		tmp2 = ft_split(tmp1[i], ' ');
// 		if(ft_doublepointerlen(tmp2) != 1)
// 		{
// 			error_print("Error\nCheck ur rgb format");
// 		}
// 		i++;
// 	}
// }

void check_rgb_format1(t_global *global)
{
    char **tmp1;
    int i;
    char **tmp2;
    i = 0;

    if (rgb_format(global->f + 1) == -1)
	{
		free_global(global);
        error_print("Error\nCheck your RGB format");
	}
    tmp1 = ft_split(global->f + 1, ',');
    while (tmp1[i])
    {
        if (ft_atoi(tmp1[i]) > 255)
        {
            ft_doublepointerfree(tmp1);
            error_print("Error\nCheck your RGB values");
        }
        tmp2 = ft_split(tmp1[i], ' ');
        if (!tmp2)
        {
            ft_doublepointerfree(tmp1);
            error_print("Error\nMemory allocation failed");
        }
        if (ft_doublepointerlen(tmp2) != 1)
        {
            ft_doublepointerfree(tmp2);
            ft_doublepointerfree(tmp1);
            error_print("Error\nCheck your RGB format");
        }
        ft_doublepointerfree(tmp2);
        i++;
    }
    ft_doublepointerfree(tmp1);
}

void	store_rgb(t_global *global)
{
	char	**tmp;

	tmp = ft_split(global->c + 1, ',');
	global->ceiling_red = ft_atoi(tmp[0]);
	global->ceiling_green = ft_atoi(tmp[1]);
	global->ceiling_blue = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
	tmp = ft_split(global->f + 1, ',');
	global->floor_red = ft_atoi(tmp[0]);
	global->floor_green = ft_atoi(tmp[1]);
	global->floor_blue = ft_atoi(tmp[2]);
	ft_doublepointerfree(tmp);
}

void	check_for_textures_extension(t_global *global)
{
	if (ft_strncmp(global->so + ft_strlen(global->so) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nSO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->no + ft_strlen(global->no) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nNO texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->we + ft_strlen(global->we) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nWE texture must be a .xpm file\n");
	}
	if (ft_strncmp(global->ea + ft_strlen(global->ea) - 4, ".xpm", 4) != 0)
	{
		free_global(global);
		error_print("Error\nEA texture must be a .xpm file\n");
	}
}

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
    int j = 0;
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
	check_for_textures_extension(global);
	// check_for_textures_extension2(global);
	check_textures_extention(global);
	exit(1);
    while(global->real_map[j])
    {
        printf("%s\n",global->real_map[j]);
        j++;
    }
    // while(ft_strncmp(global->real_map[0], "", 1) == 0)
    // {
        // printf("==%d==\n",ft_strncmp(global->real_map[0], "", 1));
        // j++;
    // }
    // exit(1);
	// get_specified_data(s_map);
	// skip_useless_data(s_map);
	// check_for_max_255(s_map->f, s_map->c_p);
	// check_for_max_255(s_map->c, s_map->f_p);
	// check_textures(s_map);
	// s_map->map += 6;
	// check_border_top(s_map);
	// check_for_unwanted_chars(s_map);
	// init_sec_part(s_map);
	// get_map(s_map);
	// make_the_map_rectangle(s_map, get_max_len(s_map));
}
