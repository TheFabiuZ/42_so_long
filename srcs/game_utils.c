/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:01:15 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:04 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Find e in map
int	*curr_entity_pos(t_map *map, char e)
{
	int	*coords;

	coords = (int *)malloc(sizeof(int) * 2);
	coords[1] = 0;
	while (coords[1] < map->y)
	{
		coords[0] = 0;
		while (coords[0] < map->x)
		{
			if (map->map[coords[1]][coords[0]] == e)
				return (coords);
			coords[0]++;
		}
		coords[1]++;
	}
	coords[1] = 0;
	coords[0] = 0;
	return (coords);
}

// Display map in terminal
void	display_map_terminal(t_map *map, char **mapp)
{
	int	i;

	i = -1;
	while (++i < map->x / 2 - 2)
		ft_printf(" ");
	ft_printf("MAP\n");
	i = -1;
	while (++i < map->x)
		ft_printf("-");
	ft_printf("\n");
	i = -1;
	while (++i < map->y)
		ft_printf("%s", mapp[i]);
	i = -1;
	while (++i < map->x)
		ft_printf("-");
	ft_printf("\n");
}

// Backup Map
void	backup_map(t_map *map, int print_map)
{
	int	y;

	map->backup = (char **)malloc(sizeof(char *) * (map->y + 1));
	y = 0;
	while (y < map->y)
	{
		map->backup[y] = ft_strdup(map->map[y]);
		y++;
	}
	map->backup[map->y] = 0;
	if (print_map)
		display_map_terminal(map, map->map);
}
