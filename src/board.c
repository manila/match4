#include "match4.h"

char GAME_BOARD[6][7] = {
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			};

void	draw_board(void)
{
	int x, y, i;

	x = 0;
	y = 6;
	i = 0;
	putchar('|');
	while (i < 7)
	{
		putchar(49 + i);
		putchar('|');
		i++;
	}
	putchar('\n');
	putchar(x + 48);
	putchar(y + 48);
	while (y > 0)
	{
		y--;
		putchar('|');
		while (x < 7) 
		{
			if (GAME_BOARD[x][y] == 0)
			{
				putchar(' ');
			}
			else
			{
				putchar(GAME_BOARD[x][y]);
			}
			putchar('|');
			x++;
		}
		putchar('\n');
		x = 0;
	}
}

int	get_top_of_stack(int col)
{
	int i;
	
	i = 0;
	while (GAME_BOARD[i][col] && i < 6 && col < 7)
	{
		i++;
	}
	
	return (i);
}

void	insert_onto_stack(int col, char piece)
{
	GAME_BOARD[get_top_of_stack(col)][col] = piece; 
}
