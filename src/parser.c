/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:52:56 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/31 16:51:25 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
//#include "ft_printf.h"

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

double	ft_atof(char *num)
{
	double	res;
	int		overflow;
	int		i;
	int		sign;

	sign = 1;
	i = -1;
	overflow = 0;
	if (*num == '-')
	{
		sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		error_m(160);
	res = ft_atoi_s(num, &overflow, &sign);
	num++;
	if (overflow)
		error_m(155);
	while (ft_isdigit(*num))
		num++;
	return (ft_atof_two(num, &overflow, &sign, res));
}

double	ft_atof_two(char *num, int *overflow, int *sign, int res)
{
	double	tmp;

	if (*num == '.')
		num++;
	else
		error_m(160);
	if (!ft_isdigit(*num))
		error_m(160);
	tmp = ft_atoi_s(num, overflow, sign);
	while (ft_isdigit(*num))
	{
		tmp /= (double)10;
		num++;
	}
	if (*num)
		error_m(160);
	if (*overflow)
		error_m(155);
	return (ft_atofr((res + tmp) * *sign));
}

double	ft_atofr(double x)
{
	if (x > 2)
		return (2);
	else
		return (x);
}

int	ft_atoi_s(const char *str, int *overflow, int *sign)
{
	size_t			i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > 2147483650)
			break ;
	}
	if (result > 2147483647 && *sign == 1)
		*overflow = 1;
	if (result > 2147483648 && *sign == -1)
		*overflow = 1;
	return ((int)result);
}
