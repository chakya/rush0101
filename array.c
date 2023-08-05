/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwijaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:09:17 by cwijaya           #+#    #+#             */
/*   Updated: 2023/08/05 12:09:18 by cwijaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**create_array(int x, int y)
{
	int	**array;
	int	i;

	i = 0;
	array = (int **) malloc(x * sizeof(int *));
	while (i < x)
	{
		array[i] = (int *) malloc(y * sizeof(int));
		i++;
	}
	return (array);
}

void	free_array(int **array, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	len(const int *array)
{
	int	length;

	length = 0;
	while (array[length] != '\0')
	{
		length++;
	}
	return (length);
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
			write(1, array, len(array));
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
