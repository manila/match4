#include "match4.h"

int 	GAME_OVER = 0;
char	PLAYER_PIECE[2] = {'X', 'O'};

int	main(int ac, char **av)
{
	int 	player_turn = 0;
	int	input = 0;
	
	while (1)
	{
		draw_board();

		input = getchar();		

		insert_onto_stack(input - 49, PLAYER_PIECE[player_turn]);

		if (player_turn == 0)
		{
			player_turn = 1;
		}
		else
		{
			player_turn = 0;
		}
	}
	return (0);
}
