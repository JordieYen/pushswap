/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:06 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:49:09 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	movesecondup(t_stack *s)
{
	int	i;

	i = 0;
	while (i < *s->size - 1)
	{
		s->stck[i] = s->stck[i + 1];
		i++;
	}
}

void	moveseconddown(t_stack *s)
{
	int	size;

	size = *s->size;
	while (size > 0)
	{
		s->stck[size] = s->stck[size - 1];
		size--;
	}
}
