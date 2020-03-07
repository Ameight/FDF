.PHONY : all re clean fclean

.SUFFIXES :
.SUFFIXES : .c .o .h .a

VPATH = .:libft:/usr/local/include:/usr/local/lib

override CC = gcc

override CFLAGS = -I. -Ilibft -Wall -Wextra -Werror

MLXFLAGS = 	-I /usr/local/include \
			-L /usr/local/lib -lmlx \
			-I includes \
			-framework OpenGL \
			-framework AppKit \

FTFLAGS = -Llibft -lft

FDFFLAGS = $(CFLAGS) $(FTFLAGS) $(MLXFLAGS)

MAKE_LIBFT = $(MAKE) -C libft

NAME = fdf

SRC =	sources/main.c \
      	sources/draw_lines.c \
      	sources/events.c \
      	sources/fdf.c \
      	sources/handler.c \
      	sources/lines.c \
      	sources/projection.c \
      	sources/struct.c \

OBJ = $(SRC:.c=.o)

all ::
	$(MAKE) -C libft
all :: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FDFFLAGS) $(OBJ) -o $@

clean :
	$(MAKE_LIBFT) clean
	$(RM) -f $(OBJ)

fclean : clean
	$(MAKE_LIBFT) fclean
	$(RM) -f $(NAME)

re : fclean all
