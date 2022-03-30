/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:22:31 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:44:05 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_extension(int *i, va_list *args, t_flags *f_arg, const char *format)
{
	int	j;

	j = *i;
	(*i)++;
	if (format[j] == 'd' || format[j] == 'i' || format[j] == 's'
		|| format[j] == 'u' || format[j] == 'p' || format[j] == 'x'
		|| format[j] == 'X')
		return (extension_two(args, f_arg, format[j]));
	else if (format[j] == 'c' || format[j] == '%')
		return (create_res_c(args, f_arg, format[j]));
	else
	{
		free(f_arg->result);
		free(f_arg);
		return (-1);
	}
}

int	extension_two(va_list *args, t_flags *f_arg, char convers)
{
	if (get_arg(args, f_arg, convers))
		return (1);
	if (add_space(f_arg, convers))
		return (1);
	if (f_arg->flag_prec)
	{
		if (precision_form(f_arg, convers))
			return (1);
	}
	if (f_arg->width)
	{
		if (add_width(f_arg, convers))
			return (1);
	}
	if (convers != 'c' && convers != '%')
		f_arg->numb_simb = f_arg->tmp;
	return (0);
}

int	add_space(t_flags *f_arg, char convers)
{
	int	i;

	i = f_arg->tmp;
	if (!f_arg->flag_s)
		return (0);
	if (convers == 's' || f_arg->result[f_arg->numb_simb] == '-'
		|| f_arg->result[f_arg->numb_simb] == '+')
		return (0);
	if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
	{
		f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg->result)
			return (clean_flags(f_arg, 0));
	}
	while (f_arg->numb_simb <= i)
	{
		f_arg->result[i + 1] = f_arg->result[i];
		i--;
	}
	f_arg->result[++i] = ' ';
	f_arg->result[++f_arg->tmp] = '\0';
	if (f_arg->width && f_arg->flag_n && !f_arg->flag_prec)
		f_arg->width--;
	return (0);
}
