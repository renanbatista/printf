NAME=libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf utils
BONUS = ft_printf_bonus utils_bonus
RM = rm -f
INC = -I./include
SRC_DIR = src/
SRC_LIBFT = ./libft
SRC_LIBFT_A = $(SRC_LIBFT)/libft.a
OBJ = $(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))
BONUS_OBJS = $(addprefix $(SRC_DIR), $(addsuffix .o, $(BONUS)))

all: libft $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(SRC_LIBFT_A)
	ar rcsT $(NAME) $(OBJ) $(SRC_LIBFT_A)

bonus:	libft $(BONUS_OBJS) $(SRC_LIBFT_A)
	@$(MAKE) --no-print-directory OBJ="$(BONUS_OBJS)"

libft: 
	@$(MAKE) -C $(SRC_LIBFT) --no-print-directory

clean:
	$(MAKE) clean -C $(SRC_LIBFT)
	rm -f $(OBJ)
	rm -f $(BONUS_OBJS)

fclean:	clean
	$(MAKE) fclean -C $(SRC_LIBFT)
	$(RM) $(NAME)
	$(RM) libft.a

re: fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean re libft bonus rebonus