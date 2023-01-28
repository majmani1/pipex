NAME=	pipex
cc=	cc
CFLAGS=	-Wall -Wextra -Werror

AF=    pipe.c   \
pipex_utils.c    \
pipex_utils2.c    \
split.c    \

bonus= bonus/ft_here_doc.c \
bonus/get_next_line_utils.c	\
bonus/get_next_line.c \
bonus/pipe_bonus.c \
bonus/pipex_utils_bonus.c \
bonus/pipex_utils2.c \
bonus/split_bonus.c \

OBJ=    $(AF:.c=.o)

BONUS=	$(bonus:.c=.o)

all:    $(NAME)

$(NAME):    $(OBJ)
	$(cc) $(CFLAGS) $(OBJ) -o $(NAME)

bonus :  $(BONUS)
	$(cc) $(CFLAGS) $(BONUS) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS)

fclean:    clean
	rm -f $(NAME)

re: fclean all
