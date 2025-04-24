/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:24:20 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:54 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Number of elements in a file
size_t	ft_sizeelem(int file)
{
	int		endline;
	char	*line;
	int		len;

	len = 0;
	endline = 1;
	while (endline)
	{
		line = get_next_line(file);
		if (line)
		{
			endline = line[0];
			len++;
		}
		else
			endline = 0;
		free(line);
	}
	return (len);
}

// Textures used
void	texture_credits(t_vars *vars)
{
	ft_printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -");
	ft_printf("\nTEXTURES\nespace:\t\t%s\n", vars->textures.espace);
	ft_printf("wall:\t\t%s\n", vars->textures.wall);
	ft_printf("collectible:\t%s\n", vars->textures.collectible);
	ft_printf("exit:\t\t%s\n", vars->textures.exit);
	ft_printf("start:\t\t%s\n", vars->textures.start);
	ft_printf("character:\t%s\n", vars->textures.character.curr);
	ft_printf("enemy:\t\t%s\n", vars->textures.enemy.curr);
	ft_printf("\nBORDERS\n%s\n", vars->textures.d_down);
	ft_printf("%s\n", vars->textures.d_left);
	ft_printf("%s\n", vars->textures.d_right);
	ft_printf("%s\n", vars->textures.l_border);
	ft_printf("%s\n", vars->textures.r_border);
	ft_printf("%s\n", vars->textures.u_left);
	ft_printf("%s\n", vars->textures.u_right);
	ft_printf("%s\n", vars->textures.u_up);
	ft_printf("%s\n", vars->textures.u_upwall);
	ft_printf("- - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

// Free all memory allocated, then destroy all
int	win_destroy(t_vars *vars, int err)
{
	if (err > 3)
		err = 0;
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->grimgs.espace.img)
		free_grimgs(vars->mlx, &vars->grimgs);
	if (vars->textures.character.next)
		free_atextures(&vars->textures);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map.backup)
		free_map_and_backup(&vars->map);
	else
		free_map(&vars->map);
	if (vars->stats.curr_pos)
		free(vars->stats.curr_pos);
	exit(err);
	return (0);
}
//texture_credits(vars);

// On press of a key
int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		ft_printf("Are you leaving me? ='(\nBye my friend...\n");
		win_destroy(vars, 0);
	}
	if (keycode == 'w' || keycode == 65362)
		player_movement(0, -1, &vars->map, vars);
	if (keycode == 'a' || keycode == 65361)
		player_movement(-1, 0, &vars->map, vars);
	if (keycode == 's' || keycode == 65364)
		player_movement(0, 1, &vars->map, vars);
	if (keycode == 'd' || keycode == 65363)
		player_movement(1, 0, &vars->map, vars);
	return (0);
}

void	my_mlx(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, &render_frame, vars);
	mlx_hook(vars->win, 2, 1L << 0, on_keydown, vars);
	mlx_hook(vars->win, 17, 1L << 4, win_destroy, vars);
	mlx_loop(vars->mlx);
}
