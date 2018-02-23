#include "match4.h"

void	start_game()
{
	int player_input;

	while (1)
	{
		draw_board();
		set_player_turn(get_next_player_turn());	
		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%i", &player_input);
		insert_onto_stack(player_input - 1, get_player_piece());
	}
}
