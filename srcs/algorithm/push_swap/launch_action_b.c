/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_action_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:09 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 15:13:12 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	launch_rrr_rra_rrb(t_push_list *element, t_push_list **list_sb,
		t_push_list **list_sa)
{
	while (element->rrr > 0)
	{
		action_rrr(list_sb, list_sa);
		element->rrr--;
	}
	while (element->rra > 0)
	{
		action_rrb(list_sb, 0);
		element->rra--;
	}
	while (element->rrb > 0)
	{
		action_rra(list_sa, 0);
		element->rrb--;
	}
}

void	launch_rr_ra_rb(t_push_list *element, t_push_list **list_sb,
		t_push_list **list_sa)
{
	while (element->rr > 0)
	{
		action_rr(list_sb, list_sa);
		element->rr--;
	}
	while (element->ra > 0)
	{
		action_rb(list_sb, 0);
		element->ra--;
	}
	while (element->rb > 0)
	{
		action_ra(list_sa, 0);
		element->rb--;
	}
}

void	launch_action_b(t_push_list *element, t_push_list **list_sb,
		t_push_list **list_sa)
{
	launch_rrr_rra_rrb(element, list_sb, list_sa);
	launch_rr_ra_rb(element, list_sb, list_sa);
	action_pa(list_sb, list_sa);
}
