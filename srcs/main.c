/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:49:00 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:52:01 by ftapponn         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int argc, char **argv)
{
	t_push_list	*list_sa;
	t_push_list	*list_sb;

	list_sb = NULL;
	if (argc == 1)
		return (1);
	if (!is_valid_parameters(argc, argv))
		return (print_error(), 1);
	else if ((is_valid_parameters(argc, argv)) == MULTIPLE_ARGUMENT)
	{
		list_sa = parse_multiple_arguments(argc, argv);
		if (!list_sa)
			return (print_error(), 1);
	}
	else
	{
		list_sa = parse_numbers(argv[1]);
		if (!list_sa)
			return (print_error(), 1);
	}
	if (!list_sa)
		return (print_error(), 1);
	choose_algorithm(&list_sa, &list_sb);
	free(list_sa);
	free(list_sb);
}
