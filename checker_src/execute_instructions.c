/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:30:12 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/17 20:23:43 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swapinstruction(char *line, t_stack *a, t_stack *b)
{
	if (line[1] == 'a' && line[2] == '\n')
		swap(a);
	else if (line[1] == 'b' && line[2] == '\n')
		swap(b);
	else if (line[1] == 's' && line[2] == '\n')
	{
		swap(a);
		swap(b);
	}
	else
		errorexit();
}

//first letter in line is 'p'
void	pushinstruction(char *line, t_stack *a, t_stack *b)
{
	if (line[1] == 'a' && line[2] == '\n')
		push(b, a);
	else if (line[1] == 'b' && line[2] == '\n')
		push(a, b);
	else
		errorexit();
}

//first letter in line is 'r'
void	rotateinstruction(char *line, t_stack *a, t_stack *b)
{
	if (line[1] == 'a' && line[2] == '\n')
		rotate(a);
	else if (line[1] == 'b' && line[2] == '\n')
		rotate(b);
	else
		errorexit();
}

//first and second letter in line is 'r'
void	reverserotateinstruction(char *line, t_stack *a, t_stack *b)
{
	if (line[1] == 'r' && line[2] == '\n')
	{
		rotate(a);
		rotate(b);
	}
	else if (line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		reverserotate(a);
	else if (line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		reverserotate(b);
	else if (line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
	{
		reverserotate(a);
		reverserotate(b);
	}
	else
		errorexit();
}
