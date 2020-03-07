NAME 	= fdf
LIBFT 	= libft.a

CUR_DIR = $(shell pwd)
LIB_DIR = $(CUR_DIR)/libft
OBJ_DIR = $(CUR_DIR)/objects
SRC_DIR	= $(CUR_DIR)/sources

SRC		=	main.c 			\
      		brezeham.c      \
            draw_dots.c     \
            events.c        \
            fdf.c           \
            parser.c        \
            s_lines.c       \
            s_point.c 		\

OBJ 	=	$(SRC:.c=.o)

MLXFLAGS = 	-I /usr/local/include \
			-L /usr/local/lib -lmlx \
			-I includes \
			-framework OpenGL \
			-framework AppKit 			

SRCS 	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS 	= $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT_H = $(LIB_DIR)/includes
FDF_H 	= $(CUR_DIR)/includes

CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	make -C $(CUR_DIR) $(OBJS)

$(LIBFT):
	make -C $(LIB_DIR) -I$(LIBFT_H) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I$(LIBFT_H) -I$(FDF_H)

$(NAME):
	make -C $(CUR_DIR) $(LIBFT)
	make -C $(CUR_DIR) $(OBJ_DIR)
	$(CC) $(CCFLAGS) $(MLXFLAGS) -I$(LIBFT_H) -I$(FDF_H) $(LIB_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

clean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette
	
.PHONY: all clean fclean re norm