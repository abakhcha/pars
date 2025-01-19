CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc
NAME = cub3D

SRC =  get_next_line.c get_next_line_utils.c main.c parse_first_part.c additional_functions1.c additional_functios.c additional_functions_2.c additional_functions_3.c additional_functions_4.c pars.c\
		pars2.c pars3.c pars4.c pars5.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all





