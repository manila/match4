#include "match4.h"

char *ERR_INVALID_MOVE = "Invalid Move.\n";

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
	int row, col, i;

	col = 0;
	row = 6;
	i = 0;
	putchar('\n');
	putchar('|');
	while (i < 7)
	{
		putchar(49 + i);
		putchar('|');
		i++;
	}
	putchar('\n');
	while (row > 0)
	{
		row--;
		putchar('|');
		while (col < 7) 
		{

			/* printf("row: %i, col: %i, int: %i", row, col, GAME_BOARD[row][col]); */
			if (GAME_BOARD[row][col] != 0)
			{
				putchar(GAME_BOARD[row][col]);
			}
			else
			{
				putchar(' ');
			}
			putchar('|');
			col++;
		}
		putchar('\n');
		col = 0;
	}
}

int	get_top_of_stack(int col)
{
	int i;
	
	i = 0;

	if (i < 6 && col < 7)
	{
		while (GAME_BOARD[i][col] && i < 6 && col < 7)
		{
			i++;
		}
	
		return (i);
	}
	else
	{
		return (-1);
	}
}

void	insert_onto_stack(int col, char piece)
{
	int top_of_row = get_top_of_stack(col);
	
	if (top_of_row < 0 || top_of_row > 5 || col < 0 || col > 6)
	{
		printf(ERR_INVALID_MOVE);
		set_player_turn(get_next_player_turn());	
	}
	else
	{
		GAME_BOARD[top_of_row][col] = piece; 
	}
}
