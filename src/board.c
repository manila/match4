#include "match4.h"

Game *init_game(void)
{
	Game *game = malloc(sizeof(Game));

	game->board_x = 0x8102040813333;
	game->board_o = 1;
	game->col_mask = 127;
	game->game_over = 0;
	
	return (game);
}

void	print_board(Game *game)
{
	int col, row, cols = 7, rows = 6;
	uint64_t full_board = (game->board_x | game->board_o);
	uint64_t bitmask = 1;
	
	for (col = 1; col < cols; col++)
	{
		for (row = 0; row < rows + 1; row++)
		{
			printf("%d", (int) (full_board & (bitmask << ((row * cols) + (cols - 1) - (col)))) > 0 ? 1 : 0);  
		}
		putchar('\n');
	}
}

void	insert_onto_stack(Game *game, int col)
{
	
	game->board_x |= ((game->board_x<<1 | game->board_x) & (game->col_mask<<(col*7)));
} 

int	 check_board_for_chains(void)
{
	return (0);
}

int	check_diag_chains(void)
{
	return (0);	
}
