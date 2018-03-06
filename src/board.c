#include "match4.h"

char 	*ERR_INVALID_MOVE = "Invalid Move.\n\0";
char	**GAME_BOARD; 

void	init_board(void)
{
	int	i;
	GAME_BOARD = (char **) malloc(7 * sizeof(char *));

	for (i = 0; i < 6; i++)
	{
		GAME_BOARD[i] = (char *) malloc(6 * sizeof(char));	
	}
}

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

char	**get_current_board(void)
{
	return(GAME_BOARD);
}

int	get_top_of_stack(int col)
{
	int i;
	
	i = 0;

	while (i < 6 && GAME_BOARD[i][col] && col < 7)
	{
		i++;
	}

	if (i < 6 && col < 7)
	{
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
		printf("\n%s", ERR_INVALID_MOVE);
		set_player_turn(get_next_player_turn());	
	}
	else
	{
		GAME_BOARD[top_of_row][col] = piece; 
	}
}

int	 check_board_for_chains(char **board, char piece)
{
	int row, col;
	int chain_count = 0;

	/* check rows */
	for (row = 0; row < 6; row++)
	{
		for (col = 0; col < 7; col++)
		{	
			if (board[row][col] == piece)
			{
				chain_count++;
				if (chain_count == 4)
				{
					return (1);
				}
			}
			else
			{
				chain_count = 0;
			}
		}	
	}
	chain_count = 0;
	/* check columns */
	for (col = 0; col < 7; col++)
	{
		for (row = 0; row < 6; row++)
		{
			if (board[row][col] == piece)
			{
				chain_count++;
				if (chain_count == 4)
				{
					return (1);
				}	
				
			}
			else
			{
				chain_count = 0;
			}
		}
	}
	chain_count = 0;
	/* check diagonal right to left on drawn board */
	
	for (col = 0, row = 0; col < 7 && row < 6; col++, row++)
	{
		if (board[row][col] == piece)
		{
			chain_count++;
			if (chain_count == 4)
			{
				return (1);
			}
		}
		else
		{
			chain_count = 0;
		}
	}
	return (0);
}

int	check_diag_chains()
{
	
}
