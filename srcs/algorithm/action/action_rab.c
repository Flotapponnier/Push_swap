/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:53:28 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:31 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	action_ra(t_push_list **list_sa, int silent)
{
	t_push_list	*first;
	t_push_list	*last;

	if (!silent)
		ft_printf("ra\n");
	if (!list_sa || !*list_sa || !(*list_sa)->next)
		return ;
	first = *list_sa;
	last = *list_sa;
	while (last->next)
		last = last->next;
	*list_sa = first->next;
	(*list_sa)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	update_index(list_sa);
}

void	action_rb(t_push_list **list_sb, int silent)
{
	t_push_list	*first;
	t_push_list	*last;

	if (!silent)
		ft_printf("rb\n");
	if (!list_sb || !*list_sb || !(*list_sb)->next)
		return ;
	first = *list_sb;
	last = *list_sb;
	while (last->next)
		last = last->next;
	*list_sb = first->next;
	(*list_sb)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	update_index(list_sb);
}

void	action_rr(t_push_list **list_sa, t_push_list **list_sb)
{
	ft_printf("rr\n");
	action_ra(list_sa, 1);
	action_rb(list_sb, 1);
	return ;
}
