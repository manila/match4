#include "match4.h"

/* Create and return a multi-dimentional array */
static char **init_board(void);

char 	*ERR_INVALID_MOVE = "Invalid Move.\n\0";

Game	*create_game(void)
{
	Game *game = malloc(sizeof(game));

	game->board = init_board();	
	game->game_over = 0;

	return (game);
}

static char **init_board(void)
{
	int	i;
	char **board = (char **) malloc(7 * sizeof(char *));

	for (i = 0; i < 6; i++)
	{
		board[i] = (char *) malloc(6 * sizeof(char));	
	}

	return (board);
}

void	draw_board(char **board)
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

			if (board[row][col] != 0)
			{
				putchar(board[row][col]);
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

char	**get_current_board(Game *game)
{
	return(game->board);
}

int	get_top_of_stack(char **board,int col)
{
	int i;
	
	i = 0;

	while (i < 6 && board[i][col] && col < 7)
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

void	insert_onto_stack(char **board, int col, char piece)
{
	int top_of_row = get_top_of_stack(board, col);
	
	if (top_of_row < 0 || top_of_row > 5 || col < 0 || col > 6)
	{
		printf("\n%s", ERR_INVALID_MOVE);
		set_player_turn(get_next_player_turn());	
	}
	else
	{
		board[top_of_row][col] = piece; 
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
	return (0);	
}
