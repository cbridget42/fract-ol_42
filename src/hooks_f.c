/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:28:50 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/29 17:25:32 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	h_keyb(int keycode, t_envf *env_f)
{
	printf("kc=%d\n", keycode);
	if (keycode == 34)
		increase_c(env_f);
	if (keycode == 40)
		decrease_c(env_f);
	if (keycode <= 126 && keycode >= 123)
		arrow_m(env_f, keycode);
	if (keycode == 53)
		ft_close(env_f);
	if (keycode == 38)
		change_dr(env_f);
	if (keycode == 4)
		change_drtwo(env_f);
	if (keycode == 31 || keycode == 35)
		ch_iter(keycode, env_f);
	return (0);
}

int	mh_keyb(int button, int x, int y, t_envf *env_f)
{
	env_f->coords.x = x;
	env_f->coords.y = y;
	if (button == 4)
		increase_c(env_f);
	else if (button == 5)
		decrease_c(env_f);
	return (0);
}

void	frc_hk(t_envf *env_f)
{
	mlx_key_hook(env_f->win, h_keyb, env_f);
	mlx_hook(env_f->win, 6, 1L<<6, m_mouse, env_f);
	mlx_hook(env_f->win, 17, 0L, ft_close, env_f);
	mlx_mouse_hook(env_f->win, mh_keyb, env_f);
	mlx_loop(env_f->mlx);
}

void	increase_c(t_envf *env_f)
{
	new_img(env_f);
	env_f->coords.c_x = coord_trn(env_f->coords.x, env_f, 0);
	env_f->coords.c_y = coord_trn(env_f->coords.y, env_f, 1);
	if (env_f->coords.scale * 2 < env_f->coords.scale)
		ft_close(env_f);
	env_f->coords.scale *= /*2*/1.2;
	env_f->coords.max_it += env_f->coords.cof;
	if (env_f->coords.max_it % 2)
		env_f->coords.cof += 1;
	printf("c_x=%f, c_y=%f, scale=%llu, it=%d\n", env_f->coords.c_x, env_f->coords.c_y, env_f->coords.scale, env_f->coords.max_it);
	ft_fractals(env_f);
}

void	decrease_c(t_envf *env_f)
{
	if (env_f->coords.scale / 2 < 100)
		return ;
	new_img(env_f);
	env_f->coords.c_x = coord_trn(env_f->coords.x, env_f, 0);
	env_f->coords.c_y = coord_trn(env_f->coords.y, env_f, 1);
	env_f->coords.scale /= /*2*/1.2;
	if (env_f->coords.max_it % 2)
		env_f->coords.cof -= 1;
	if (env_f->coords.max_it < env_f->coords.cof)
		env_f->coords.max_it -= env_f->coords.cof;
	printf("c_x=%f, c_y=%f, scale=%llu, it=%d\n", env_f->coords.c_x, env_f->coords.c_y, env_f->coords.scale, env_f->coords.max_it);
	ft_fractals(env_f);
}

void	arrow_m(t_envf *env_f, int kc)
{
	printf("+: %f\n", (double)f_shift / env_f->coords.scale);
	new_img(env_f);
	if (kc == 125)
		env_f->coords.c_y += (double)f_shift / env_f->coords.scale;
	else if (kc == 126)
		env_f->coords.c_y -= (double)f_shift / env_f->coords.scale;
	else if (kc == 123)
		env_f->coords.c_x -= (double)f_shift / env_f->coords.scale;
	else
		env_f->coords.c_x += (double)f_shift / env_f->coords.scale;
	ft_fractals(env_f);
}
