CC = gcc
SRC = $(wildcard *.c)
NAME = ragnarok
OBJ = $(SRC:%.c=%.o)
RM = rm -f
CFLAGS = -W -Wall -Werror
LDFLAGS = -L. -lmy

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
