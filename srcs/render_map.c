/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:18 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:36 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Render walls
void	render_walls(t_vars *vars, t_map *map, t_img *wall)
{
	int	x;
	int	y;
	int	var1;
	int	var2;

	y = 1;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (vars->map.map[y][x] == '1')
			{
				var1 = x * (vars->grimgs.wall.width - 1);
				var2 = (y + 1) * (vars->grimgs.wall.height - 1);
				mlx_put_image_to_window(vars->mlx, vars->win, wall, var1, var2);
			}
			x++;
		}
		y++;
	}
}

// Texture map (0)voidspace, (C)collectibles, (E)exit
void	texture_map1(t_vars *vars, char c, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	if (c == '0')
	{
		img = vars->grimgs.espace.img;
		width = x * (vars->grimgs.espace.width - 1);
		height = (y + 1) * (vars->grimgs.espace.height - 1);
	}
	if (c == 'C')
	{
		img = vars->grimgs.collectible.img;
		width = x * (vars->grimgs.collectible.width - 1);
		height = (y + 1) * (vars->grimgs.collectible.height - 1);
	}
	if (c == 'E')
	{
		img = vars->grimgs.exit.img;
		width = x * (vars->grimgs.exit.width - 1);
		height = (y + 1) * (vars->grimgs.exit.height - 1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, width, height);
}

// Texture map (P)start, (G)player, (N)enemy
void	texture_map2(t_vars *vars, char c, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	if (c == 'P')
	{
		img = vars->grimgs.start.img;
		width = x * (vars->grimgs.start.width - 1);
		height = (y + 1) * (vars->grimgs.start.height - 1);
	}
	if (c == 'G')
	{
		img = vars->grimgs.character->img;
		width = x * (vars->grimgs.character->width - 1);
		height = (y + 1) * (vars->grimgs.character->height - 1);
	}
	if (c == 'N')
	{
		img = vars->grimgs.enemy->img;
		width = x * (vars->grimgs.enemy->width - 1);
		height = (y + 1) * (vars->grimgs.enemy->height - 1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, width, height);
}

// Texture map
void	texture_map(t_vars *vars, char c, int x, int y)
{
	if (c == '0' || c == 'C' || c == 'E')
		texture_map1(vars, c, x, y);
	if (c == 'P' || c == 'G' || c == 'N')
		texture_map2(vars, c, x, y);
}

// Render map
void	my_map_to_window(t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (vars->map.map[y][x] != '1')
				texture_map(vars, vars->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
}
