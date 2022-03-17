/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:53:06 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:53:09 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_stack *s)
{
	if (s->stck[0] > s->stck[1] && s->stck[0] > s->stck[2])
		rotate(s, 'a');
	else if (s->stck[1] > s->stck[0] && s->stck[1] > s->stck[2])
		reverserotate(s, 'a');
	if (s->stck[0] > s->stck[1])
		swap(s, 'a');
}

void	sort3a(t_stack *s)
{
	while (!(checkascendi(s, 3)))
	{
		if (s->stck[0] > s->stck[1])
		{
			swap(s, 'a');
		}
		if (s->stck[1] > s->stck[2])
		{
			rotate(s, 'a');
			swap(s, 'a');
			reverserotate(s, 'a');
			if (s->stck[0] > s->stck[1])
				swap(s, 'a');
		}
	}
}

void	sort3b(t_stack *s)
{
	while (!(checkdecendi(s, 3)))
	{
		if (s->stck[0] < s->stck[1])
			swap(s, 'b');
		if (s->stck[1] < s->stck[2])
		{
			rotate(s, 'b');
			swap(s, 'b');
			reverserotate(s, 'b');
			if (s->stck[0] < s->stck[1])
				swap(s, 'b');
		}
	}
}
