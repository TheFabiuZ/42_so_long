/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:42:04 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:45 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Player touch a collectible/exit/enemy
void	player_next_pos(t_vars *vars, t_stats *stats, char next_pos)
{
	if (next_pos == 'C' && stats->uncollected > 0)
		stats->uncollected--;
	if (next_pos == 'E')
		display_win(vars->map.info.collects, ++stats->moves, vars);
	if (next_pos == 'N')
		display_lose(stats->uncollected, vars->map.info.collects, vars);
}

// Player movement
void	player_movement(int x, int y, t_map	*map, t_vars *vars)
{
	char	next_pos;
	char	prev_pos;
	t_stats	*stats;

	stats = &vars->stats;
	next_pos = map->map[stats->curr_pos[1] + y][stats->curr_pos[0] + x];
	if (next_pos == '1')
		return ;
	if (next_pos == 'E' && stats->uncollected > 0)
		return ;
	player_next_pos(vars, stats, next_pos);
	map->map[stats->curr_pos[1] + y][stats->curr_pos[0] + x] = 'G';
	prev_pos = map->backup[stats->curr_pos[1]][stats->curr_pos[0]];
	if (prev_pos == 'P' || prev_pos == 'E')
		map->map[stats->curr_pos[1]][stats->curr_pos[0]] = prev_pos;
	else
		map->map[stats->curr_pos[1]][stats->curr_pos[0]] = '0';
	stats->curr_pos[1] += y;
	stats->curr_pos[0] += x;
	stats->moves++;
	my_map_to_window(vars, map);
	display_stats(vars, stats, &vars->img, &vars->img.line_length);
}
