/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:04:55 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/20 21:04:57 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	count_rr(t_push_list **list_sa)
{
	int	count_sa;
	int	count_sb;

	count_sa = (*list_sa)->index;
	if (!(*list_sa)->target_node->index)
		count_sb = 1;
	else
		count_sb = (*list_sa)->target_node->index;
	if (count_sa == 1 || count_sb == 1)
		return (0);
	count_sa--;
	count_sb--;
	if (count_sa > count_sb)
		return (count_sb);
	else if (count_sa < count_sb)
		return (count_sa);
	else
		return (count_sa);
}

int	count_ra(t_push_list **list_sa)
{
	int	count_sa;

	count_sa = (*list_sa)->index;
	if (count_sa == 1)
		return (0);
	count_sa--;
	return (count_sa);
}

int	count_rb(t_push_list **list_sa)
{
	int	count_sb;

	count_sb = (*list_sa)->target_node->index;
	if (count_sb == 1)
		return (0);
	count_sb--;
	return (count_sb);
}
