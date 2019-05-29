/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:09:37 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:10:51 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/srcs/includes/libft.h"
#include <stdio.h>
# define MARKER 0
# define DATA 1
# define EMPTY 0
# define FULL 1
# define USED 2
# define TO_PUSH 3
# define CDIV 20

typedef struct				s_pile
{
	int						**p_a;
	int						**p_b;
	int						size_a;
	int						size_b;
	int						op_nbr;
}							t_pile;

int							ft_error(char *str);
int							init_piles(int ac, char **av, t_pile *piles);
int							init_piles2(int cpt, char **res, t_pile *piles);
int							check_overflow(long long a);
void						check_valid_input(int ac, char **av);
void						check_valid_input2(char **av, t_pile *piles);
int							push_op(t_pile *piles, char *str);
int							swap_op(t_pile *piles, char *str);
int							rotate_op(t_pile *piles, char *str);
int							revrotate_op(t_pile *piles, char *str);
int							all_ops(char *str, t_pile *piles, int a);
int							sort_checker(t_pile piles);
int							checker_instructions(t_pile *piles);
int							push_swap_instructions(t_pile *piles);
int							find_bigest_in_a(t_pile *piles);
int							find_bigest_in_b(t_pile *piles);
int							find_smallest_in_a(t_pile *piles);
int							algo_ps1(t_pile *piles);
int							small_algo(t_pile *piles);
int							small_algov2(t_pile *piles, char c);
void						small_sort_a(t_pile *piles);
int							small_algov3(t_pile *piles);
void						small_sort_b(t_pile *piles);
int							check_dirty_plates_a(t_pile *piles);
int							big_algo(t_pile *piles);
int							big_algo2(t_pile *piles);
int							big_algo3(t_pile *piles);
int							a_is_sorted(t_pile piles);
void						clean_markers(t_pile *piles);
void						clean_markers_a(t_pile *piles);
int							find_median_index_a(t_pile *piles);
int							scan_the_conquered(t_pile *piles);
void						push_the_conquered(t_pile *piles);
int							check_layer_a(t_pile *piles);
void						sort_from_b(t_pile *piles);
int							counter_b(t_pile *piles);
int							counter_a(t_pile *piles);
int							divide_and_conquer(t_pile *piles);
void						push_on_half_median(t_pile *piles, int nb);
void						divide_top_a(t_pile *piles);
void						divide_top_b(t_pile *piles);
void						push_half_group_b(t_pile *piles);
int							get_new_median_b(t_pile *piles);
int							get_new_median_a(t_pile *piles);
int							detect_first_usable_elem_b(t_pile *piles);
void						free_piles(t_pile *piles);

#endif
