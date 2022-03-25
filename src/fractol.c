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

int	h_keyb(int keycode, t_envf *env_f);
int	m_mouse(int x, int y, t_envf *env_f);

int	main(int argc, char **argv)
{
	t_envf env_f;

	parser();
	env_f.mlx = mlx_init();
	env_f.win = mlx_new_window(env_f.mlx, width, hight, "fractol");
	env_f.img.img = mlx_new_image(env_f.mlx, width, hight);
	env_f.img.addr = mlx_get_data_addr(env_f.img.img, &env_f.img.bits_per_pixel, &env_f.img.line_lenght, &env_f.img.endian);
	env_f.coords.scale = 250;
	env_f.coords.max_it = 50;
	env_f.coords.cof = 50;
	env_f.coords.c_x = 0;
	env_f.coords.c_y = 0;
	ft_mandelbrot(&env_f);
	mlx_put_image_to_window(env_f.mlx, env_f.win, env_f.img.img, 0, 0);
	mlx_key_hook(env_f.win, h_keyb, &env_f);
	mlx_hook(env_f.win, 6, 1L<<6, m_mouse, &env_f);
	mlx_hook(env_f.win, 17, 0L, ft_close, &env_f);
	mlx_loop(env_f.mlx);
	return 0;
}

int	ft_close(t_envf *env_f)
{
	mlx_clear_window(env_f->mlx, env_f->win);
	mlx_destroy_window(env_f->mlx, env_f->win);
	free(env_f->mlx);
	exit(0);
}

int	m_mouse(int x, int y, t_envf *env_f)
{
	env_f->coords.x = x;
	env_f->coords.y = y;
	return (0);
}

int	h_keyb(int keycode, t_envf *env_f)
{
	printf("kc=%d\n", keycode);
	if (keycode == /*mac-34*/105)
	{
		env_f->coords.c_x = (env_f->coords.x - (double)width / 2) / env_f->coords.scale + env_f->coords.c_x;
		env_f->coords.c_y = (env_f->coords.y - (double)hight / 2) / env_f->coords.scale + env_f->coords.c_y;
//		printf("b=%f\n", ((double)150 - (double)width / 2) / env_f->coords.scale + env_f->coords.c_x);
//		printf("af=%f\n", ((double)150 - (double)width / 2) / env_f->coords.scale + (env_f->coords.x - 500));
		env_f->coords.scale *= 2;
		env_f->coords.max_it += env_f->coords.cof;
		env_f->coords.cof += 25;
		if (env_f->coords.max_it > 23000)
			env_f->coords.cof += 1000;
		printf("c_x=%f, c_y=%f, scale=%llu, it=%d\n", env_f->coords.c_x, env_f->coords.c_y, env_f->coords.scale, env_f->coords.max_it);
		ft_mandelbrot(env_f);
		mlx_put_image_to_window(env_f->mlx, env_f->win, env_f->img.img, 0, 0);
//		printf("in_close: vars->coords.x=%d, vars->coords.y=%d\n", env_f->coords.x, env_f->coords.y);
	}
	if (keycode == /*mac-53*/65307)
		ft_close(env_f);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	*((int *)(data->addr) + y * data->line_lenght / (data->bits_per_pixel / 8) + x) = color;
}
