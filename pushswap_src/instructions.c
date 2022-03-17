/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:51:44 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:52:16 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *s, char c)
{
	int	i;

	if (*s->size >= 2)
	{
		i = s->stck[0];
		s->stck[0] = s->stck[1];
		s->stck[1] = i;
		ft_putstr_fd("s", 1);
		ft_putchar_fd(c, 1);
		ft_putendl_fd("", 1);
	}
}

void	push(t_stack *s1, t_stack *s2, char c)
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
		ft_putstr_fd("p", 1);
		ft_putchar_fd(c, 1);
		ft_putendl_fd("", 1);
		s2->stck[0] = firstt_stack1;
		*s2->size += 1;
	}
}

void	rotate(t_stack *s, char c)
{
	int	first;

	first = s->stck[0];
	movesecondup(s);
	ft_putstr_fd("r", 1);
	ft_putchar_fd(c, 1);
	ft_putendl_fd("", 1);
	s->stck[*s->size - 1] = first;
}

void	reverserotate(t_stack *s, char c)
{
	int	last;

	last = s->stck[*s->size - 1];
	moveseconddown(s);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putendl_fd("", 1);
	s->stck[0] = last;
}

void	reverserotate_n(t_stack *s, char c, int n)
{
	while (n > 0)
	{
		reverserotate(s, c);
		n--;
	}
}
