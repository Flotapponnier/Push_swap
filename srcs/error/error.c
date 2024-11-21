/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:53:36 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:47:48 by ftapponn         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void exit_list(t_push_list **list)
{
    t_push_list *current;
    t_push_list *next;

	print_error();
    current = *list;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
    exit(1);
}
