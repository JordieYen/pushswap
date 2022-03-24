/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:51:07 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:01:47 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort500(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (*a->size > 50)
		get50r(a, b);
	while (*a->size > 10)
	{
		push10smallest(a, b);
		i += 1;
	}
	sortunder10(a, b);
	while (i > 0)
	{
		push5biggest(a, b);
		sort5ascend(a, b);
		sort5decend(a, b);
		i--;
	}
	while (!(checksorted(a, b)))
	{
		push10biggest(a, b);
		push5smallest(a, b);
		sort5ascend(a, b);
		sort5decend(a, b);
	}
}

void	get50r(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;
	int		j;

	j = 50;
	while (j > 0)
	{
		t.stck = ft_calloc(50, sizeof(int));
		tsize = 0;
		t.size = &tsize;
		i = 0;
		while (i < j)
		{
			t.stck[i] = geti(a, t);
			*t.size += 1;
			i++;
		}
		j--;
		rotatepush(getcloser(*a->size, t), a, b);
		freestack(&t);
	}
}
