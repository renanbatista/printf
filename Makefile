NAME=libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf utils
RM = rm -f
INC = -I./include
SRC_DIR = src/
SRC_LIBFT = ./libft
SRC_LIBFT_A = $(SRC_LIBFT)/libft.a
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))

all: libft $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(SRC_LIBFT_A)
	ar rcsT $(NAME) $(OBJ) $(SRC_LIBFT_A)

libft: 
	$(MAKE) -C $(SRC_LIBFT) --no-print-directory

clean:
	$(MAKE) clean -C $(SRC_LIBFT)
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C $(SRC_LIBFT)
	$(RM) $(NAME)
	$(RM) libft.a

re: fclean all

.PHONY:	all clean fclean re bonus rebonus libft