/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:47:59 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 18:31:58 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	freestack(t_stack *s)
{
	free(s->stck);
	s->stck = NULL;
}

void	printt_stack(t_stack *s)
{
	int	i;

	i = 0;
	printf("( ");
	while (i < *s->size)
	{
		printf("%d ", s->stck[i]);
		i++;
	}
	printf(")\n");
}

void	freearg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
