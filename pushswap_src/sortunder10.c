/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortunder10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:11:56 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:06:57 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sortunder10(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (*a->size > 5)
	{
		i = 5;
		push5smallest(a, b);
	}
	if (*a->size == 5)
		sort5ascend(a, b);
	else if (*a->size == 4)
		sort4ascend(a, b);
	else if (*a->size == 3)
		sort3a(a);
	else if (*a->size == 2)
		sort2ascend(a, 'a');
	if (i == 5)
		sort5decend(a, b);
}
