# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 18:29:51 by ymoukhli          #+#    #+#              #
#    Updated: 2019/03/04 22:33:43 by ymoukhli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		make re -C libft
		gcc -Wall -Wextra -Werror *.c -o fdf -I ./minilibx_macos -L libft -L ./minilibx_macos -lmlx -lft -framework opengl -framework appkit

clean:
		make clean -C libft

fclean:
		make fclean -C libft
		rm -rf fdf

re: fclean all
