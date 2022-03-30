/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:43:02 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:44:29 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_width(t_flags *f_arg, char convers)
{
	if (f_arg->flag_n && convers != 's' && !f_arg->precision
		&& !f_arg->flag_prec)
	{
		if (f_arg->result[f_arg->numb_simb] == '-'
			|| f_arg->result[f_arg->numb_simb] == '+')
			f_arg->width--;
		if ((convers == 'x' || convers == 'X') && f_arg->flag_o)
			f_arg->width -= 2;
		f_arg->precision = f_arg->width;
		if (precision_form(f_arg, convers))
			return (1);
	}
	else
	{
		if (add_width_two(f_arg))
			return (1);
	}
	return (0);
}

int	add_width_two(t_flags *f_arg)
{
	if (f_arg->flag_m)
	{
		if (width_end(f_arg))
			return (1);
	}
	else
	{
		if (width_start(f_arg))
			return (1);
	}
	return (0);
}

int	width_start(t_flags *f_arg)
{
	int	j;
	int	i;
	int	d;

	j = f_arg->width;
	i = f_arg->tmp - f_arg->numb_simb;
	d = f_arg->tmp + 1;
	while (i < j)
	{
		if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
		{
			f_arg->result = my_realloc(f_arg, 0);
			if (!f_arg->result)
				return (clean_flags(f_arg, 0));
		}
		while (f_arg->numb_simb <= --d)
			f_arg->result[d + 1] = f_arg->result[d];
		f_arg->result[++d] = ' ';
		f_arg->result[++f_arg->tmp] = '\0';
		d = f_arg->tmp;
		i++;
	}
	return (0);
}

int	width_end(t_flags *f_arg)
{
	int	j;
	int	i;

	j = f_arg->width;
	i = f_arg->tmp - f_arg->numb_simb;
	while (i < j)
	{
		if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
		{
			f_arg->result = my_realloc(f_arg, 0);
			if (!f_arg->result)
				return (clean_flags(f_arg, 0));
		}
		f_arg->result[f_arg->tmp++] = ' ';
		i++;
	}
	f_arg->result[f_arg->tmp] = '\0';
	return (0);
}
