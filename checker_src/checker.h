/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:05 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/17 16:51:22 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct stack
{
	int	*stck;
	int	*size;	
	int	size_ptr;
}	t_stack;

void	freearg(char **arg);
void	errorexit(void);
int		getsizeofarg(char **arg);
void	freestack(t_stack *s);
void	swap(t_stack *s);
void	movesecondup(t_stack *s);
void	moveseconddown(t_stack *s);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	reverserotate(t_stack *s);
void	printt_stack(t_stack *s);
int		checksorted(t_stack *a, t_stack *b);
int		checkintover(char *c);
int		errorcheck(int argc, char **argv);
void	sort(t_stack *a, t_stack *b);
void	swapinstruction(char *line, t_stack *a, t_stack *b);
void	pushinstruction(char *line, t_stack *a, t_stack *b);
void	rotateinstruction(char *line, t_stack *a, t_stack *b);
void	reverserotateinstruction(char *line, t_stack *a, t_stack *b);
void	init_stack(t_stack *stack, int len);
void	sort_them_numbers(t_stack *a, t_stack *b);
int		main(int argc, char **argv);

#endif
