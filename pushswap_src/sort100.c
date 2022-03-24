/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:38 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:01:40 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort100(t_stack *a, t_stack *b)
{
	while (*a->size > 10)
		get10r(a, b);
	sortunder10(a, b);
	while (!(checksorted(a, b)))
	{
		push10biggest(a, b);
		push5smallest(a, b);
		sort5ascend(a, b);
		sort5decend(a, b);
	}
}

void	get10r(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;
	int		j;

	j = 10;
	if (*a->size < 10)
		j = *a->size;
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
