/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:52:56 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/30 16:33:39 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "ft_printf.h"

void	parser(int argc, char **argv, t_envf *env_f)
{
	int	i;

	i = 1;
	if (argc < 2 || argc == 3 || argc > 4)
		error_m(5);
	if (!ft_strncmp(argv[i], "Mandelbrot", 11))
		env_f->flags.frc = 0;
	else if (!ft_strncmp(argv[i], "Julia", 6))
	{
		env_f->flags.frc = 1;
		env_f->coords.j_x = 0.28;
		env_f->coords.j_y = 0.0113;
	}
	else if (!ft_strncmp(argv[i], "Burning_ship", 13))
		env_f->flags.frc = 2;
	else
		error_m(55);
	if (argc == 4 && env_f->flags.frc == 1)
	{
		env_f->coords.j_x = ft_atof(argv[2]);
		env_f->coords.j_y = ft_atof(argv[3]);
	}
	else if (argc == 4)
		error_m(5);
}

void	error_m(int err)
{
	if (err == 5)
		ft_printf("error: wrong number of arguments\n");
	else if (err == 55)
		ft_printf("error: first arg is invalid\n");
	else
		ft_printf("error: wrong number for Julia\n");
	ft_printf("first arg: type of fractal (Mandelbrot or Julia or Burning_ship)\n");
	ft_printf("fot Julia you can enter real and imaginary parts (format like 0.05)\n");
	exit(err);
}

double	ft_atof(char *num)
{
	double	res;
	double	tmp;
	int	overflow;
	int	i;

	i = -1;
	overflow = 0;
	ch_db(num);
	res = ft_atoi_s(num, &overflow);
	if (overflow)
		error_m(155);
	while (*num != '.' && (ft_isdigit(*num) || *num == '-'))
		num++;
	if (*num != '.')
		return (ft_atofr(res));
	num++;
	if (!ft_isdigit(*num))
		error_m(155);
	tmp = ft_atoi_s(num, &overflow);
	if (overflow)
		error_m(155);
	while (ft_isdigit(num[++i]))
		tmp /= 10;
	return (ft_atofr(res + tmp));
}

void	ch_db(char *str)
{
	if (*str != '-' && !ft_isdigit(*str) && *str != '.')
		error_m(160);
	str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	else
		error_m(160);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		error_m(160);
}

double	ft_atofr(double x)
{
	if (x > 2)
		return (2);
	else
		return (x);
}

int	ft_atoi_s(const char *str, int *overflow)
{
	size_t			i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = skipp(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > 2147483650)
			break ;
	}
	if (result > 2147483647 && sign == 1)
		*overflow = 1;
	if (result > 2147483648 && sign == -1)
		*overflow = 1;
	return ((int)result * sign);
}

int	skipp(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i ++;
	}
	return (i);
}
