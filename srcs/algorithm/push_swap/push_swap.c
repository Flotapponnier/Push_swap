/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:10:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 16:10:51 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	push_to_b(t_push_list **list_sa, t_push_list **list_sb)
{
	t_push_list	*element_to_push;
	int			size_list;

	size_list = ft_listlen(*list_sa);
	while (size_list != 3)
	{
		element_to_push = (*list_sa);
		reset_target_nodes(list_sa);
		get_list_targetnode(list_sa, list_sb);
		get_movement(list_sa, list_sb);
		element_to_push = get_cheapest(*list_sa);
		launch_action(element_to_push, list_sa, list_sb);
		size_list = ft_listlen(*list_sa);
	}
	get_right_order(list_sa);
	return ;
}

void	push_to_a(t_push_list **list_sa, t_push_list **list_sb)
{
	t_push_list	*element_to_push;
	int			size_list;

	size_list = ft_listlen(*list_sa);
	while (size_list != 0)
	{
		reset_target_nodes(list_sb);
		reset_target_nodes(list_sa);
		get_list_targetnode_b(list_sb, list_sa);
		get_movement(list_sb, list_sa);
		element_to_push = get_cheapest(*list_sb);
		launch_action_b(element_to_push, list_sb, list_sa);
		size_list = ft_listlen(*list_sb);
	}
	get_right_order(list_sa);
	return ;
}

void	ft_initialise_swap(t_push_list **list_sa, t_push_list **list_sb)
{
	if ((*list_sa)->data < (*list_sa)->next->data)
	{
		action_pb(list_sa, list_sb);
		action_pb(list_sa, list_sb);
	}
	else
	{
		action_ra(list_sa, 0);
		action_pb(list_sa, list_sb);
	}
}

void	push_swap(t_push_list **list_sa, t_push_list **list_sb)
{
	ft_initialise_swap(list_sa, list_sb);
	push_to_b(list_sa, list_sb);
	tiny_sort(list_sa);
	push_to_a(list_sa, list_sb);
}
