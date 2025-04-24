/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:02:45 by famirant          #+#    #+#             */
/*   Updated: 2022/12/05 16:26:45 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Add animation to the animations list
void	add_animations(t_animate *alist, char *path, int n)
{
	t_animate	*aimg;

	if (*(path + ft_strlen(path) - 1) == '\n')
		ft_memset(path + ft_strlen(path) - 1, 0, 1);
	aimg = malloc(sizeof(t_animate));
	aimg->curr = path;
	aimg->next = NULL;
	aimg->n = n;
	alist->next = aimg;
}

// Load animations from file
void	load_animations_file(int file, t_animate *temp)
{
	char	*path;
	int		endline;

	endline = 1;
	while (endline)
	{
		path = get_next_line(file);
		if (path)
		{
			add_animations(temp, path, endline);
			temp = temp->next;
			endline++;
		}
		else
			endline = 0;
	}
	close(file);
}

// Load textures (Animations)
void	load_animations(t_files *texture)
{
	t_animate	*temp;
	int			file;

	file = open("textures/Player/ChickBoy/a_idle/animations.txt", O_RDONLY);
	texture->character.n = 0;
	texture->character.next = NULL;
	temp = &texture->character;
	load_animations_file(file, temp);
	file = open("textures/Enemy/one-cat/a_idle/animations.txt", O_RDONLY);
	texture->enemy.n = 0;
	texture->enemy.next = NULL;
	temp = &texture->enemy;
	load_animations_file(file, temp);
}

// Load textures (Tiles/Entities +Animations)
void	load_textures(t_files *texture)
{
	texture->espace = "textures/Tiles/Cottage_Tileset/Floor.xpm";
	texture->wall = "textures/Tiles/32x32Tiles/block_0.xpm";
	texture->collectible = "textures/Collects/MegaPixelArt/Collectible_0.xpm";
	texture->exit = "textures/Tiles/Dungeon_Tileset/Exit_0.xpm";
	texture->start = "textures/Tiles/Cottage_Tileset/Start.xpm";
	texture->character.curr = "textures/Player/ChickBoy/Character_0.xpm";
	texture->enemy.curr = "textures/Enemy/one-cat/Enemy_0.xpm";
	texture->d_down = "textures/Tiles/Cottage_Tileset/Borders/Ddown.xpm";
	texture->d_left = "textures/Tiles/Cottage_Tileset/Borders/Dleft.xpm";
	texture->d_right = "textures/Tiles/Cottage_Tileset/Borders/Dright.xpm";
	texture->l_border = "textures/Tiles/Cottage_Tileset/Borders/LBorder.xpm";
	texture->r_border = "textures/Tiles/Cottage_Tileset/Borders/RBorder.xpm";
	texture->u_left = "textures/Tiles/Cottage_Tileset/Borders/Uleft.xpm";
	texture->u_right = "textures/Tiles/Cottage_Tileset/Borders/Uright.xpm";
	texture->u_up = "textures/Tiles/Cottage_Tileset/Borders/Uup.xpm";
	texture->u_upwall = "textures/Tiles/Cottage_Tileset/Borders/Wall.xpm";
	load_animations(texture);
}
