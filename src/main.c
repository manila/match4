#include "match4.h"

int 	GAME_OVER = 0;

int	main(int ac, char **av)
{
	int	input = 0;
	
	while (1)
	{
		draw_board();
		
		if (get_player_turn() == 1)
		{
			set_player_turn(0);
		}
		else
		{
			set_player_turn(1);
		}

		printf("\nPlayer %c's Turn: Enter row number to place piece: ", get_player_piece());
		scanf("%i", &input);
		insert_onto_stack(input - 1, get_player_piece());
	}
	return (0);
}
