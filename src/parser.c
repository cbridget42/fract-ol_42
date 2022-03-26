/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:52:56 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/26 13:18:48 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	parser(int argc, char **argv, t_envf *env_f)
{
	int	i;

	i = 1;
	if (argc < 2)
		error_m(5);
	if (!ft_strncmp(argv[i], "Mandelbrot", 11))
		env_f->flags.frc = 0;
	else if (!ft_strncmp(argv[i], "Julia", 6))
		env_f->flags.frc = 1;
	else
		error_m(55);
}

void	error_m(int err)
{
	if (err == 5)
		write(1, "error: not enough arguments\n", 28);
	else if (err == 55)
		write(1, "error: first arg is invalid\n", 28);
	write(1, "first arg: type of fractal (Mandelbrot or Julia)\n", 49);
	exit(err);
}
