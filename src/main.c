#include "match4.h"

int 	GAME_OVER = 0;
int	PLAYER_TURN = 0;
char	PLAYER_PIECE[2] = {'X', 'O'};

int	main(int ac, char **av)
{
	int	input = 0;
	
	while (1)
	{
		draw_board();
		printf("\nPlayer %c's Turn: Enter row number to place piece: %i ", PLAYER_PIECE[PLAYER_TURN], PLAYER_TURN);
		scanf("%i", &input);
		insert_onto_stack(input - 1, PLAYER_PIECE[PLAYER_TURN]);
		
		if (PLAYER_TURN == 1)
		{
			PLAYER_TURN = 0;
		}
		else
		{
			PLAYER_TURN = 1;
		}
	}
	return (0);
}
