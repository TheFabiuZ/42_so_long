/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:26:58 by famirant          #+#    #+#             */
/*   Updated: 2022/10/03 14:27:00 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*prov;

	prov = s;
	i = 0;
	while (i < n)
	{
		*(prov + i) = 0;
		i++;
	}
}
