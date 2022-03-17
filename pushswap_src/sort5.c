/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:46:19 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:46:26 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort5(t_stack *a, t_stack *b)
{
	getsmolpush(a, b, 5);
	getsmolpush(a, b, 4);
	sort3(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

void	getsmolpush(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = getsmol(a);
	if (i <= c - 2)
	{
		while (i > 0)
		{
			rotate(a, 'a');
			i--;
		}
	}
	else
	{
		while (i < c)
		{
			reverserotate(a, 'a');
			i++;
		}
	}
	push(a, b, 'b');
}

int	getsmol(t_stack *s)
{
	int	i;
	int	ret;
	int	min;

	i = 0;
	min = 2147483647;
	ret = -1;
	while (i < *s->size)
	{
		if (s->stck[i] < min)
		{
			min = s->stck[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
