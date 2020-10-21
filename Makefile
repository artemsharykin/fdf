NAME    =   fdf
#                       *****   OBJECT FILES    ******
SRC     =   input_read.o\
            init.o\
            draw.o\
            draw_menu.o\
            color.o\
            primitives.o\
            events.o\
            events_operations.o\
            events_operations_2.o\
            validate.o\
            project.o\
            exit_free.o\
            lines.o\
            fdf.o

SRCDIR      =   $(addprefix ./sources/, $(SRC))
LIBDIR      =   ./libft/
MLXDIR      =   ./minilibx_macos/
INCLUDES    =   ./includes/
# INC_FLAG    =   $(addprefix -I, $(INCLUDES))
#                       *****   COLLORS         *****
GREEN       =   \033[0;32m
RED         =   \033[0;31m
YELLOW      =   \033[0;33m
RESET       =   \033[0m
CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
all: $(NAME)
%.o: %.c
				@echo "$(GREEN)$(NAME): $(RESET) [Compilation:$(YELLOW) $@$(RESET)]"
				@$(CC) -o $@ -c $< $(INC_FLAG) #$(CFLAGS)
lib:
				@echo "$(NAME): creating LIBFT...$(GREEN)OK!$(RESET)"
				@make -C $(LIBDIR)
mlx:
				@echo "$(NAME): creating MLX...$(GREEN)OK!$(RESET)"
				@make -C $(MLXDIR)
$(NAME): mlx lib $(SRCDIR)
				$(CC) $(CFLAGS) $(SRCDIR) -o $(NAME) -L $(LIBDIR) -lft -L $(MLXDIR)
				@echo "$(NAME): creating $(NAME)...$(GREEN) OK!$(RESET)"
clean:
				@make -C $(LIBDIR) clean
				@make -C $(MLXDIR) clean
				@rm -rf $(SRCDIR)
fclean:
				@make -C $(LIBDIR) fclean
				@make -C $(MLXDIR) clean
				@rm -rf $(SRCDIR)
				@rm -rf $(NAME)
#               @echo "$(NAME): delete all files...$(GREEN) OK!$(RESET)"
re: fclean all
.PHONY: re clean fclean all lib
