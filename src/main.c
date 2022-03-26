/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:43:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/24 15:30:17by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_envf env_f;

	parser(argc, argv, &env_f);
	init_f(&env_f);
	ft_fractals(&env_f);
	frc_hk(&env_f);
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	*((int *)(data->addr) + y * data->line_lenght / (data->bits_per_pixel / 8) + x) = color;
}
