/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftapponn <ftapponn@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:27:48 by ftapponn          #+#    #+#             */
/*   Updated: 2024/11/21 20:48:18 by ftapponn         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MULTIPLE_ARGUMENT 42
# define ERROR_PARAMETER 1
# define ERROR_MALLOC 2
# define ERROR_NUMBER 3
# define INT_MAX_NB 2147483648
# define INT_MIN_NB -2147483648

# include "libft.h"

typedef struct s_push_list
{
	struct s_push_list	*target_node;
	struct s_push_list	*next;
	struct s_push_list	*previous;
	int					data;
	int					index;
	int					ra;
	int					rra;
	int					rb;
	int					rrb;
	int					rr;
	int					rrr;
	int					sa;
	int					sb;
	int					total;
}						t_push_list;

// push_swap
void					choose_algorithm(t_push_list **list_sa,
							t_push_list **list_sb);
void					push_swap(t_push_list **list_sa, t_push_list **list_sb);
void					push_to_b(t_push_list **list_sa, t_push_list **list_sb);
void					ft_initialise_swap(t_push_list **list_sa,
							t_push_list **list_sb);
// push swap utils
void					get_movement(t_push_list **list_sa,
							t_push_list **list_sb);
void					get_right_order(t_push_list **list_sa);
void					get_list_targetnode_b(t_push_list **list_sb,
							t_push_list **list_sa);
void					get_list_targetnode(t_push_list **list_a,
							t_push_list **list_b);

// launch action
void					launch_action(t_push_list *element,
							t_push_list **list_sa, t_push_list **list_sb);
void					launch_action_b(t_push_list *element,
							t_push_list **list_sb, t_push_list **list_sa);

// count_action
int						count_rb(t_push_list **list_sa);
int						count_ra(t_push_list **list_sa);
int						count_rr(t_push_list **list_sa);
int						count_rrr(t_push_list **list_sa, t_push_list **list_sb,
							int list_len, int list_len_b);
int						count_rra(t_push_list **list_sa, int list_len);
int						count_rrb(t_push_list **list_sa, int list_len);

// action
void					action_pa(t_push_list **list_sa, t_push_list **list_sb);
void					action_pb(t_push_list **list_sb, t_push_list **list_sa);
void					action_ra(t_push_list **list_sa, int silent);
void					action_rb(t_push_list **list_sb, int silent);
void					action_rr(t_push_list **list_sa, t_push_list **list_sb);
void					action_rra(t_push_list **list_sa, int silent);
void					action_rrb(t_push_list **list_sb, int silent);
void					action_rrr(t_push_list **list_sa,
							t_push_list **list_sb);
void					action_sa(t_push_list **list_sa, int silent);
void					action_sb(t_push_list **list_sb, int silent);
void					action_ss(t_push_list **list_sa, t_push_list **list_sb);

// tiny_middle_sort
void					tiny_sort(t_push_list **list);
void					middle_sort(t_push_list **list_sa,
							t_push_list **list_sb);

// find_algorithm
void					choose_algorithm(t_push_list **list_sa,
							t_push_list **list_sb);

// validation
int						is_valid_parameters(int argc, char **argv);
int						valid_multiple_arguments(int argc, char **argv);
int						is_valid_list(t_push_list *list);

// checking list
int						add_to_back_if_valid_float(t_push_list **list,
							double data);

// initialisation
t_push_list				*create_node(int data);
void					add_to_back(t_push_list **list, int data);
t_push_list				*parse_numbers(char *str);
t_push_list				*parse_multiple_arguments(int argc, char **argv);

// utils
void					free_list(t_push_list *list);
void					update_index(t_push_list **list);
void					get_list_position(t_push_list **list);
int						ft_listlen(t_push_list *lst);
void					print_list(t_push_list *list);

// utils 2
t_push_list				*get_list_min(t_push_list *list);
t_push_list				*get_list_max(t_push_list *list);
t_push_list				*get_cheapest(t_push_list *list_sa);
void					reset_target_nodes(t_push_list **list_a);

// error
void					print_error(void);
void					exit_list(t_push_list **list);
#endif
