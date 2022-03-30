/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:20:31 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:43:51 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision_form(t_flags *f_arg, char convers)
{
	int	j;
	int	i;
	int	sign;

	sign = 0;
	j = f_arg->precision;
	i = f_arg->tmp - f_arg->numb_simb;
	if (f_arg->result[f_arg->numb_simb] == '-'
		|| f_arg->result[f_arg->numb_simb] == '+' || f_arg->flag_s)
		sign += 1;
	else if ((convers == 'x' || convers == 'X') && f_arg->flag_o)
		sign += 2;
	j = f_arg->precision + sign;
	while (i < j && convers != 's')
	{
		if (add_pr(f_arg, sign))
			return (1);
		j--;
	}
	precision_form_two(f_arg, convers);
	return (0);
}

void	precision_form_two(t_flags *f_arg, char convers)
{
	if ((convers == 's' || f_arg->result[f_arg->numb_simb] == '0')
		&& !f_arg->flag_o)
	{
		if ((f_arg->tmp - f_arg->numb_simb) > f_arg->precision)
			f_arg->tmp = f_arg->numb_simb + f_arg->precision;
	}
	if (!f_arg->precision && f_arg->flag_p
		&& f_arg->result[f_arg->numb_simb + 1] == '0')
		f_arg->tmp -= 1;
}

int	add_pr(t_flags *f_arg, int sign)
{
	int	i;

	i = f_arg->tmp;
	if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
	{
		f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg->result)
			return (clean_flags(f_arg, 0));
	}
	while (f_arg->numb_simb + sign <= i)
	{
		f_arg->result[i + 1] = f_arg->result[i];
		i--;
	}
	f_arg->result[++i] = '0';
	f_arg->result[++f_arg->tmp] = '\0';
	return (0);
}
