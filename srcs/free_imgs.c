/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:30:48 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:26 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Free Animated Image lists
void	free_grimgs_animage_list(t_aimgs *node)
{
	t_aimgs	*lst;
	int		n;

	n = node->n;
	node = node->next;
	while (node->n != n)
	{
		lst = node->next;
		free(node);
		node = lst;
	}
}

// Free Animated Images list's images
void	free_grimgs_animage_a(void *mlx, t_aimgs *img)
{
	int	n;

	n = img->n;
	img = img->next;
	while (img->n != n)
	{
		mlx_destroy_image(mlx, img->curr.img);
		img = img->next;
	}
	mlx_destroy_image(mlx, img->curr.img);
}

// Free Animated Images
void	free_grimgs_animage(void *mlx, t_grimgs *grimgs)
{
	free_grimgs_animage_a(mlx, &grimgs->acharacter);
	free_grimgs_animage_list(&grimgs->acharacter);
	free_grimgs_animage_a(mlx, &grimgs->aenemy);
	free_grimgs_animage_list(&grimgs->aenemy);
}

// Free Imgs
void	free_grimgs(void *mlx, t_grimgs *grimgs)
{
	mlx_destroy_image(mlx, grimgs->espace.img);
	mlx_destroy_image(mlx, grimgs->wall.img);
	mlx_destroy_image(mlx, grimgs->collectible.img);
	mlx_destroy_image(mlx, grimgs->exit.img);
	mlx_destroy_image(mlx, grimgs->start.img);
	free_grimgs_animage(mlx, grimgs);
}
