#include <unistd.h>

int		solve_backtrack(void);
int		**matrix_allocate(int size);
void	matrix_free(int **matrix, int size);

void	print_matrix(int **array, int size);
void	print_str(char *str);
void	print_char(char c);

int		parse_arguments(char *args, int **g_clues);
int		validate_args(char *args);

int		visible_left(int **matrix, int size, int row);
int		visible_right(int **matrix, int size, int row);
int		visible_up(int **matrix, int size, int col);
int		visible_down(int **matrix, int size, int col);

int	**g_grid;
int	**g_clues;
int	g_grid_siz;

int	is_valid_visibility(int row, int col)
{
	if (visible_up(g_grid, g_grid_siz, col) > g_clues[0][col])
		return (0);
	if (visible_left(g_grid, g_grid_siz, col) > g_clues[2][col])
		return (0);
	if (col == g_grid_siz - 1)
	{
		if (visible_right(g_grid, g_grid_siz, row) != g_clues[3][row])
			return (0);
		if (visible_left(g_grid, g_grid_siz, row) != g_clues[2][row])
			return (0);
	}
	else if (row == g_grid_siz - 1)
	{
		if (visible_down(g_grid, g_grid_siz, col) != g_clues[1][col])
			return (0);
		if (visible_up(g_grid, g_grid_siz, col) != g_clues[0][col])
			return (0);
	}
	return (1);
}

int	is_valid_solution(int row, int col, int num)
{
	int		i;
	int		original;

	i = 0;
	while (i < g_grid_siz)
	{
		if (g_grid[row][i] == num || g_grid[i][col] == num)
			return (0);
		i++;
	}
	original = g_grid[row][col];
	g_grid[row][col] = num;
	if (!is_valid_visibility(row, col))
	{
		g_grid[row][col] = original;
		return (0);
	}
	g_grid[row][col] = original;
	return (1);
}

int	find_solution(int row, int col)
{
	int		num;
	int		original_val;

	num = 1;
	while (num <= g_grid_siz)
	{
		if (is_valid_solution(row, col, num))
		{
			original_val = g_grid[row][col];
			g_grid[row][col] = num;
			if (solve_backtrack())
				return (1);
			g_grid[row][col] = original_val;
		}
		else
		{
			g_grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve_backtrack(void)
{
	int		row;
	int		col;	

	row = 0;
	col = 0;
	while (row < g_grid_siz)
	{
		col = 0;
		while (col < g_grid_siz)
		{
			if (g_grid[row][col] == 0)
			{
				if (find_solution(row, col))
					return (1);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !validate_args(argv[1]))
	{
		print_str("Error\n");
		return (0);
	}
	g_grid_siz = 4;
	g_grid = matrix_allocate(g_grid_siz);
	g_clues = matrix_allocate(g_grid_siz);
	if (!parse_arguments(argv[1], g_clues))
	{
		print_str("Error\n");
		return (0);
	}
	if (solve_backtrack())
		print_matrix(g_grid, g_grid_siz);
	else
		print_str("Error\n");
	matrix_free(g_grid, g_grid_siz);
	matrix_free(g_clues, g_grid_siz);
	return (0);
}
