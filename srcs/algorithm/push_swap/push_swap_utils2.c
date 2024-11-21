/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:43:20 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:44:24 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_push_list	*find_best_match(t_push_list *current_a, t_push_list *list_b,
		t_push_list *min_b, t_push_list *max_b)
{
	t_push_list	*best_match;
	t_push_list	*current_b;

	best_match = NULL;
	current_b = list_b;
	if (current_a->data < min_b->data)
		best_match = max_b;
	else if (current_a->data > max_b->data)
		best_match = max_b;
	else
	{
		while (current_b)
		{
			if (current_b->data <= current_a->data && (!best_match
					|| current_b->data > best_match->data))
				best_match = current_b;
			current_b = current_b->next;
		}
	}
	return (best_match);
}

void	get_list_targetnode(t_push_list **list_a, t_push_list **list_b)
{
	t_push_list	*current_a;
	t_push_list	*min_b;
	t_push_list	*max_b;
	t_push_list	*best_match;

	if (!list_a || !list_b || !(*list_a) || !(*list_b))
		return ;
	min_b = get_list_min(*list_b);
	max_b = get_list_max(*list_b);
	current_a = *list_a;
	while (current_a)
	{
		best_match = find_best_match(current_a, *list_b, min_b, max_b);
		current_a->target_node = best_match;
		current_a = current_a->next;
	}
}

t_push_list	*find_best_match_b(t_push_list *current_b, t_push_list *list_a)
{
	t_push_list	*current_a;
	t_push_list	*best_match;

	current_a = list_a;
	best_match = NULL;
	while (current_a)
	{
		if (current_a->data > current_b->data)
		{
			if (!best_match || current_a->data < best_match->data)
				best_match = current_a;
		}
		current_a = current_a->next;
	}
	if (!best_match)
		best_match = get_list_min(list_a);
	return (best_match);
}

void	get_list_targetnode_b(t_push_list **list_sb, t_push_list **list_sa)
{
	t_push_list	*current_b;
	t_push_list	*min_b;
	t_push_list	*max_b;
	t_push_list	*best_match;

	if (!list_sb || !list_sa || !(*list_sb) || !(*list_sa))
		return ;
	min_b = get_list_min(*list_sa);
	max_b = get_list_max(*list_sa);
	current_b = *list_sb;
	while (current_b)
	{
		best_match = NULL;
		if (current_b->data == max_b->data)
			best_match = min_b;
		else
			best_match = find_best_match_b(current_b, *list_sa);
		current_b->target_node = best_match;
		current_b = current_b->next;
	}
}
