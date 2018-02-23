#include "match4.h"

unsigned char	PLAYER_TURN = 0;
char		PLAYER_PIECE[2] = {'X', 'O'};

unsigned char	get_player_turn(void)
{
	return (PLAYER_TURN);
}

unsigned char	set_player_turn(unsigned char player)
{
	if (player == 0 || player == 1)
	{
		PLAYER_TURN = player;
	}
	return (PLAYER_TURN);
}

unsigned char	get_next_player_turn()
{
	return ((~PLAYER_TURN) & 0x01);
}

char	get_player_piece(void)
{
	return (PLAYER_PIECE[PLAYER_TURN]);
}
