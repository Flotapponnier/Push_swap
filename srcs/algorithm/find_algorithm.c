/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:33:26 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:33:31 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_issorted(t_push_list **list)
{
	t_push_list	*current;

	if (*list == NULL || (*list)->next == NULL)
		return (1);
	current = *list;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	choose_algorithm(t_push_list **list_sa, t_push_list **list_sb)
{
	int	size_list;

	size_list = ft_listlen(*list_sa);
	if (ft_issorted(list_sa))
		return ;
	if (size_list <= 2)
	{
		if (size_list > 1 && (*list_sa)->data > (*list_sa)->next->data)
			action_sa(list_sa, 0);
		return ;
	}
	else if (size_list == 3)
		tiny_sort(list_sa);
	else if (size_list <= 5)
		middle_sort(list_sa, list_sb);
	else
		push_swap(list_sa, list_sb);
	return ;
}
