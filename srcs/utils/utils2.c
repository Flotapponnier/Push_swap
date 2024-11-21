/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:51:41 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/20 20:51:58 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_push_list	*get_cheapest(t_push_list *list_sa)
{
	t_push_list	*current;
	t_push_list	*cheapest;
	int			min_total;

	if (!list_sa)
		return (NULL);
	current = list_sa;
	cheapest = current;
	min_total = current->total;
	while (current)
	{
		if (current->total < min_total)
		{
			min_total = current->total;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

t_push_list	*get_list_max(t_push_list *list)
{
	t_push_list	*max_node;

	max_node = list;
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->data > max_node->data)
			max_node = list;
		list = list->next;
	}
	return (max_node);
}

t_push_list	*get_list_min(t_push_list *list)
{
	t_push_list	*min_node;

	min_node = list;
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->data < min_node->data)
			min_node = list;
		list = list->next;
	}
	return (min_node);
}

void	reset_target_nodes(t_push_list **list_a)
{
	t_push_list	*current_a;

	if (!list_a || !(*list_a))
		return ;
	current_a = *list_a;
	while (current_a)
	{
		current_a->target_node = NULL;
		current_a = current_a->next;
	}
}
