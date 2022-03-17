/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:48:33 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 18:41:06 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	geti(t_stack *s, t_stack t)
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
			if (checkt(i, t))
			{
				min = s->stck[i];
				ret = i;
			}
		}
		i++;
	}
	return (ret);
}

int	getclose(t_stack *s)
{
	int	i;
	int	min;
	int	val;
	int	ret;

	i = 0;
	ret = -1;
	min = 2147483647;
	while (i < *s->size)
	{
		val = s->stck[i];
		if (val < 0)
			val = val * -1;
		if (val < min)
		{
			min = val;
			ret = i;
		}
		i++;
	}
	val = s->stck[ret];
	freestack(s);
	return (val);
}

void	rotatepush(int n, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			rotate(a, 'a');
			i++;
		}
	}
	else
	{
		n = n * -1;
		while (i < n)
		{
			reverserotate(a, 'a');
			i++;
		}
	}
	push(a, b, 'b');
}

int	getcloser(int len, t_stack t)
{
	t_stack	temp;
	int		tempsize;
	int		i;

	temp.stck = ft_calloc(*t.size, sizeof(int));
	tempsize = 0;
	temp.size = &tempsize;
	i = 0;
	while (*temp.size < *t.size)
	{
		if (t.stck[i] <= (len / 2))
		{
			temp.stck[i] = t.stck[i];
			*temp.size += 1;
		}
		else
		{
			temp.stck[i] = t.stck[i] - len;
			*temp.size += 1;
		}
		i++;
	}
	return (getclose(&temp));
}
