/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:34 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/17 20:29:29 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stack(t_stack *stack, int len)
{
	stack->stck = ft_calloc(len, sizeof(int));
	stack->size_ptr = 0;
	stack->size = &stack->size_ptr;
}

int	linesize(char *line)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i] != '\0')
			i++;
	}
	return (i);
}

void	checkline(char *line, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	if (line[0] == 's')
		swapinstruction(line, a, b);
	else if (line[0] == 'p')
		pushinstruction(line, a, b);
	else if (line[0] == 'r')
	{
		if (line[1] == 'r')
			reverserotateinstruction(line, a, b);
		else
			rotateinstruction(line, a, b);
	}
	else
		errorexit();
}

void	sort_them_numbers(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (linesize(line) > 1)
	{
		checkline(line, a, b);
		free(line);
		line = get_next_line(0);
		if (!line)
			break ;
	}
	if (line)
		free(line);
	if (checksorted(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	init_stack(&a, argc + 1);
	init_stack(&b, argc + 1);
	if (argc > 1)
	{
		if (!(errorcheck(argc, argv)))
			errorexit();
		i = 0;
		while (argv[i + 1] != NULL)
		{
			a.stck[i] = ft_atoi(argv[i + 1]);
			*a.size += 1;
			i++;
		}
		sort_them_numbers(&a, &b);
		freestack(&a);
		freestack(&b);
	}
	return (0);
}
