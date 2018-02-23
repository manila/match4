#ifndef MATCH4_H
# define MATCH4_H

# include <unistd.h>
# include <stdio.h>

void		draw_board(void);
void		insert_onto_stack(int col, char piece);
unsigned char	set_player_turn(unsigned char player);
unsigned char	get_player_turn(void);
unsigned char	get_next_player_turn(void);
char		get_player_piece(void);

#endif
