# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 16:15:57 by mring             #+#    #+#              #
#    Updated: 2025/04/01 13:49:34 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fractol
#CFLAGS			:= -Wextra -Wall -Werror -Wunreachable-code -Ofast # -march=native -mtune=native -funroll-loops -fomit-frame-pointer -flto -finline-functions -ftree-vectorize -fno-math-errno -fno-trapping-math
CFLAGS 			:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -ffast-math -march=native -funroll-loops -fomit-frame-pointer -fno-math-errno
LIBMLX			:= ./MLX42

HEADERS			:= -I ./include -I $(LIBMLX)/include
LIBS			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC_DIR			:= src
SRC				:= main hooks fractals utils init
SRCS			:= $(addsuffix .c, $(SRC))
OBJ_DIR			:= obj
OBJS			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_PATH		:=	./libft
LIBFT			:=	$(LIBFT_PATH)/libft.a

all: libmlx $(NAME)

libmlx:
				@cmake $(LIBMLX) -B $(LIBMLX)/build
				@make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)


$(NAME): $(OBJS) $(LIBFT)
				@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)
				@echo "/// compiled: $(NAME) ///"			

${LIBFT}:
				@$(MAKE) -C $(LIBFT_PATH)

clean:
				@rm -rf $(OBJ_DIR)
				@rm -rf $(LIBMLX)/build

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY: all, clean, fclean, re, libmlx