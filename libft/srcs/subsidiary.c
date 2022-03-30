/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:37:50 by cbridget          #+#    #+#             */
/*   Updated: 2021/12/01 17:43:27 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_arg(va_list *args, t_flags *f_arg, char convers)
{
	char	numb[18];
	char	*line;

	if (convers == 'i' || convers == 'd' || convers == 'u')
		line = get_arg_two(args, f_arg, convers, numb);
	else if (convers == 'p' || convers == 'x' || convers == 'X')
	{
		if (convers == 'p')
			ft_itoa_base(va_arg(*args, unsigned long), 16, numb + 2, 0);
		else
			ft_itoa_base(va_arg(*args, unsigned int), 16, numb + 2, 0);
		if (convers == 'X')
			change_case(numb + 2);
		line = reverse(numb + 2);
		line = line - put_0x(f_arg, convers, numb);
	}
	else
	{
		if (f_arg->flag_p)
			f_arg->flag_p = 0;
		line = va_arg(*args, char *);
	}
	return (put_arg(f_arg, line));
}

char	*get_arg_two(va_list *args, t_flags *f_arg, char convers, char *numb)
{
	char	*line;
	int		tmp;

	tmp = 0;
	if (convers == 'u')
		ft_itoa_base(va_arg(*args, unsigned int), 10, numb, 0);
	else
		tmp = get_arg_three(args, f_arg, numb);
	if (tmp < 0 || f_arg->flag_p)
		line = (reverse(&numb[1])) - 1;
	else
		line = reverse(numb);
	return (line);
}

int	get_arg_three(va_list *args, t_flags *f_arg, char *numb)
{
	int	tmp;

	tmp = va_arg(*args, int);
	if (tmp < 0)
	{
		numb[0] = '-';
		if (tmp == -2147483648)
			ft_itoa_base(2147483648, 10, &numb[1], 0);
		else
			ft_itoa_base(-tmp, 10, &numb[1], 0);
	}
	else if (f_arg->flag_p)
	{
		numb[0] = '+';
		ft_itoa_base(tmp, 10, &numb[1], 0);
	}
	else
		ft_itoa_base(tmp, 10, numb, 0);
	return (tmp);
}

int	put_arg(t_flags *f_arg, char *line)
{
	int	length;

	if (!line)
		line = "(null)";
	length = ft_strlen(line);
	while ((unsigned int)(length + f_arg->numb_simb) >= f_arg->size)
	{
		f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg->result)
			return (clean_flags(f_arg, 0));
	}
	f_arg->tmp = f_arg->numb_simb;
	while (*line)
	{
		f_arg->result[f_arg->tmp++] = *line;
		line++;
	}
	f_arg->result[f_arg->tmp] = '\0';
	return (0);
}

int	put_0x(t_flags *f_arg, char convers, char *num)
{
	if (convers == 'p' || ((convers == 'x' || convers == 'X') && f_arg->flag_o))
	{
		num[0] = '0';
		if (convers == 'X' && *(num + 2) != '0')
		{
			num[1] = 'X';
			return (2);
		}
		else if ((convers == 'x' && *(num + 2) != '0') || convers == 'p')
		{
			num[1] = 'x';
			return (2);
		}
		f_arg->flag_o = 0;
	}
	return (0);
}
