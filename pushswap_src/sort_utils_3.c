/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:49:41 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:49:47 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort1to5a(t_stack *a, t_stack *b, int c)
{
	int	i;
	int	val;

	i = 0;
	val = -1;
	while (i < c)
	{
		if (b->stck[0] > a->stck[i])
			val = i;
		i++;
	}
	i = -1;
	while (i < val)
	{
		rotate(a, 'a');
		i++;
	}
	push(b, a, 'a');
	while (i > -1)
	{
		reverserotate(a, 'a');
		i--;
	}
}

void	sort5ascend(t_stack *a, t_stack *b)
{
	push(a, b, 'b');
	push(a, b, 'b');
	sort3a(a);
	sort1to5a(a, b, 3);
	sort1to5a(a, b, 4);
}

void	sort1to5(t_stack *a, t_stack *b, int c)
{
	int	i;
	int	val;

	i = 0;
	val = -1;
	while (i < c)
	{
		if (a->stck[0] < b->stck[i])
			val = i;
		i++;
	}
	i = -1;
	while (i < val)
	{
		rotate(b, 'b');
		i++;
	}
	push(a, b, 'b');
	while (i > -1)
	{
		reverserotate(b, 'b');
		i--;
	}
}

void	sort5decend(t_stack *a, t_stack *b)
{
	push(b, a, 'a');
	push(b, a, 'a');
	sort3b(b);
	sort1to5(a, b, 3);
	sort1to5(a, b, 4);
	push(b, a, 'a');
	push(b, a, 'a');
	push(b, a, 'a');
	push(b, a, 'a');
	push(b, a, 'a');
}

int	getbigval(t_stack *s, t_stack t)
{
	int	i;
	int	ret;
	int	max;

	i = 0;
	max = -2147483648;
	ret = -1;
	while (i < *s->size)
	{
		if (s->stck[i] > max)
		{
			if (checkt(s->stck[i], t))
			{
				max = s->stck[i];
				ret = max;
			}
		}
		i++;
	}
	return (ret);
}
