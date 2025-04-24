/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:51:36 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:09 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Merge strings
char	*merge_str(char *str1, char *str2)
{
	char	*new_str;

	new_str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (new_str);
}

// Stats string
void	display_stats_str(t_vars *vars, t_stats *stats, char **s_c, char **s_m)
{
	char	*temp;

	temp = ft_strdup("/");
	*s_c = merge_str(ft_itoa(stats->uncollected), temp);
	*s_c = merge_str(*s_c, ft_itoa(vars->map.info.collects));
	temp = ft_strdup("Moves: ");
	*s_m = merge_str(temp, ft_itoa(stats->moves));
}

// Stats string all in one
void	display_stats_togheter(char **str_clt, char **s_moves)
{
	char	*temp;

	temp = ft_strdup("  Collectibles: ");
	*str_clt = merge_str(temp, *str_clt);
	*s_moves = merge_str(*s_moves, *str_clt);
}

// Display your moves and collectibles
void	display_stats(t_vars *vars, t_stats *stats, t_img *i, int *ll)
{
	char	*s_moves;
	char	*str_clt;
	int		tp[2];

	(*i).img = mlx_new_image(vars->mlx, 192, 16);
	(*i).addr = mlx_get_data_addr((*i).img, &(*i).bpp, ll, &(*i).endian);
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, (*i).width * 2, 0);
	tp[1] = vars->map.y * 32 + 12;
	mlx_put_image_to_window(vars->mlx, vars->win, (*i).img, 2, tp[1]);
	mlx_destroy_image(vars->mlx, (*i).img);
	display_stats_str(vars, stats, &str_clt, &s_moves);
	if (vars->map.x * 32 < 8 * 32)
	{
		mlx_string_put(vars->mlx, vars->win, (*i).width, 16, 0xFFFFFF, s_moves);
		tp[0] = (vars->map.x * 32) / 2 - 10;
		tp[1] = vars->map.y * 32 + 28 - vars->map.y;
		mlx_string_put(vars->mlx, vars->win, tp[0], tp[1], 0xFFFFFF, str_clt);
		free(str_clt);
	}
	else
	{
		display_stats_togheter(&str_clt, &s_moves);
		mlx_string_put(vars->mlx, vars->win, (*i).width, 16, 0xFFFFFF, s_moves);
	}
	free(s_moves);
}
