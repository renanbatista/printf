NAME=libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = printf
RM = rm -f
INC = -I./include
SRC_DIR = src/
SRC_LIBFT = ./libft
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))

all: libft $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	ar rcs $(NAME) $@

$(NAME): $(OBJ) libft.a
	ar rcs $(NAME) $^
#	 $(MAKE) -C $(SRC_LIBFT)
#	 cp $(SRC_LIBFT)/libft.a .

libft: 
	$(MAKE) -C $(SRC_LIBFT) --no-print-directory
	cp $(SRC_LIBFT)/libft.a .

clean:
	$(MAKE) clean -C $(SRC_LIBFT)
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C $(SRC_LIBFT)
	$(RM) $(NAME)
	$(RM) libft.a

re: fclean all

.PHONY:	all clean fclean re bonus rebonus libft