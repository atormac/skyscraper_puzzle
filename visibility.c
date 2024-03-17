
int	visible_left(int **matrix, int size, int row)
{
	int		i;
	int		tallest;
	int		visible;

	i = 0;
	tallest = 0;
	visible = 0;
	while (i < size)
	{
		if (matrix[row][i] > tallest)
		{
			tallest = matrix[row][i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	visible_right(int **matrix, int size, int row)
{
	int		i;
	int		tallest;
	int		visible;

	i = size - 1;
	tallest = 0;
	visible = 0;
	while (i >= 0)
	{
		if (matrix[row][i] > tallest)
		{
			tallest = matrix[row][i];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	visible_up(int **matrix, int size, int col)
{
	int		i;
	int		tallest;
	int		visible;

	i = 0;
	tallest = 0;
	visible = 0;
	while (i < size)
	{
		if (matrix[i][col] > tallest)
		{
			tallest = matrix[i][col];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	visible_down(int **matrix, int size, int col)
{
	int		i;
	int		tallest;
	int		visible;

	i = size - 1;
	tallest = 0;
	visible = 0;
	while (i >= 0)
	{
		if (matrix[i][col] > tallest)
		{
			tallest = matrix[i][col];
			visible++;
		}
		i--;
	}
	return (visible);
}
