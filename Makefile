CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc
NAME = cub3D

SRC =  parsing/get_next_line.c parsing/get_next_line_utils.c parsing/main.c parsing/parse_first_part.c\
  	   parsing/additional_functions1.c parsing/additional_functios.c parsing/additional_functions_2.c \
	   parsing/additional_functions_3.c parsing/additional_functions_4.c parsing/pars.c\
		parsing/pars2.c parsing/pars3.c parsing/pars4.c parsing/pars5.c parsing/init.c
		

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





