/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:17:44 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/12 21:18:13 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	getsmallval(t_stack *s, t_stack t)
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
			if (checkt(s->stck[i], t))
			{
				min = s->stck[i];
				ret = min;
			}
		}
		i++;
	}
	return (ret);
}

int	getsmallest(t_stack *s)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < *s->size)
	{
		if (s->stck[i] < min)
			min = s->stck[i];
		i++;
	}
	return (min);
}

int	getbiggest(t_stack *s)
{
	int	i;
	int	max;

	i = 0;
	max = -2147483648;
	while (i < *s->size)
	{
		if (s->stck[i] > max)
			max = s->stck[i];
		i++;
	}
	return (max);
}

void	pushbiggest(t_stack *a, t_stack *b, int min, int c)
{
	int	i;
	int	rcount;
	int	pcount;

	i = 0;
	rcount = 0;
	pcount = 0;
	while (i < 50)
	{
		if (b->stck[0] >= min)
		{
			push(b, a, 'a');
			pcount++;
		}
		else
		{
			if (pcount < c)
			{
				rotate(b, 'b');
				rcount++;
			}
		}
		i++;
	}
	reverserotate_n(b, 'b', rcount);
}

void	pushsmallest(t_stack *a, t_stack *b, int max, int c)
{
	int	i;
	int	rcount;
	int	pcount;

	i = 0;
	rcount = 0;
	pcount = 0;
	while (i < 50)
	{
		if (a->stck[0] <= max)
		{
			push(a, b, 'b');
			pcount++;
		}
		else
		{
			if (pcount < c)
			{
				rotate(a, 'a');
				rcount++;
			}
		}
		i++;
	}
	reverserotate_n(a, 'a', rcount);
}
