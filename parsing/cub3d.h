#ifndef CUB3D_H
#define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_global
{
	char			**map;
    char			**tmp;
	char			**real_map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
    int				no_flag;
	int				so_flag;
	int				we_flag;
	int				ea_flag;
	int				f_flag;
	int				c_flag;
	int				map_height;
	int				map_width;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
    int             index;
    int             mapstart;
    int             mapend;
}					t_global;


//parsing

void parse_first_part(t_global *global, int fd);
void	error_print(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strtrim_free(char *str, char *rts);
char	*ft_strneww(size_t n);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, int start, size_t len);
void	ft_doublepointerfree(char **str);
int	ft_atoi(char *str);
char	**doublepointercopy(char **map);
int	is_space(char c);
char	*ft_strtrim(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*ft_strjoin_l(char const *s1, char const *s2);
int	checkextention(char *str);
void free_global(t_global *global);
size_t	ft_countwords(char *s, char c);
size_t	ft_getwordlen(char *s, char c);
void	ft_freearray(size_t i, char **array);
// static char	**split(char *s, char c, char **array, size_t words_count);
char	**ft_split(char *s, char c);
char	*my_strjoin(char const *s1, char const *s2);
char	*free_join(char *s1, char *s2);
char	*ft_strneww(size_t n);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, int start, size_t len);
void	ft_doublepointerfree(char **str);
int	ft_atoi(char *str);
char	**doublepointercopy(char **map);
void	error_print(char *str);
int	is_space(char c);
char	*ft_strtrim(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*str_join(char *s1, char *s2);
char	**fill_map(int fd);
void init(t_global *global);
void fill_elements(t_global *global, char *tmp, int x);
int all_elements(t_global *global);
void get_infos_from_map(char **str, t_global *global);
int map_size(t_global *global);
int	ft_doublepointerlen(char **str);
void get_realmap(t_global *global, int size);
void check_emptymap(t_global *global);
void check_emptymap2(t_global *global);
void player_exists(t_global *global);
void	check_for_unwanted_chars(t_global *global);
int	chek_walls2(t_global *global, int i, int j);
void	check_walls(t_global *global);
void check_emptyline(t_global *global);
int	rgb_format(char *str);
void check_rgb_format(t_global *global);
void check_rgb_format1(t_global *global);
void	store_rgb(t_global *global);
void	check_for_textures_extension(t_global *global);
void	check_textures_extention(t_global *global);
void check_extentions_format(t_global *global);
void check_extentions_format2(t_global *global);
void parse_first_part(t_global *global, int fd);

#endif