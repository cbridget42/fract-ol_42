/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:41:25 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/30 16:45:12 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# define HIGHT 1000
# define WIDTH 1000
# define SHIFT 300

typedef struct s_frc_flags {
	int	frc;
	int	drw;
	int	cof_c1;
	int	cof_c2;
	int	cof_c3;
	int	clrs1;
	int	clrs2;
	int	clrs3;
	int	seed;
}				t_frc_flags;

typedef struct s_coords {
	int					x;
	int					y;
	unsigned int		max_it;
	unsigned int		cof;
	double				c_x;
	double				c_y;
	double				j_x;
	double				j_y;
	unsigned long long	scale;
}				t_coords;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_envf {
	void		*mlx;
	void		*win;
	t_coords	coords;
	t_data		img;
	t_frc_flags	flags;
}				t_envf;

int				ft_close(t_envf *env_f);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_fractals(t_envf *env_f);
unsigned int	ft_mandelbrot(t_envf *env_f, double x, double y);
unsigned int	ft_julia(t_envf *env_f, double x, double y);
unsigned int	ft_burning_ship(t_envf *env_f, double x, double y);
void			error_m(int err);
void			parser(int argc, char **argv, t_envf *env_f);
void			ch_db(char *str);
void			init_f(t_envf *env_f);
void			new_img(t_envf *env_f);
int				drawing_one(unsigned int i, t_envf *env_f, double x, double y);
int				drawing_two(unsigned int i, t_envf *env_f);
int				m_mouse(int x, int y, t_envf *env_f);
int				ft_close(t_envf *env_f);
void			frc_hk(t_envf *env_f);
void			change_dr(t_envf *env_f);
void			change_drtwo(t_envf *env_f);
void			increase_c(t_envf *env_f);
int				h_keyb(int keycode, t_envf *env_f);
double			coord_trn(double x_y, t_envf *env_f, int mod);
void			decrease_c(t_envf *env_f);
void			arrow_m(t_envf *env_f, int kc);
int				mh_keyb(int button, int x, int y, t_envf *env_f);
double			ft_atof(char *num);
double			ft_atofr(double x);
int				ft_atoi_s(const char *str, int *overflow);
int				skipp(const char *str, int *sign);
int				drawing_three(unsigned int i, t_envf *env_f);
void			ch_iter(int kc, t_envf *env_f);
int				ft_do_rand(int *ctx);
int				ft_rand_r(int *ctx);

#endif
