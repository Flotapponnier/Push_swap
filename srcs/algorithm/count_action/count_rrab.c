/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rrab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:05:55 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/20 21:05:59 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	count_rrr(t_push_list **list_sa, t_push_list **list_sb, int list_len,
		int list_len_b)
{
	int	count_sa;
	int	count_sb;

	if (*list_sa == NULL || (*list_sa)->target_node == NULL || *list_sb == NULL)
		return (0);
	count_sa = (*list_sa)->index;
	count_sb = (*list_sa)->target_node->index;
	if (count_sa == 1 || count_sb == 1)
		return (0);
	if (count_sa == list_len || count_sb == list_len_b)
		return (1);
	count_sa = list_len - count_sa + 1;
	count_sb = list_len_b - count_sb + 1;
	if (count_sa > count_sb)
		return (count_sb);
	else if (count_sa < count_sb)
		return (count_sa);
	else
		return (count_sa);
}

int	count_rra(t_push_list **list_sa, int list_len)
{
	int	count_sa;

	if (*list_sa == NULL || (*list_sa)->target_node == NULL)
		return (0);
	count_sa = (*list_sa)->index;
	if (count_sa == 1)
		return (0);
	if (count_sa == list_len)
		return (1);
	count_sa = list_len - count_sa + 1;
	return (count_sa);
}

int	count_rrb(t_push_list **list_sb, int list_len)
{
	int	count_sb;

	if (*list_sb == NULL || (*list_sb)->target_node == NULL)
		return (0);
	count_sb = (*list_sb)->target_node->index;
	if (count_sb == 1)
		return (0);
	if (count_sb == list_len)
		return (1);
	count_sb = list_len - count_sb + 1;
	return (count_sb);
}
