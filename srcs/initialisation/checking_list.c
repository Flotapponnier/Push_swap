/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:53:52 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:54:05 by ftapponn         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

static int	contains_duplicate(t_push_list *list, int data)
{
	while (list)
	{
		if (list->data == data)
			return (1);
		list = list->next;
	}
	return (0);
}

int	add_to_back_if_valid_float(t_push_list **list, double data)
{
	int	int_data;

	if (data < (double)INT_MIN_NB || data > (double)INT_MAX_NB)
		return (exit_list(list),0);
	int_data = (int)data;
	if ((double)int_data != data)
		return (exit_list(list),0);
	if (contains_duplicate(*list, int_data))
		return (exit_list(list),0);
	add_to_back(list, int_data);
	return (1);
}
