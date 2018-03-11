#include "match4.h"

int	GAME_OVER = 0;

void	start_game()
{
	Game *game = create_game();

	char player_input[256];
	
	draw_board(game->board);

	while (!game->game_over)
	{
		set_player_turn(get_next_player_turn());	
		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%255s", player_input);
		insert_onto_stack(game->board, player_input[0] - 49, get_player_piece());
		draw_board(game->board);
		if (check_board_for_chains(get_current_board(game), get_player_piece()) == 1)
		{
			printf("\nGAME OVER: %c's Won!\n", get_player_piece());
			game->game_over = 1;
		}
	}
}
