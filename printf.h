/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:35:14 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:35:14 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H
# include <stdarg.h>

typedef struct		s_check
{
	int				index;
	int				temp_counter;
	int				flag_justify_true;
	int				flag_padding_true;
	int				precision_true;
	int				precision_value;
	int				field_width_true;
	int				field_width_value;
	char			conversion_value;
	char			*temp_string;
	char			*arg_string;
	int				int_negative_true;
	int				null_true;
}					t_check;

int					ft_printf(const char *format, ...);
t_check				ft_read(const char *format, t_check check, va_list args);
t_check				ft_set_check(void);
t_check				ft_reset_check(t_check check);
t_check				ft_read_field_width_1(va_list args, t_check check);
t_check				ft_read_field_width_2(const char *format, t_check check);
t_check				ft_read_precision(const char *format, va_list args, \
					t_check check);
t_check				ft_write(va_list args, t_check check);
t_check				ft_make_field_width(t_check check);
t_check				ft_make_temp(t_check check);
t_check				ft_make_s(va_list args, t_check check);
t_check				ft_make_arg(va_list args, t_check check);
t_check				ft_make_c(va_list args, t_check check);
t_check				ft_make_d(va_list args, t_check check);
t_check				ft_make_u(va_list args, t_check check);
t_check				ft_make_x(va_list args, t_check check);
t_check				ft_make_x_2(va_list args, t_check check);
t_check				ft_make_p(va_list args, t_check check);
t_check				ft_make_per(t_check check);
int					ft_atoi(const char *str);
void				ft_putchar(unsigned char c);
char				*ft_itoa_base(unsigned long n, int base);
char				*ft_itoa(int n);
char				*ft_str_upper(char *str);
char				*ft_ident(char *str);
int					ft_strlen(char *str);
void				ft_putstr(char *s, t_check check);
char				*ft_strdup(char *s1);

#endif
