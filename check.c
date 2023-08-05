/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwijaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:50:04 by cwijaya           #+#    #+#             */
/*   Updated: 2023/08/05 13:50:05 by cwijaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Check if 'val' is not present in the row and column
int	is_valid(int **grid, int row, int col, int val)
{
	int	i;

	i = 0;
	while (grid[row][i] && grid[i][col])
	{
		if (grid[row][i] == val || grid[i][col] == val) {
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_visibility(int clues[SIZE][4], int row, int col, int val) {
    int visible_left = 0, visible_right = 0, visible_top = 0, visible_bottom = 0;
    int i;

    // Check visibility from the left
    i = col - 1;
    while (i >= 0) {
        if (grid[row][i] > visible_left) {
            visible_left = grid[row][i];
            if (visible_left == SIZE)
                break;
        }
        i--;
    }

    // Check visibility from the right
    i = col + 1;
    while (i < SIZE) {
        if (grid[row][i] > visible_right) {
            visible_right = grid[row][i];
            if (visible_right == SIZE)
                break;
        }
        i++;
    }

    // Check visibility from the top
    i = row - 1;
    while (i >= 0) {
        if (grid[i][col] > visible_top) {
            visible_top = grid[i][col];
            if (visible_top == SIZE)
                break;
        }
        i--;
    }

    // Check visibility from the bottom
    i = row + 1;
    while (i < SIZE) {
        if (grid[i][col] > visible_bottom) {
            visible_bottom = grid[i][col];
            if (visible_bottom == SIZE)
                break;
        }
        i++;
    }

    return (visible_left == clues[row][2]) && (visible_right == clues[row][3]) &&
           (visible_top == clues[col][0]) && (visible_bottom == clues[col][1]);
}
