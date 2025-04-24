/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_borders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:38 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:42 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Render borders up 2
void	render_borders_up2(t_vars *vars, t_img *i, t_map *map)
{
	int	x;
	int	pos[2];

	group_imgs_img(vars, i, vars->textures.u_upwall);
	x = 0;
	while (++x < map->x - 1)
	{
		pos[0] = x * ((*i).width - 1);
		pos[1] = ((*i).height - 1);
		mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, pos[0], pos[1]);
	}
	mlx_destroy_image(vars->mlx, (*i).img);
	group_imgs_img(vars, i, vars->textures.u_right);
	pos[0] = (map->x - 1) * ((*i).width - 1);
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, pos[0], 0);
	mlx_destroy_image(vars->mlx, (*i).img);
}

// Render borders up
void	render_borders_up(t_vars *vars, t_img *i, t_map *map)
{
	int	i_s[2];
	int	x;

	group_imgs_img(vars, i, vars->textures.u_left);
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, 0, 0);
	mlx_destroy_image(vars->mlx, (*i).img);
	group_imgs_img(vars, i, vars->textures.u_up);
	x = 0;
	while (++x < map->x - 1)
	{
		i_s[0] = x * ((*i).width - 1);
		mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, i_s[0], 0);
	}
	mlx_destroy_image(vars->mlx, (*i).img);
	render_borders_up2(vars, i, map);
}

// Render borders sides
void	render_borders_side(t_vars *vars, t_img *i, t_map *map)
{
	int	i_s[2];
	int	y;

	group_imgs_img(vars, i, vars->textures.l_border);
	y = 0;
	while (++y < map->y)
	{
		i_s[1] = y * ((*i).height - 1);
		mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, 0, i_s[1]);
	}
	mlx_destroy_image(vars->mlx, (*i).img);
	group_imgs_img(vars, i, vars->textures.r_border);
	y = 0;
	while (++y < map->y)
	{
		i_s[0] = (map->x - 1) * ((*i).width - 1);
		i_s[1] = y * ((*i).height - 1);
		mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, i_s[0], i_s[1]);
	}
	mlx_destroy_image(vars->mlx, (*i).img);
}

// Render borders down
void	render_borders_down(t_vars *vars, t_img *i, t_map *map)
{
	int	i_s[2];
	int	x;

	group_imgs_img(vars, i, vars->textures.d_left);
	i_s[1] = map->y * ((*i).height - 1);
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, 0, i_s[1]);
	mlx_destroy_image(vars->mlx, (*i).img);
	group_imgs_img(vars, i, vars->textures.d_down);
	x = 0;
	while (++x < map->x - 1)
	{
		i_s[0] = x * ((*i).width - 1);
		i_s[1] = map->y * ((*i).height - 1);
		mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, i_s[0], i_s[1]);
	}
	mlx_destroy_image(vars->mlx, (*i).img);
	group_imgs_img(vars, i, vars->textures.d_right);
	i_s[0] = (map->x - 1) * ((*i).width - 1);
	i_s[1] = map->y * ((*i).height - 1);
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, i_s[0], i_s[1]);
	mlx_destroy_image(vars->mlx, (*i).img);
}

// Render borders
void	render_borders(t_vars *vars, t_map *map)
{
	render_borders_up(vars, &vars->img, map);
	render_borders_side(vars, &vars->img, map);
	render_borders_down(vars, &vars->img, map);
}
