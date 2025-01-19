#ifndef CUB3D_H
#define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


typedef struct s_elements
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	char			**map;
}					t_elements;

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

void parse_first_part(t_global *global, int fd);
void	error_print(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(char *s1, char *s2, size_t n);
// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strtrim_free(char *str, char *rts);


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

char	*ft_strjoin_l(char const *s1, char const *s2);

#endif