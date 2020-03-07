NAME 	= myfdf
LIBFT 	= libft.a

CUR_DIR = $(shell pwd)
LIB_DIR = $(CUR_DIR)/libft
OBJ_DIR = $(CUR_DIR)/objects
SRC_DIR	= $(CUR_DIR)

SRC		=	fdf.c			\
			read_map.c 		


OBJ 	=	$(SRC:.c=.o)

SRCS 	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS 	= $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFT_H = $(LIB_DIR)/includes
FDF_H 	= $(CUR_DIR)

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
	$(CC) $(CCFLAGS) -I$(LIBFT_H) -I$(FDF_H) $(LIB_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

clean:
	@make -C $(LIB_DIR) fclean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette fdf.c fdf.h read_map.c
	
.PHONY: all clean fclean re norm