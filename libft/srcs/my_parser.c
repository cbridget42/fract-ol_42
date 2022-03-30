/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:05:13 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/30 16:36:29 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	pars(int *i, va_list *args, t_flags *f_arg, const char *format)
{
	(*i)++;
	set_zero(f_arg);
	check_flags(i, args, f_arg, format);
	return (get_extension(i, args, f_arg, format));
}

void	check_flags(int *i, va_list *args, t_flags *f_arg, const char *format)
{
	while (format[*i])
	{
		if (format[*i] == '-' || format[*i] == '+' || format[*i] == ' '
			|| format[*i] == '0' || format[*i] == '#')
			save_flag(format[*i], i, f_arg);
		else if (ft_isdigit(format[*i]) || format[*i] == '*')
			save_width(format, i, f_arg, args);
		else if (format[*i] == '.')
			save_precision(format, i, f_arg, args);
		else
			break ;
	}
}

void	save_flag(char f, int *i, t_flags *f_arg)
{
	if (f == '-')
		f_arg->flag_m = 1;
	else if (f == '+')
		f_arg->flag_p = 1;
	else if (f == ' ')
		f_arg->flag_s = 1;
	else if (f == '0')
		f_arg->flag_n = 1;
	else
		f_arg->flag_o = 1;
	(*i)++;
}

void	save_width(const char *format, int *i, t_flags *f_arg, va_list *args)
{
	if (format[*i] == '*')
	{
		f_arg->width = va_arg(*args, int);
		if (f_arg->width < 0)
		{
			f_arg->flag_n = 0;
			f_arg->flag_m = 1;
			f_arg->width *= -1;
		}
		(*i)++;
	}
	else
	{
		f_arg->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	save_precision(const char *format, int *i,
						t_flags *f_arg, va_list *args)
{
	(*i)++;
	f_arg->flag_prec = 1;
	if (format[*i] == '*')
	{
		f_arg->precision = va_arg(*args, int);
		if (f_arg->precision < 0)
		{
			f_arg->precision = 0;
			f_arg->flag_prec = 0;
		}
		(*i)++;
	}
	else
	{
		f_arg->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}
