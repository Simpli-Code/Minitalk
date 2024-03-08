# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 08:36:42 by chruhin           #+#    #+#              #
#    Updated: 2024/03/06 16:08:50 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program namey
NAME1				=		server
NAME2				=		client

# Directories
SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

# Source files
DIRS1				=		server utils
DIRS2				=		client utils

SRCS1				=		$(foreach dir,$(DIRS1),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))
SRCS2				=		$(foreach dir,$(DIRS2),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

# Object files
OBJS1				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS1))
OBJS2				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS2))


# Header files
INCS				=		$(addprefix -I, $(INC_DIR))

# Compiler flags
CFLAGS				=		-Wall -Wextra -Werror

# Cleanup
RM					=		rm -rf

# No exceptions
.PHONY:						all clean fclean re

# Targets
all:						$(OBJ_DIR) $(NAME1) $(NAME2)

# Create a Dir for obj
$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
# Compiling obj
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Compiling exec
$(NAME1): 					$(OBJS1)
							@$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1)

$(NAME2): 					$(OBJS2)
							@$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

# Remove object files
clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}"'Deleted Object Files'"${RST}\n"

# Remove obj & executable files
fclean:						clean
							@$(RM) $(NAME1) $(NAME2)
							@printf "${RED}"'and the Executable File'"${RST}\n"
# remove all & recompile
re:							fclean all

# colors
GRN					=		\e[1;32m
RED					=		\e[1;31m
RST					=		\e[0m
