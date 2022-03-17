/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:47:24 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:47:29 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkascendi(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (s->stck[i] > s->stck[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checkdecendi(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (s->stck[i] < s->stck[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checksorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < (*a->size - 1))
	{
		if (a->stck[i] > a->stck[i + 1])
			return (0);
		i++;
	}
	if (*b->size != 0)
		return (0);
	return (1);
}

int	checkt(int val, t_stack t)
{
	int	i;

	i = 0;
	if (*t.size != 0)
	{
		while (i < *t.size)
		{
			if (val == t.stck[i])
				return (0);
			i++;
		}
	}
	return (1);
}
