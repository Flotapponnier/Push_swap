/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_middle_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:53:10 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:53:11 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_min_position(t_push_list *list)
{
	int			min_value;
	int			min_position;
	int			current_position;
	t_push_list	*current;

	min_value = list->data;
	min_position = 0;
	current_position = 0;
	current = list;
	while (current != NULL)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			min_position = current_position;
		}
		current_position++;
		current = current->next;
	}
	return (min_position);
}

void	bring_to_top(t_push_list **list, int position)
{
	int	size;

	size = ft_listlen(*list);
	if (position <= size / 2)
	{
		while (position-- > 0)
			action_ra(list, 0);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			action_rra(list, 0);
	}
}

void	push_min_to_b(t_push_list **list_sa, t_push_list **list_sb)
{
	int	min_pos;

	min_pos = find_min_position(*list_sa);
	bring_to_top(list_sa, min_pos);
	action_pb(list_sa, list_sb);
}

void	tiny_sort(t_push_list **list)
{
	if ((*list)->data > (*list)->next->data
		&& (*list)->next->data < (*list)->next->next->data
		&& (*list)->data < (*list)->next->next->data)
		action_sa(list, 0);
	else if ((*list)->data > (*list)->next->data
		&& (*list)->next->data > (*list)->next->next->data)
	{
		action_sa(list, 0);
		action_rra(list, 0);
	}
	else if ((*list)->data > (*list)->next->data
		&& (*list)->data > (*list)->next->next->data)
		action_ra(list, 0);
	else if ((*list)->data < (*list)->next->data
		&& (*list)->data < (*list)->next->next->data
		&& (*list)->next->data > (*list)->next->next->data)
	{
		action_sa(list, 0);
		action_ra(list, 0);
	}
	else if ((*list)->data < (*list)->next->data
		&& (*list)->data > (*list)->next->next->data)
		action_rra(list, 0);
}

void	middle_sort(t_push_list **list_sa, t_push_list **list_sb)
{
	int	size_list;

	size_list = ft_listlen(*list_sa);
	if (size_list == 4)
	{
		push_min_to_b(list_sa, list_sb);
		tiny_sort(list_sa);
		action_pa(list_sb, list_sa);
	}
	else if (size_list == 5)
	{
		push_min_to_b(list_sa, list_sb);
		push_min_to_b(list_sa, list_sb);
		tiny_sort(list_sa);
		action_pa(list_sb, list_sa);
		action_pa(list_sb, list_sa);
	}
}
