/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:04 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:44:48 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_flags	*f_arg;
	va_list	args;
	int		i;

	i = 0;
	f_arg = start_struct();
	if (!f_arg)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (pars(&i, &args, f_arg, format))
				return (-1);
			continue ;
		}
		if ((unsigned int)f_arg->numb_simb == f_arg->size)
			f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg->result)
			return (clean_flags(f_arg, 1));
		f_arg->result[f_arg->numb_simb++] = format[i++];
	}
	va_end(args);
	return (put_result(f_arg));
}

t_flags	*start_struct(void)
{
	t_flags	*f_arg;

	f_arg = (t_flags *)malloc(sizeof(t_flags) * 1);
	if (!f_arg)
		return ((void *)0);
	f_arg->size = 20;
	f_arg->numb_simb = 0;
	f_arg->result = my_realloc(f_arg, 1);
	if (!f_arg->result)
	{
		free(f_arg);
		return ((void *)0);
	}
	return (f_arg);
}

int	put_result(t_flags *f_arg)
{
	int	length;

	length = f_arg->numb_simb;
	f_arg->result[f_arg->numb_simb] = '\0';
	write(1, f_arg->result, length);
	free(f_arg->result);
	free(f_arg);
	return (length);
}

void	set_zero(t_flags *f_arg)
{
	f_arg->flag_m = 0;
	f_arg->flag_n = 0;
	f_arg->flag_o = 0;
	f_arg->flag_p = 0;
	f_arg->flag_s = 0;
	f_arg->flag_prec = 0;
	f_arg->width = 0;
	f_arg->precision = 0;
}
