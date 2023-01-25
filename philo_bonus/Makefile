# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:48:00 by juwkim            #+#    #+#              #
#    Updated: 2023/01/25 02:20:25 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and flags

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -march=native -O2 -pipe -MMD -fsanitize=address -fsanitize=leak

# Define the directories

SRC_DIR				:=	sources
BUILD_DIR			:=	build
INC_DIR				:=	-I includes

# Define the source files

SRCS				:=	$(patsubst %.c, $(SRC_DIR)/%_bonus.c, main.c ft_time.c parsing.c philosopher.c print.c simulate.c)
OBJS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS				:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRCS))

# Define the variables for progress bar

TOTAL_FILES			:=	$(shell find $(SRC_DIR) -type f -name "*.c" | wc -l)
COMPILED_FILES		:=	0
STEP				:=	100

# Define the target

NAME				:=	philo_bonus

# Define the rules

all:
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "\n$(MAGENTA)[$(NAME)]:\tLinking Success\n$(DEF_COLOR)"

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[$(NAME)]:\t[%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

dir_guard:
	@mkdir -p $(BUILD_DIR)

norm:
	@(norminette | grep Error) || (printf "$(GREEN)[$(NAME)]:\tNorminette Success\n$(DEF_COLOR)")

clean:
	@$(RM) -r $(BUILD_DIR)
	@printf "$(BLUE)[$(NAME)]:\tobj. dep. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CYAN)[$(NAME)]:\texec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)[$(NAME)]:\tCleaned and rebuilt everything!\n$(DEF_COLOR)"

.PHONY: all clean fclean re dir_guard norm

#Colors

DEF_COLOR	=	\033[1;39m
GRAY		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
MAGENTA		=	\033[1;95m
CYAN		=	\033[1;96m
WHITE		=	\033[1;97m

-include $(DEPS)
