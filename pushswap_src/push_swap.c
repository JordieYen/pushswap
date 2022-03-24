/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:44:34 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/18 18:29:53 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (*a->size == 2)
		sort2ascend(a, 'a');
	else if (*a->size == 3)
		sort3(a);
	else if (*a->size == 4)
		sort4ascend(a, b);
	else if (*a->size == 5)
		sort5(a, b);
	else if (*a->size > 5 && *a->size <= 10)
		sortunder10(a, b);
	else if (*a->size > 5 && *a->size <= 250)
		sort100(a, b);
	else if (*a->size > 250)
		sort500(a, b);
}

void	init_stack(t_stack *stack, int len)
{
	stack->stck = ft_calloc(len, sizeof(int));
	stack->size_ptr = 0;
	stack->size = &stack->size_ptr;
}

void	sort_them_numbers(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		init_stack(&a, argc + 1);
		init_stack(&b, argc + 1);
		i = 0;
		while (argv[i] != NULL)
		{
			a.stck[i] = ft_atoi(argv[i]);
			*a.size += 1;
			i++;
		}
		sort(&a, &b);
		freestack(&a);
		freestack(&b);
	}
}

int	main(int argc, char **argv)
{
	char	**argvnew;
	int		newarg;

	newarg = 1;
	if (argc == 2)
	{
		if (argvcheck(argv[1]))
		{
			argvnew = ft_split(argv[1], ' ');
			newarg = 0;
		}
	}
	if (newarg == 1)
	{
		if (!(errorcheck(argc, argv)))
			errorexit();
	}
	if (newarg == 0)
	{
		sort_them_numbers(getsizeofarg(argvnew), argvnew);
		freearg(argvnew);
	}
	else
		sort_them_numbers(argc - 1, argv + 1);
	return (0);
}
