/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:28:14 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/20 20:49:41 by ftapponn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	is_valid_space(char *str, int i)
{
	if (str[i] == ' ' && (i == 0 || str[i + 1] == ' ' || str[i + 1] == '\0'))
		return (0);
	return (1);
}

static int	is_valid_number(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
		return (0);
	return (1);
}

static int	process_argument(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
		{
			if (!is_valid_space(arg, i))
				return (0);
			i++;
			continue ;
		}
		if (!is_valid_number(arg, &i))
			return (0);
	}
	return (1);
}

int	is_valid_parameters(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		return (process_argument(argv[1]));
	else
		return (valid_multiple_arguments(argc, argv));
}
