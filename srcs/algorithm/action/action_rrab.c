/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:53:38 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:40 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	action_rra(t_push_list **list_sa, int silent)
{
	t_push_list	*last;
	t_push_list	*second_last;

	if (!silent)
		ft_printf("rra\n");
	if (!list_sa || !(*list_sa) || (*list_sa)->next == NULL)
		return ;
	last = *list_sa;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list_sa;
	(*list_sa)->previous = last;
	last->previous = NULL;
	(*list_sa) = last;
	update_index(list_sa);
}

void	action_rrb(t_push_list **list_sb, int silent)
{
	t_push_list	*last;
	t_push_list	*second_last;

	if (!silent)
		ft_printf("rrb\n");
	if (!list_sb || !(*list_sb) || (*list_sb)->next == NULL)
		return ;
	last = *list_sb;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list_sb;
	(*list_sb)->previous = last;
	last->previous = NULL;
	(*list_sb) = last;
	update_index(list_sb);
}

void	action_rrr(t_push_list **list_sa, t_push_list **list_sb)
{
	ft_printf("rrr\n");
	action_rra(list_sa, 1);
	action_rrb(list_sb, 1);
	return ;
}
