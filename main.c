/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwijaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:23:46 by cwijaya           #+#    #+#             */
/*   Updated: 2023/08/05 15:23:47 by cwijaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	v = 0: colup; v = 1: coldown; v = 2: rowleft; v = 3: rowright  */
int	**create_array(int x, int y);
void	print_array(int **array, int x, int y);

int	parse_for_view(int argc, char **argv, int **view, int size)
{
	int	i;
	int	v;
	int	c;

	i = 0;
	v = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0' && v < size)
	{
		c = 0;
		while (c < size)
		{
			view[v][c] = argv[1][i] - '0';
			i += 2;
			c++;
		}
		v++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	**view;
	int	size;

	size = 4;
	view = create_array(size, size);
	parse_for_view(argc, argv, view, size);
	print_array(view, size, size);
}
