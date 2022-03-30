/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_c%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:05:22 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:44:13 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_res_c(va_list *args, t_flags *f_arg, char convers)
{
	char	tmp;

	if (convers == 'c')
		tmp = va_arg(*args, int);
	else
		tmp = '%';
	if (f_arg->width > 1)
		return (create_c_one(f_arg, tmp, convers));
	else
	{
		if (put_symbol(f_arg, tmp, 0))
			return (1);
		return (put_symbol(f_arg, '\0', 1));
	}
}

int	create_c_one(t_flags *f_arg, char tmp, char convers)
{
	if (f_arg->flag_m)
	{
		if (put_symbol(f_arg, tmp, 0))
			return (1);
		while (f_arg->width > 1)
		{
			if (put_symbol(f_arg, ' ', 0))
				return (1);
			f_arg->width--;
		}
	}
	else
	{
		if (create_c_two(f_arg, tmp, convers))
			return (1);
	}
	if (put_symbol(f_arg, '\0', 1))
		return (1);
	return (0);
}

int	create_c_two(t_flags *f_arg, char tmp, char convers)
{
	while (f_arg->width > 1)
	{
		if (convers != 'c' && f_arg->flag_n)
		{
			if (put_symbol(f_arg, '0', 0))
				return (1);
		}
		else
		{
			if (put_symbol(f_arg, ' ', 0))
				return (1);
		}
		f_arg->width--;
	}
	if (put_symbol(f_arg, tmp, 0))
		return (1);
	return (0);
}

int	put_symbol(t_flags *f_arg, char symbol, char mod)
{
	if ((unsigned int)(f_arg->numb_simb + 1) >= f_arg->size)
		f_arg->result = my_realloc(f_arg, 0);
	if (!f_arg->result)
		return (clean_flags(f_arg, 0));
	if (mod)
		f_arg->result[f_arg->numb_simb] = symbol;
	else
		f_arg->result[f_arg->numb_simb++] = symbol;
	return (0);
}
