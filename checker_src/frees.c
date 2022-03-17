/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:47:59 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/16 18:53:11 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
