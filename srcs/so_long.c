/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:22:21 by famirant          #+#    #+#             */
/*   Updated: 2022/12/05 16:04:20 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Developer to Player informations at GAME START (Use a window of 77+ width)
void	game_informations(void)
{
	ft_printf("\n\033[01;07;39m\
  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――  \n\
  ︳                                                                       ︳\n\
  ︳Hello Player                                                           ︳\n\
  ︳Welcome to so_long, or at least my small version of it.                ︳\n\
  ︳Have Fun trying to find some Bug, Hope you don't find any of course.   ︳\n\
  ︳                                                                       ︳\n\
  ︳RULES:                                                                 ︳\n\
  ︳  Take all the Toilet Paper and escape to the ladder, but be careful,  ︳\n\
  ︳  you're not alone, your cats want to stop you from take               ︳\n\
  ︳  the Toilet Papers so stay away from them.                            ︳\n\
  ︳                                                                       ︳\n\
  ︳COMMANDS:                                                              ︳\n\
  ︳  Move with WASD or the ARROW KEYS                                     ︳\n\
  ︳  Quit from the game with ESC                                          ︳\n\
  ︳                                                                       ︳\n\
  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――  \
\033[0m\n\n");
}

int	detect_arguments(int argc, char **argv, t_map *map)
{
	int	file;

	if (argc == 2)
		file = open(argv[1], O_RDONLY);
	else
		file = open("maps/maptest1.ber", O_RDONLY);
	if (file < 0)
	{
		ft_printf("ERROR\n");
		if (argc == 2)
			ft_printf("MAP: Can't open [%s]\n", argv[1]);
		else
			ft_printf("MAP: Can't open [maps/maptest1.ber]\n");
		exit(1);
	}
	map->map = (char **)malloc(sizeof(char *) * (ft_sizeelem(file) + 1));
	close(file);
	if (argc == 2)
		file = open(argv[1], O_RDONLY);
	else
		file = open("maps/maptest1.ber", O_RDONLY);
	return (file);
}

void	map_selected(t_vars *vars, t_map *map, int argc, char **argv)
{
	int			file;
	int			endline;

	file = detect_arguments(argc, argv, map);
	endline = 1;
	map->y = 0;
	while (endline)
	{
		map->map[map->y] = get_next_line(file);
		if (map->map[map->y])
			endline = map->map[map->y++][0];
		else
			endline = 0;
	}
	map->map[map->y] = 0;
	close(file);
	map->x = ft_strlen(map->map[0]) - 1;
	count_objects(map);
	check_map(vars, map);
	backup_map(map, 1);
	vars->stats.uncollected = vars->map.info.collects;
	vars->stats.curr_pos = curr_entity_pos(&vars->map, 'P');
	map->map[vars->stats.curr_pos[1]][vars->stats.curr_pos[0]] = 'G';
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	initialize_vars(&vars);
	map_selected(&vars, &vars.map, argc, argv);
	initialize_display_window(&vars);
	load_textures(&vars.textures);
	group_imgs(&vars, &vars.grimgs);
	render_borders(&vars, &vars.map);
	my_map_to_window(&vars, &vars.map);
	render_walls(&vars, &vars.map, vars.grimgs.wall.img);
	display_stats(&vars, &vars.stats, &vars.img, &vars.img.line_length);
	game_informations();
	my_mlx(&vars);
	return (0);
}

/* ERROR returns:
		0: All Working
		1: MAP not working
		2: DISPLAY is 0
		3: WINDOW is 0
*/

// For Mem_leaks: valgrind --leak-check=full --show-leak-kinds=all
