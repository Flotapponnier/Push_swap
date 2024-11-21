/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:54:07 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:05:36 by ftapponn         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_push_list	*create_node(int data)
{
	t_push_list	*new_node;

	new_node = (t_push_list *)malloc(sizeof(t_push_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->target_node = NULL;
	new_node->index = 0;
	return (new_node);
}

void	add_to_back(t_push_list **list, int data)
{
	t_push_list	*new_node;
	t_push_list	*temp;

	new_node = create_node(data);
	if (!new_node)
		return ;
	if (!(*list))
	{
		*list = new_node;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->previous = temp;
}

t_push_list	*parse_multiple_arguments(int argc, char **argv)
{
	t_push_list	*list;
	int			i;
	double		num;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atod(argv[i]);
		if (!add_to_back_if_valid_float(&list, num))
			return (NULL);
		i++;
	}
	return (list);
}

t_push_list	*parse_numbers(char *str)
{
	t_push_list	*list;
	char		**numbers;
	int			i;
	double		num;

	list = NULL;
	numbers = ft_split(str, ' ');
	i = 0;
	while (numbers[i])
	{
		num = ft_atod(numbers[i]);
		if (!add_to_back_if_valid_float(&list, num))
			return (NULL);
		i++;
	}
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	return (list);
}
