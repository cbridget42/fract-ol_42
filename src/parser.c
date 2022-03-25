/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:52:56 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/25 17:24:05 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	parser(int argc, char **argv, t_envf *env_f)
{
	int	i;

	i = 1;
	if (argc < 2)
		error_m();
	if (!ft_strncmp(argv[i], "Mandelbrot", 11))
		env_f->flags.frc = 0;
	else if (!ft_strncmp(argv[i], "Julia", 6))
		env_f->flags.frc = 1;
	else
		error_m();
	if (!ft_strncmp(argv[++i], "crack", 6))
	{
		env_f->flags.crk = 1;
		i++;
	}
	else
		env_f->flags.crk = 0;
}
