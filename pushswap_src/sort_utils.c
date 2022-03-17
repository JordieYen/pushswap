/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:18:46 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/12 21:19:09 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push10biggest(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;

	t.stck = ft_calloc(10, sizeof(int));
	tsize = 0;
	t.size = &tsize;
	i = 0;
	while (i < 10)
	{
		t.stck[i] = getbigval(b, t);
		*t.size += 1;
		i++;
	}
	pushbiggest(a, b, getsmallest(&t), 10);
	freestack(&t);
}

void	push5biggest(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;

	t.stck = ft_calloc(5, sizeof(int));
	tsize = 0;
	t.size = &tsize;
	i = 0;
	while (i < 5)
	{
		t.stck[i] = getbigval(b, t);
		*t.size += 1;
		i++;
	}
	pushbiggest(a, b, getsmallest(&t), 5);
	freestack(&t);
}

void	push10smallest(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;

	t.stck = ft_calloc(10, sizeof(int));
	tsize = 0;
	t.size = &tsize;
	i = 0;
	while (i < 10)
	{
		t.stck[i] = getsmallval(a, t);
		*t.size += 1;
		i++;
	}
	pushsmallest(a, b, getbiggest(&t), 10);
	freestack(&t);
}

void	push5smallest(t_stack *a, t_stack *b)
{
	t_stack	t;
	int		tsize;
	int		i;

	t.stck = ft_calloc(5, sizeof(int));
	tsize = 0;
	t.size = &tsize;
	i = 0;
	while (i < 5)
	{
		t.stck[i] = getsmallval(a, t);
		*t.size += 1;
		i++;
	}
	pushsmallest(a, b, getbiggest(&t), 5);
	freestack(&t);
}
