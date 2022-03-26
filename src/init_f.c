/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:23:17 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/26 16:22:43 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_f(t_envf *env_f)
{
	env_f->mlx = mlx_init();
	env_f->win = mlx_new_window(env_f->mlx, width, hight, "fractol");
	env_f->img.img = mlx_new_image(env_f->mlx, width, hight);
	env_f->img.addr = mlx_get_data_addr(env_f->img.img, &env_f->img.bits_per_pixel, &env_f->img.line_lenght, &env_f->img.endian);
	env_f->coords.scale = 250;
	env_f->coords.max_it = 350;
	env_f->coords.cof = 50;
	env_f->coords.c_x = 0;
	env_f->coords.c_y = 0;
	env_f->flags.drw = 0;
}

void	new_img(t_envf *env_f)
{
	mlx_destroy_image(env_f->mlx, env_f->img.img);
	mlx_clear_window(env_f->mlx, env_f->win);
	env_f->img.img = mlx_new_image(env_f->mlx, width, hight);
	env_f->img.addr = mlx_get_data_addr(env_f->img.img, &env_f->img.bits_per_pixel, &env_f->img.line_lenght, &env_f->img.endian);
}

double	coord_trn(double x_y, t_envf *env_f, int mod)
{
	if (!mod)
		return (((double)x_y - (double)width / 2) / env_f->coords.scale + env_f->coords.c_x);
	else
		return (((double)x_y - (double)hight / 2) / env_f->coords.scale + env_f->coords.c_y);
}
