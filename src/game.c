#include "match4.h"

int	GAME_OVER = 0;

void	start_game()
{
	int player_input = 0;
	
	init_board();

	draw_board();

	while (!GAME_OVER)
	{
		set_player_turn(get_next_player_turn());	
		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%i", &player_input);
		insert_onto_stack(player_input - 1, get_player_piece());
		draw_board();
		if (check_board_for_chains(get_current_board(), get_player_piece()) == 1)
		{
			printf("\nGAME OVER: %c's Won!\n", get_player_piece());
			GAME_OVER = 1;
		}
	}
}

void	end_game(void)
{
	GAME_OVER = 1;
}
