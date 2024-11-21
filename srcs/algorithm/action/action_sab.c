/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:53:45 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:47 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	action_sa(t_push_list **list_sa, int silent)
{
	t_push_list	*first;
	t_push_list	*second;

	if (!silent)
		ft_printf("sa\n");
	if (!list_sa || !*list_sa || !(*list_sa)->next)
		return ;
	first = *list_sa;
	second = (*list_sa)->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	*list_sa = second;
	first->previous = second;
	update_index(list_sa);
}

void	action_sb(t_push_list **list_sb, int silent)
{
	t_push_list	*first;
	t_push_list	*second;

	if (!silent)
		ft_printf("sa\n");
	if (!list_sb || !*list_sb || !(*list_sb)->next)
		return ;
	first = *list_sb;
	second = (*list_sb)->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	*list_sb = second;
	first->previous = second;
	update_index(list_sb);
}

void	action_ss(t_push_list **list_sa, t_push_list **list_sb)
{
	ft_printf("ss\n");
	action_sa(list_sa, 1);
	action_sb(list_sb, 1);
	return ;
}
