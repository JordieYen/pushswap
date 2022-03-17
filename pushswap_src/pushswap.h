/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:50:05 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/13 17:56:18 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
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
void	swap(t_stack *s, char c);
void	movesecondup(t_stack *s);
void	moveseconddown(t_stack *s);
void	push(t_stack *s1, t_stack *s2, char c);
void	rotate(t_stack *s, char c);
void	reverserotate(t_stack *s, char c);
void	reverserotate_n(t_stack *s, char c, int n);
void	printt_stack(t_stack *s);
int		checkascendi(t_stack *s, int n);
int		checkdecendi(t_stack *s, int n);
void	sort3a(t_stack *s);
void	sort3b(t_stack *s);
int		checksorted(t_stack *a, t_stack *b);
int		checkt(int val, t_stack t);
int		geti(t_stack *s, t_stack t);
int		getclose(t_stack *s);
void	rotatepush(int n, t_stack *a, t_stack *b);
int		getcloser(int len, t_stack t);
void	get10r(t_stack *a, t_stack *b);
void	get50r(t_stack *a, t_stack *b);
void	sort1to5a(t_stack *a, t_stack *b, int c);
void	sort5ascend(t_stack *a, t_stack *b);
void	sort1to5(t_stack *a, t_stack *b, int c);
void	sort5decend(t_stack *a, t_stack *b);
int		getbigval(t_stack *s, t_stack t);
int		getsmallval(t_stack *s, t_stack t);
int		getsmallest(t_stack *s);
int		getbiggest(t_stack *s);
void	pushbiggest(t_stack *a, t_stack *b, int min, int c);
void	pushsmallest(t_stack *a, t_stack *b, int max, int c);
void	push10biggest(t_stack *a, t_stack *b);
void	push5biggest(t_stack *a, t_stack *b);
void	push10smallest(t_stack *a, t_stack *b);
void	push5smallest(t_stack *a, t_stack *b);
void	sort500(t_stack *a, t_stack *b);
void	sort100(t_stack *a, t_stack *b);
void	sort3(t_stack *s);
int		getsmol(t_stack *s);
void	getsmolpush(t_stack *a, t_stack *b, int c);
void	sort5(t_stack *a, t_stack *b);
int		checkintover(char *c);
int		errorcheck(int argc, char **argv);
int		argvcheck(char *argv);
void	sort(t_stack *a, t_stack *b);
void	init_stack(t_stack *stack, int len);
void	sort_them_numbers(int argc, char **argv);
int		main(int argc, char **argv);

#endif
