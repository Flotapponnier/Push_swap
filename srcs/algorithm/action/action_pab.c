/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:59:21 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/20 21:02:53 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	action_pa(t_push_list **list_sa, t_push_list **list_sb)
{
	t_push_list	*tmp;

	ft_printf("pa\n");
	if (!(*list_sa))
		return ;
	tmp = *list_sa;
	*list_sa = tmp->next;
	if (*list_sa)
		(*list_sa)->previous = NULL;
	tmp->next = *list_sb;
	if (*list_sb)
		(*list_sb)->previous = tmp;
	*list_sb = tmp;
	tmp->previous = NULL;
	update_index(list_sa);
	update_index(list_sb);
}

void	action_pb(t_push_list **list_sb, t_push_list **list_sa)
{
	t_push_list	*tmp;

	ft_printf("pb\n");
	if (!(*list_sb))
		return ;
	tmp = *list_sb;
	*list_sb = tmp->next;
	if (*list_sb)
		(*list_sb)->previous = NULL;
	tmp->next = *list_sa;
	if (*list_sa)
		(*list_sa)->previous = tmp;
	*list_sa = tmp;
	tmp->previous = NULL;
	update_index(list_sb);
	update_index(list_sa);
}
