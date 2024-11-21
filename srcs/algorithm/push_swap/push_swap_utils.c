/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:35 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:51:49 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	update_totals(t_push_list *node, int total_rr, int total_rrr)
{
	if (total_rrr < total_rr)
	{
		node->rr = 0;
		node->rb = 0;
		node->ra = 0;
		node->total = total_rrr + 1;
	}
	else
	{
		node->rrr = 0;
		node->rrb = 0;
		node->rra = 0;
		node->total = total_rr + 1;
	}
}

static void	calculate_movements(t_push_list *node, t_push_list **list_sb,
		int list_len, int list_len_b)
{
	int	total_rr;
	int	total_rrr;

	node->rr = count_rr(&node);
	node->ra = count_ra(&node) - node->rr;
	node->rb = count_rb(&node) - node->rr;
	node->rrr = count_rrr(&node, list_sb, list_len, list_len_b);
	node->rra = count_rra(&node, list_len) - node->rrr;
	node->rrb = count_rrb(&node, list_len_b) - node->rrr;
	total_rr = node->rr + node->ra + node->rb;
	total_rrr = node->rrr + node->rra + node->rrb;
	update_totals(node, total_rr, total_rrr);
}

void	get_movement(t_push_list **list_sa, t_push_list **list_sb)
{
	int			list_len;
	int			list_len_b;
	t_push_list	*current;

	list_len = ft_listlen(*list_sa);
	list_len_b = ft_listlen(*list_sb);
	current = *list_sa;
	while (current)
	{
		calculate_movements(current, list_sb, list_len, list_len_b);
		current = current->next;
	}
}

void	get_right_order(t_push_list **list_sa)
{
	t_push_list	*list_min_number;
	int			number_ra;
	int			number_rra;
	int			list_size;

	list_size = ft_listlen(*list_sa);
	list_min_number = get_list_min(*list_sa);
	number_ra = list_min_number->index - 1;
	number_rra = (list_size - list_min_number->index) + 1;
	if (number_ra >= number_rra)
	{
		while (number_rra != 0)
		{
			action_rra(list_sa, 0);
			number_rra--;
		}
	}
	else
	{
		while (number_ra != 0)
		{
			action_ra(list_sa, 0);
			number_ra--;
		}
	}
}
