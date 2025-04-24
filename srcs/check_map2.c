/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:14:24 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:04 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Map must be closed/surrounded by walls
void	check_map3(t_vars *vars, t_map *map, t_point i)
{
	if (i.x == map->x - 1 || i.y == map->y - 1 || i.x == 0 || i.y == 0)
	{
		ft_printf("Error\nMAP: Map must be closed/surrounded by walls\n");
		win_destroy(vars, 1);
	}
	if (ft_char_in_array(map->backup[i.y + 1][i.x], "F"))
	{
		map->backup[i.y + 1][i.x] = 'S';
		check_map3(vars, map, (t_point){i.x, i.y + 1});
	}
	if (ft_char_in_array(map->backup[i.y - 1][i.x], "F"))
	{
		map->backup[i.y - 1][i.x] = 'S';
		check_map3(vars, map, (t_point){i.x, i.y - 1});
	}
	if (ft_char_in_array(map->backup[i.y][i.x + 1], "F"))
	{
		map->backup[i.y][i.x + 1] = 'S';
		check_map3(vars, map, (t_point){i.x + 1, i.y});
	}
	if (ft_char_in_array(map->backup[i.y][i.x - 1], "F"))
	{
		map->backup[i.y][i.x - 1] = 'S';
		check_map3(vars, map, (t_point){i.x - 1, i.y});
	}
}

// Map error(1): Player is able to reach the Exit after all collectibles
void	err1_path(t_vars *vars)
{
	ft_printf("Error\n");
	ft_printf("MAP: Player can't reach the Exit and/or all collectibles\n");
	win_destroy(vars, 1);
}

// Player can reach all collectibles before Exit
int	check_map4_collects(t_map *map)
{
	int	coords[2];

	coords[1] = 0;
	while (coords[1] < map->y)
	{
		coords[0] = 0;
		while (coords[0] < map->x)
		{
			if (map->backup[coords[1]][coords[0]] == 'C')
				return (1);
			coords[0]++;
		}
		coords[1]++;
	}
	return (0);
}

// Player must have a valid path
void	check_map4(t_vars *vars, t_map *map)
{
	t_point	i;
	int		*pos;

	backup_map(map, 0);
	pos = curr_entity_pos(map, 'P');
	i.x = pos[0];
	i.y = pos[1];
	free(pos);
	map_path(map->backup, (t_point){map->x, map->y}, i);
	pos = curr_entity_pos(map, 'E');
	i.x = pos[0];
	i.y = pos[1];
	free(pos);
	if (map->backup[i.y][i.x] == 'F' && !check_map4_collects(map))
		return ;
	else
		err1_path(vars);
}
