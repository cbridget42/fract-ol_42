/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:08:21 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:45:34 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct a_flags
{
	char			flag_p;
	char			flag_m;
	char			flag_s;
	char			flag_n;
	char			flag_o;
	char			flag_prec;
	int				width;
	int				precision;
	char			*result;
	unsigned int	size;
	int				numb_simb;
	int				tmp;
}		t_flags;

int		ft_printf(const char *format, ...);
int		pars(int *i, va_list *args, t_flags *f_arg, const char *format);
void	check_flags(int *i, va_list *args, t_flags *f_arg, const char *format);
void	save_flag(char f, int *i, t_flags *f_arg);
void	save_width(const char *format, int *i, t_flags *f_arg, va_list *args);
void	save_precision(const char *format, int *i, t_flags *f_arg,
			va_list *args);
t_flags	*start_struct(void);
int		get_extension(int *i, va_list *args, t_flags *f_arg,
			const char *format);
int		extension_two(va_list *args, t_flags *f_arg, char convers);
int		get_arg(va_list *args, t_flags *f_arg, char convers);
char	*get_arg_two(va_list *args, t_flags *f_arg, char convers, char *numb);
int		get_arg_three(va_list *args, t_flags *f_arg, char *numb);
int		put_arg(t_flags *f_arg, char *line);
char	*my_realloc(t_flags *f_arg, char mod);
char	*my_realloc_two(t_flags *f_arg);
int		clean_flags(t_flags *f_arg, char mod);
void	ft_itoa_base(unsigned long numb, int base, char *line, int i);
char	*reverse(char *line);
void	change_case(char *line);
int		put_0x(t_flags *f_arg, char convers, char *num);
int		put_result(t_flags *f_arg);
int		create_res_c(va_list *args, t_flags *f_arg, char convers);
int		create_c_one(t_flags *f_arg, char tmp, char convers);
int		create_c_two(t_flags *f_arg, char tmp, char convers);
int		put_symbol(t_flags *f_arg, char symbol, char mod);
int		precision_form(t_flags *f_arg, char convers);
void	precision_form_two(t_flags *f_arg, char convers);
int		add_pr(t_flags *f_arg, int sign);
int		add_width(t_flags *f_arg, char convers);
int		add_width_two(t_flags *f_arg);
int		width_start(t_flags *f_arg);
int		width_end(t_flags *f_arg);
int		add_space(t_flags *f_arg, char convers);
void	set_zero(t_flags *f_arg);

#endif
