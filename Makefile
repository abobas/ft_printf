# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/29 01:21:19 by abobas        #+#    #+#                  #
#    Updated: 2020/09/03 21:09:55 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SRC_DIR	=	./src/

SRC = 		printf.o \
			printf_struct.o \
			printf_read_1.o \
			printf_read_2.o \
			printf_read_3.o \
			printf_write_1.o \
			printf_write_2.o \
			printf_arg_d.o \
			printf_arg_u.o \
			printf_arg_x_1.o \
			printf_arg_x_2.o \
			printf_arg_s.o \
			printf_arg_p.o \
			printf_arg_c.o \
			printf_arg_per.o \
			printf_utility_1.o \
			printf_utility_2.o \
			printf_utility_3.o

SRC :=		$(SRC:%=$(SRC_DIR)%)

HEADER = 	src/printf.h

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	ar rcs $(NAME) $(SRC)

%.o: %.c $(HEADER)
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all