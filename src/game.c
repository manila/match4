#include "match4.h"

int	GAME_OVER = 0;

void	start_game()
{
	int player_input = 0;

	while (!GAME_OVER)
	{
		draw_board();
		set_player_turn(get_next_player_turn());	
		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%i", &player_input);
		insert_onto_stack(player_input - 1, get_player_piece());
		end_game();
	}
}

void	end_game(void)
{
	GAME_OVER = 1;
}
