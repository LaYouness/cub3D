CC = cc
C_FLAGS = -Wall -Wextra -Werror -Wno-incompatible-pointer-types
INCDIR = includes
SRCDIR = src
OBJDIR = obj
BINDIR = bin
HEADERS = cub3d.h
SRC = main.c init_data.c put_frame.c key_hooks.c
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
NAME = cub3d
LIBS = ./minilibx-linux-master/libmlx_Linux.a -lXext -lX11 -lm -lz

all: $(BINDIR)/$(NAME) $(INCDIR)/$(HEADERS) 

$(BINDIR)/$(NAME): $(OBJ) | $(BINDIR)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(BINDIR)

re: fclean all

.PHONY: all clean fclean re
