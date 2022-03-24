/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:19:29 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:30:40 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkintover(char *num)
{
	int		i;
	char	*c;
	int		test;

	i = ft_atoi(num);
	c = ft_itoa(i);
	test = ft_strcmp(num, c);
	free(c);
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

int	argvcheck(char *argv)
{
	int		i;
	char	**tester;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!(ft_isdigit(argv[i]) || argv[i] == ' '))
			return (0);
		i++;
	}
	tester = ft_split(argv, ' ');
	i = 0;
	while (tester[i] != NULL)
	{
		if (!(checkintover(tester[i])))
			return (0);
		i++;
	}
	freearg(tester);
	return (1);
}

int	getsizeofarg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	errorexit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
