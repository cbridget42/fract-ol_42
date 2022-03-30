/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:43:46 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/30 13:17:37 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	ch_iter(int kc, t_envf *env_f)
{
	new_img(env_f);
	if (kc == 31)
		env_f->coords.max_it += 100;
	else if (env_f->coords.max_it > 100)
		env_f->coords.max_it -= 100;
	else if (env_f->coords.max_it > 10)
		env_f->coords.max_it -= 10;
	else if (env_f->coords.max_it > 0)
		env_f->coords.max_it -=1;
	ft_fractals(env_f);
}

void	change_dr(t_envf *env_f)
{
	new_img(env_f);
	if (env_f->flags.drw < 2)
		env_f->flags.drw += 1;
	else
		env_f->flags.drw = 0;
	ft_fractals(env_f);
}

void	change_drtwo(t_envf *env_f)
{
	new_img(env_f);
	env_f->flags.clrs1 = ft_rand_r(&env_f->flags.seed) % 55;
	env_f->flags.clrs2 = ft_rand_r(&env_f->flags.seed) % 55;
	env_f->flags.clrs3 = ft_rand_r(&env_f->flags.seed) % 55;
	env_f->flags.cof_c1 = ft_rand_r(&env_f->flags.seed) % 255;
	if (env_f->flags.cof_c1 == 0)
		env_f->flags.cof_c1 = 250;
	env_f->flags.cof_c2 = ft_rand_r(&env_f->flags.seed) % 255;
	if (env_f->flags.cof_c2 == 0)
		env_f->flags.cof_c2 = 250;
	env_f->flags.cof_c3 = ft_rand_r(&env_f->flags.seed) % 255;
	if (env_f->flags.cof_c3 == 0)
		env_f->flags.cof_c3 = 255;
	ft_fractals(env_f);
}
