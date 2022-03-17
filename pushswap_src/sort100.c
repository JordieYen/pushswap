/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:38 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:50:41 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort100(t_stack *a, t_stack *b)
{
	int	i;

	while (*a->size > 10)
		get10r(a, b);
	i = 0;
	push5smallest(a, b);
	sort5ascend(a, b);
	sort5decend(a, b);
	while (i < 9)
	{
		push10biggest(a, b);
		push5smallest(a, b);
		sort5ascend(a, b);
		sort5decend(a, b);
		i++;
	}
}

void	get10r(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;
	int		j;

	j = 10;
	while (j > 0)
	{
		t.stck = ft_calloc(10, sizeof(int));
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
