#include "match4.h"

int	GAME_OVER = 0;

void	start_game()
{
	Game *game = init_game();

	char player_input[256];
	
	print_board(game);

	while (!game->game_over)
	{
		set_player_turn(get_next_player_turn());	
		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%255s", player_input);
		insert_onto_stack(game, (atoi(player_input) - 1), get_player_turn());
		print_board(game);
		if (check_board_for_win(game, get_player_turn()))
			game->game_over = 1;
	}
}
