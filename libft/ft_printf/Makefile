# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 10:16:09 by mring             #+#    #+#              #
#    Updated: 2025/03/18 17:04:02 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf ft_printf_print
SRCS		= $(addsuffix .c, $(SRC))

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
				@$(CC) ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: 		$(OBJ_DIR) $(OBJS)
			@ar rcs ${NAME} ${OBJS}
			@echo "/// $(NAME) compiled ///"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@rm -rf ${OBJ_DIR}
				@echo "/// cleanin printf ///"

fclean: 		clean
				@rm -f ${NAME}
				@echo "/// fcleanin printf ///"

re: 			fclean all

.PHONY:			all clean fclean re