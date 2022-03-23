/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:43:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/23 18:36:56 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close(int keycode, t_vars *vars);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, hight, "fractol");
	img.img = mlx_new_image(mlx, width, hight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	ft_mandelbrot(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_hook(mlx_win, 2, 1L<<0, close, &vars);
	mlx_loop(mlx);
	return 0;
}

int	close(int keycode, t_vars *vars)
{
	printf("kc=%d\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	*((int *)(data->addr) + y * data->line_lenght / (data->bits_per_pixel / 8) + x) = color;
}
