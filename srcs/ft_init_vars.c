/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:58:41 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:17 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Initialize Textures
void	initialize_vars_textures(t_files *texture)
{
	texture->espace = 0;
	texture->wall = 0;
	texture->collectible = 0;
	texture->exit = 0;
	texture->start = 0;
	texture->character.curr = 0;
	texture->character.next = 0;
	texture->enemy.next = 0;
	texture->enemy.next = 0;
	texture->d_down = 0;
	texture->d_left = 0;
	texture->d_right = 0;
	texture->l_border = 0;
	texture->r_border = 0;
	texture->u_left = 0;
	texture->u_right = 0;
	texture->u_up = 0;
	texture->u_upwall = 0;
}

// Initialize Group Images
void	initialize_vars_grimgs(t_grimgs *grimgs)
{
	grimgs->espace.img = 0;
	grimgs->espace.addr = 0;
	grimgs->wall.img = 0;
	grimgs->wall.addr = 0;
	grimgs->collectible.img = 0;
	grimgs->collectible.addr = 0;
	grimgs->exit.img = 0;
	grimgs->exit.addr = 0;
	grimgs->start.img = 0;
	grimgs->start.addr = 0;
	grimgs->acharacter.curr.img = 0;
	grimgs->acharacter.curr.addr = 0;
	grimgs->acharacter.next = 0;
	grimgs->aenemy.curr.img = 0;
	grimgs->aenemy.curr.addr = 0;
	grimgs->aenemy.next = 0;
}

// Initialize all memory allocations to 0
void	initialize_vars(t_vars	*vars)
{
	vars->mlx = 0;
	vars->win = 0;
	vars->img.img = 0;
	vars->img.addr = 0;
	vars->map.map = 0;
	vars->map.backup = 0;
	initialize_vars_textures(&vars->textures);
	initialize_vars_grimgs(&vars->grimgs);
	vars->stats.moves = 0;
	vars->stats.curr_pos = 0;
}

// Initialize Display and Window
void	initialize_display_window(t_vars *vars)
{
	int	w_size[2];

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Error\nDISPLAY: Can't initialize a display\n");
		win_destroy(vars, 2);
	}
	w_size[0] = vars->map.x * 32 - vars->map.x;
	w_size[1] = (vars->map.y + 1) * 32 - vars->map.y;
	vars->win = mlx_new_window(vars->mlx, w_size[0], w_size[1], "so_long");
	if (!vars->win)
	{
		free(vars->win);
		ft_printf("Error\nWINDOW: Can't initialize a window\n");
		win_destroy(vars, 3);
	}
}
