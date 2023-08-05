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
	
	i = -1;
	while (i++ < 4)
	{
		grid[i][coord_col] = i + 1;
	}
	return (1);
}

int	insert_value_row(int **grid, int coord_row)
{
	int 	i;
	
	i = -1;
	while (i++ < 4)
	{
		grid[coord_row][i] = i + 1;
	}
	return (1);
}

void	ft_put1nb(char nb)
{
	write(1, &nb, 1);
	write(1, " ", 1);
}

void	print_array(int **array, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			ft_put1nb(array[i][j] + '0');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	gen_soln(int **view, int **grid, int grid_size)
{
	int	scan_colup;
	int	scan_rowleft;
	
	print_array(view, grid_size, grid_size);
	scan_rowleft = scan_for_n(view, 2, 4);
	printf("scan_rowleft: %d\n", scan_rowleft);
//	insert_value_row(grid, scan_rowleft);
	print_array(grid, grid_size, grid_size);
	scan_colup = scan_for_n(view, 0, 4);
	printf("scan_colup: %d\n", scan_colup);	
	insert_value_col(grid, scan_colup);
	print_array(grid, grid_size, grid_size);

	return (1);
}
