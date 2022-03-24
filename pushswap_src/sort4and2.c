/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4and2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:51:49 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:11:17 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

double	getmedian(t_stack *s, int len)
{
	int		i;
	int		sum;
	double	med;

	i = 0;
	sum = 0;
	med = 0;
	while (i < len)
	{
		sum += s->stck[i];
		i++;
	}
	med = (double)sum / (double)i;
	return (med);
}

void	sort4ascend(t_stack *a, t_stack *b)
{
	int		i;
	double	med;

	i = 0;
	med = getmedian(a, 4);
	while (i < 4)
	{
		if (a->stck[0] < med)
			push(a, b, 'b');
		else
			rotate(a, 'a');
		i++;
	}
	sort2ascend(a, 'a');
	sort2decend(b, 'b');
	push(b, a, 'a');
	push(b, a, 'a');
}

void	sort4decend(t_stack *a, t_stack *b)
{
	int		i;
	double	med;

	i = 0;
	med = getmedian(b, 4);
	while (i < 4)
	{
		if (b->stck[0] > med)
			push(b, a, 'a');
		else
			rotate(b, 'a');
		i++;
	}
	sort2ascend(a, 'a');
	sort2decend(b, 'b');
	push(a, b, 'b');
	push(a, b, 'b');
}

void	sort2ascend(t_stack *s, char c)
{
	if (s->stck[0] > s->stck[1])
		swap(s, c);
}

void	sort2decend(t_stack *s, char c)
{
	if (s->stck[0] < s->stck[1])
		swap(s, c);
}
