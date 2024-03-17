#include <unistd.h>

void	print_str(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_matrix(int **array, int size)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (x < size)
	{
		while (y < size)
		{
			print_char(array[x][y] + '0');
			if (size - 1 != y)
				print_char(' ');
			y++;
		}
		y = 0;
		print_char('\n');
		x++;
	}
}
