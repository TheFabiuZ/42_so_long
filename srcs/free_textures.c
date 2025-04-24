/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:34:32 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:19 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Free Textures list
void	free_atextures_list(t_animate *node)
{
	t_animate	*lst;

	while (node->next)
	{
		lst = node->next;
		free(node->curr);
		free(node);
		node = lst;
	}
	free(node->curr);
	free(node);
}

// Free Textures lists
void	free_atextures(t_files *textures)
{
	free_atextures_list(textures->character.next);
	free_atextures_list(textures->enemy.next);
}
