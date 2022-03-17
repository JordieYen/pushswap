/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:51:44 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/17 20:02:41 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *s)
{
	int	i;

	if (*s->size >= 2)
	{
		i = s->stck[0];
		s->stck[0] = s->stck[1];
		s->stck[1] = i;
	}
}

void	push(t_stack *s1, t_stack *s2)
{
	int	firstt_stack1;
	int	i;

	i = 0;
	if (*s1->size > 0)
	{
		firstt_stack1 = s1->stck[0];
		movesecondup(s1);
		*s1->size -= 1;
		moveseconddown(s2);
		s2->stck[0] = firstt_stack1;
		*s2->size += 1;
	}
}

void	rotate(t_stack *s)
{
	int	first;

	first = s->stck[0];
	movesecondup(s);
	s->stck[*s->size - 1] = first;
}

void	reverserotate(t_stack *s)
{
	int	last;

	last = s->stck[*s->size - 1];
	moveseconddown(s);
	s->stck[0] = last;
}
