/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_soln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:51:09 by hchua             #+#    #+#             */
/*   Updated: 2023/08/05 16:51:13 by hchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_put1nb(char nb);
void	print_array(int **array, int x, int y);

int	scan_for_n(int **view, int view_direction_i, int n_view)
{
	int	j;
	
	j = -1;
	while (j++ < 4)
		if (view[view_direction_i][j] == n_view)
			return(j);
	return (1);
}

int	insert_value_col(int **grid, int coord_col)
{
	int 	i;
	
	i = 0;
	while (i < 4)
	{
		grid[i][coord_col] = i + 1;
		i++;
	}
	return (1);
}

int	insert_value_row(int **grid, int coord_row)
{
	int 	i;
	
	i = 0;
	while (i < 4)
	{
		grid[coord_row][i] = i + 1;
		i++;
	}
	return (1);
}

int	three_insert_value_col(int **grid, int **view, int **view_three_table, int coord_col)
{
	int	coldown;
	int	i;
	int	j;
	
	coldown = view[1][coord_col];
	printf("value of coldown = %d\n", coldown);
	i = 0;
	while ( i < 6 && view_three_table[i][4] == coldown)
	{
		j = 0;
		while (j < 4 )
		{
			if (view_three_table[i][j] == grid[j][coord_col])
			{
				j=0;
				printf("i counter = %d\n", i);
				while (j < 4)
				{
					grid[j][coord_col] = view_three_table[i][j];
					j++;
				}
				return (1);
			}	
			j++;
		}
		i++;	
	}
	return (0);
}

int	gen_soln(int **view, int **grid, int **view_three_table, int grid_size)
{
	int	scan_colup;
	int	scan_rowleft;
	
	scan_colup = scan_for_n(view, 0, 4);	
	scan_rowleft = scan_for_n(view, 2, 4);
	insert_value_col(grid, scan_colup);
	insert_value_row(grid, scan_rowleft);
	scan_colup = scan_for_n(view, 0, 3);
	three_insert_value_col(grid, view, view_three_table, scan_colup);
	printf("scan_colup for 3: %d\n", scan_colup);
	printf("\n");	
	print_array(grid, grid_size, grid_size);
	print_array(view_three_table, 6, 5);
	return (1);
}
