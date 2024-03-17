#include <stdlib.h>

void	my_memset(void *dest, int val, int size)
{
	unsigned char	*p;

	p = dest;
	while (size-- > 0)
	{
		*p++ = val;
	}
}

int	**matrix_allocate(int size)
{
	int		**array;
	int		i;

	i = 0;
	array = (int **)malloc(size * sizeof(int *));
	my_memset(array, 0, size * sizeof(int *));
	while (i < size)
	{
		array[i] = malloc(size * sizeof(int));
		my_memset(array[i], 0, size * sizeof(int));
		i++;
	}
	return (array);
}

void	matrix_free(int **matrix, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
