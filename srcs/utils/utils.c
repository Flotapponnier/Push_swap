/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:51:11 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 16:02:33 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_listlen(t_push_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	free_list(t_push_list *list)
{
	t_push_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	update_index(t_push_list **list)
{
	t_push_list	*head;
	int			index;
	static int	count = 0;

	count++;
	head = *list;
	index = 1;
	while (*list)
	{
		(*list)->index = index;
		index++;
		*list = (*list)->next;
	}
	(*list) = head;
}

/*
void	print_list(t_push_list *list)
{
	t_push_list	*node;

	node = list;
	while (node)
	{
		if (node->target_node)
		{
			ft_printf("Element index: %d, data: %d", node->index, node->data);
		}
		else
		{
			ft_printf("Element index: %d, data: %d, target node: NULL\n",
				node->index, node->data);
		}
		node = node->next;
	}
	ft_printf("\n\n");
}
*/
