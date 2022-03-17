/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:19:29 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/17 20:27:49 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checkintover(char *num)
{
	int		i;
	char	*c;
	int		test;

	i = ft_atoi(num);
	c = ft_itoa(i);
	test = ft_strcmp(num, c);
	if (test == 0)
		return (1);
	return (0);
}

int	errorcheck(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!(checkintover(argv[i])))
			return (0);
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	errorexit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	checksorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < (*a->size - 1))
	{
		if (a->stck[i] > a->stck[i + 1])
			return (0);
		i++;
	}
	if (*b->size != 0)
		return (0);
	return (1);
}
