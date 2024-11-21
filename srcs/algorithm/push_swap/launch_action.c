/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:02:28 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 16:10:36 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	handle_double_rotations(t_push_list *element, t_push_list **list_sa,
		t_push_list **list_sb)
{
	while (element->rrr > 0)
	{
		action_rrr(list_sa, list_sb);
		element->rrr--;
	}
	while (element->rr > 0)
	{
		action_rr(list_sa, list_sb);
		element->rr--;
	}
}

void	handle_rotations_a(t_push_list *element, t_push_list **list_sa)
{
	while (element->rra > 0)
	{
		action_rra(list_sa, 0);
		element->rra--;
	}
	while (element->ra > 0)
	{
		action_ra(list_sa, 0);
		element->ra--;
	}
}

void	handle_rotations_b(t_push_list *element, t_push_list **list_sb)
{
	while (element->rrb > 0)
	{
		action_rrb(list_sb, 0);
		element->rrb--;
	}
	while (element->rb > 0)
	{
		action_rb(list_sb, 0);
		element->rb--;
	}
}

void	launch_action(t_push_list *element, t_push_list **list_sa,
		t_push_list **list_sb)
{
	handle_double_rotations(element, list_sa, list_sb);
	handle_rotations_a(element, list_sa);
	handle_rotations_b(element, list_sb);
	action_pb(list_sa, list_sb);
}
