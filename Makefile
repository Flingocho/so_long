############################################################################################################
# Variables

# Project name
NAME			= so_long

# Directories
SRC_DIR			= src
INC_DIR			= include
OBJ_DIR			= objs
DEP_DIR			= dependencies

# Dependencies
LIBFT			= $(DEP_DIR)/libft
MINILIBX		= $(DEP_DIR)/minilibx-linux
FTPRINTF		= $(DEP_DIR)/ft_printf

# Include files
INCLUDES		= $(INC_DIR)/so_long.h $(INC_DIR)/libft.h $(INC_DIR)/ft_printf.h $(INC_DIR)/mlx.h

# List of source files
SRCS_FILES		= so_long.c controls_manager.c counter_render.c counter_render_2.c \
				  flood_fill.c init_misc.c map_operators.c map_check.c enemy.c \
				  misc_functions.c render_window.c terminate_process.c
					
# Complete paths					
SRCS			= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

# Objects
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/$(SRC_DIR)/%.o, $(SRCS))

# Compiler settings
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR)
LIBS			= -L$(FTPRINTF) -lftprintf -L$(LIBFT) -lft -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Colors
GREEN			= \033[0;32m
UGREEN			= \033[4;32m
RED				= \033[0;31m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
CYAN			= \033[0;36m
NC				= \033[0m # No color

############################################################################################################
# Rules

all: lib mlx printf ascii_art $(NAME)

ascii_art:
	@if ! $(MAKE) -q $(NAME); then \
		printf "$(CYAN)\n"; \
		printf "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ \n"; \
		printf "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ \n"; \
		printf "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n"; \
		printf "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║\n"; \
		printf "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n"; \
		printf "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n"; \
		printf "                                                 by jvidal-t\033[0m\n"; \
		echo "$(YELLOW)\nCreating program...$(GREEN)"; \
		$(MAKE) -s $(NAME); \
	else \
		echo "$(GREEN)[$(NAME)] is already up to date.$(NC)"; \
	fi

bonus: all

lib:
	@make -C $(LIBFT)

mlx:
	@make -C $(MINILIBX)

printf:
	@make -C $(FTPRINTF)

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) && \
	printf "$(UGREEN)\n%s$(NC)" "[$(NAME)]"; printf "$(GREEN)%s$(NC)\n" " Compiled successfully."

# Rule to compile source files
$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	@echo -n "█"
	@$(CC) $(CFLAGS) -c -o $@ $<

# Rule to remove all object files
clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@make -C $(MINILIBX) clean
	@make -C $(FTPRINTF) clean
	@printf "$(RED)%s$(NC)\n" "[$(NAME)] Object files cleaned."

# Rule to remove all generated files
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(MINILIBX) clean
	@make -C $(FTPRINTF) fclean
	@printf "$(RED)%s$(NC)\n" "[$(NAME)] Cleaned successfully."

# Rule to rebuild the project from scratch
re: fclean all

# Declaration of phony targets (not associated with files)
.PHONY: all bonus lib mlx printf clean fclean re
