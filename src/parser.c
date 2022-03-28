/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:52:56 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/28 16:40:50 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

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
		write(1, "error: wrong number of arguments\n", 28);
	else if (err == 55)
		write(1, "error: first arg is invalid\n", 28);
	else
		write(1, "error: wrong number for Julia\n", 30);
	write(1, "first arg: type of fractal (Mandelbrot or Julia)\n", 49);
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
	res = ft_atoi_s(num, &overflow);
	if (overflow)
		error_m(155);
	while (*num != '.' && ft_isdigit(*num))
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
