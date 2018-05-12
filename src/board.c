#include "match4.h"

void print_row(Game *game, int row);

Game *init_game(void)
{
	Game *game = malloc(sizeof(Game));

	game->board_count = 2;
	game->board[0] = 0x40810204081;
	game->board[1] = 0x40810204081;
	game->col_mask = 127;
	game->game_over = 0;
	
	return (game);
}

uint64_t get_full_board(Game *game)
{
	return (game->board[0] | game->board[1]);		
}

void	print_board(Game *game)
{
	int col, row, cols = 7, rows = 6;
	uint64_t fb = get_full_board(game);
	uint64_t bitmask = 1;
	
	for (col = 1; col < cols; col++)
	{
		for (row = 0; row < rows + 1; row++)
		{
			printf("%d", (int) ((game->board[1] & (bitmask << ((row * cols) + (cols - 1) - (col)))) > 0 ? 1 : 0));  
		}
		putchar('\n');
	}

	row = 6;

	while (row)
	{
		print_row(game, row);
		row--;
	}
}

void	print_row(Game *game, int row)
{
	uint64_t bitmask = (1 << row);
	
	while (bitmask)
	{
		if ((game->board[0] & bitmask) > 0)
			putchar('x');
		else if ((game->board[1] & bitmask) > 0)
			putchar('o');
		else
			putchar('.');

		bitmask <<= 7;
	}	
	putchar('\n');
}

int	is_valid_move(Game *game, int col)
{
	return (get_full_board(game) ^ (game->col_mask << (col * 7)));
}

void	insert_onto_stack(Game *game, int col, int player)
{
	uint64_t fb = get_full_board(game);

	printf("Player Number: %d\n", player);	

	game->board[player] |= ((~fb) & (game->col_mask << (col * 7))) & (fb << 1);
} 

int	 check_board_for_chains(void)
{
	return (0);
}

int	check_diag_chains(void)
{
	return (0);	
}
