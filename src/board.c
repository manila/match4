#include "match4.h"

void print_row(Game *game, int row);

Game *init_game(void)
{
	Game *game = malloc(sizeof(Game));

	game->board_count = 2;
	game->board[0] = 0x0101010101010101LL;
	game->board[1] = 0x0101010101010101LL;
	game->col_mask = 255;
	game->bottom_mask = 0x0101010101010101LL;
	game->game_over = 0;
	
	return (game);
}

uint64_t get_full_board(Game *game)
{
	return (game->board[0] | game->board[1]);		
}

void	print_board_debug(uint64_t board, char *board_type)
{
	int col, row, cols = 8, rows = 7;
	uint64_t fb = board;
	uint64_t bitmask = 1;

	printf("---start %s ---\n", board_type);
	
	for (col = 1; col < cols; col++)
	{
		for (row = 0; row < rows + 1; row++)
		{
			printf("%d", (int) ((fb & (bitmask << ((row * cols) + (cols - 1) - (col)))) > 0 ? 1 : 0));  
		}
		putchar('\n');
	}

	puts("---end---");
}

void	print_board(Game *game)
{
	int row = 6;

	while (row > -1)
	{
		print_row(game, row);
		row--;
	}
}

void	print_row(Game *game, int row)
{
	int cols = 7;
	uint64_t bitmask = (1 << row);
	
	while (bitmask && cols)
	{
		if ((game->board[0] & bitmask) > 0)
			putchar('x');
		else if ((game->board[1] & bitmask) > 0)
			putchar('o');
		else
			putchar('.');
		bitmask <<= 8;
		cols--;
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

	game->board[player] |= (~fb) & ((game->col_mask << (col * 8))) & (fb << 1);
	
	print_board_debug(game->board[0], "Player 1");
	print_board_debug(game->board[1], "Player 2");
} 

uint64_t check_board_for_win(Game *game, int player)
{
	uint64_t bb = game->board[player];
	
	bb &= ~game->bottom_mask;

	return ((((bb << 1) & (bb << 2)  & (bb << 3))  |
		 ((bb << 8) & (bb << 16) & (bb << 24)) |
                 ((bb << 9) & (bb << 18) & (bb << 27)) |
                 ((bb << 7) & (bb << 14) & (bb << 21))) & bb);
}
