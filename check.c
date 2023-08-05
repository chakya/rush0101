/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:52:05 by whuang            #+#    #+#             */
/*   Updated: 2023/08/05 18:21:44 by whuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_vis(int arr[4])
{
	int	i;
	int	len;
	int	vis;

	len = arr[0];
	vis = 1;
	i = 1;
	while (i < 4)
	{
		if (len < arr[i])
		{
			vis++;
			len = arr[i];
		}	
		i++;
	}
	return (vis);
}

void	get_array_vis(int vis[4][4], int ans[4][4])
{
	int	vis[4][4];

	vis[0][0] = get_vis(ans[0][0], ans[1][0], ans[2][0], ans[3][0]);
	vis[0][1] = get_vis(ans[0][1], ans[1][1], ans[2][1], ans[3][1]);
	vis[0][2] = get_vis(ans[0][2], ans[1][2], ans[2][2], ans[3][2]);
	vis[0][3] = get_vis(ans[0][3], ans[1][3], ans[2][3], ans[3][3]);
	vis[1][0] = get_vis(ans[3][0], ans[2][0], ans[1][0], ans[0][0]);
	vis[1][1] = get_vis(ans[3][1], ans[2][1], ans[1][1], ans[0][1]);
	vis[1][2] = get_vis(ans[3][2], ans[2][2], ans[1][2], ans[0][2]);
	vis[1][3] = get_vis(ans[3][3], ans[2][3], ans[1][3], ans[0][3]);
	vis[2][0] = get_vis(ans[0][0], ans[0][1], ans[0][2], ans[0][3]);
	vis[2][1] = get_vis(ans[1][0], ans[1][1], ans[1][2], ans[1][3]);
	vis[2][2] = get_vis(ans[2][0], ans[2][1], ans[2][2], ans[2][3]);
	vis[2][3] = get_vis(ans[3][0], ans[3][1], ans[3][2], ans[3][3]);
	vis[3][0] = get_vis(ans[0][3], ans[0][2], ans[0][1], ans[0][0]);
	vis[3][1] = get_vis(ans[1][3], ans[1][2], ans[1][1], ans[1][0]);
	vis[3][2] = get_vis(ans[2][3], ans[2][2], ans[2][1], ans[2][0]);
	vis[3][3] = get_vis(ans[3][3], ans[3][2], ans[3][1], ans[3][0]);
}

int	check_visibility(int clues[4][4], int ans[4][4])
{
	int	vis[4][4];
	int	i;
	int	j;

	get_array_vis(vis, ans);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (clues[i][j] != vis[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
/*
	// Check visibility from the top
	i = row - 1;
	while (i >= 0)
	{
		if (grid[i][col] > visible_top)
		{
			visible_top = grid[i][col];
			if (visible_top == SIZE)
				break ;
		}
		i--;
	}

<<<<<<< HEAD
// int	check_visibility(int clues[SIZE][4], int row, int col) {
int	check_visibility(int *clues[4], int **ans)
{
	return (0);
	check_visibility(clues, ans);
}

//     int visible_left = 0, visible_right = 0, visible_top = 0, visible_bottom = 0;
//     int i;

//     // Check visibility from the left
//     i = col - 1;
//     while (i >= 0) {
//         if (grid[row][i] > visible_left) {
//             visible_left = grid[row][i];
//             if (visible_left == SIZE)
//                 break;
//         }
//         i--;
//     }

//     // Check visibility from the right
//     i = col + 1;
//     while (i < SIZE) {
//         if (grid[row][i] > visible_right) {
//             visible_right = grid[row][i];
//             if (visible_right == SIZE)
//                 break;
//         }
//         i++;
//     }

//     // Check visibility from the top
//     i = row - 1;
//     while (i >= 0) {
//         if (grid[i][col] > visible_top) {
//             visible_top = grid[i][col];
//             if (visible_top == SIZE)
//                 break;
//         }
//         i--;
//     }

//     // Check visibility from the bottom
//     i = row + 1;
//     while (i < SIZE) {
//         if (grid[i][col] > visible_bottom) {
//             visible_bottom = grid[i][col];
//             if (visible_bottom == SIZE)
//                 break;
//         }
//         i++;
//     }

//     return (visible_left == clues[row][2]) && (visible_right == clues[row][3]) &&
//            (visible_top == clues[col][0]) && (visible_bottom == clues[col][1]);
// }
=======
	// Check visibility from the bottom
	i = row + 1;
	while (i < SIZE)
	{
		if (grid[i][col] > visible_bottom)
		{
			visible_bottom = grid[i][col];
			if (visible_bottom == SIZE)
				break ;
		}
		i++;
	}

	// Check visibility from the left
	i = col - 1;
	while (i >= 0)
	{
		if (grid[row][i] > visible_left)
		{
			visible_left = grid[row][i];
			if (visible_left == SIZE)
				break ;
		}
		i--;
	}

	// Check visibility from the right
	i = col + 1;
	while (i < SIZE)
	{
		if (grid[row][i] > visible_right)
		{
			visible_right = grid[row][i];
			if (visible_right == SIZE)
				break ;
		}
		i++;
	}

    return (visible_left == clues[row][2]) && (visible_right == clues[row][3]) &&
           (visible_top == clues[col][0]) && (visible_bottom == clues[col][1]);
}*/
>>>>>>> 079bbb5 (check.c)
