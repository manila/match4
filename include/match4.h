#ifndef MATCH4_H
# define MATCH4_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void		start_game(void);
void		end_game(void);
void		draw_board(void);
void		insert_onto_stack(int col, char piece);
void		init_board(void);
unsigned char	set_player_turn(unsigned char player);
unsigned char	get_player_turn(void);
unsigned char	get_next_player_turn(void);
char		get_player_piece(void);
char		**get_current_board(void);
int		check_board_for_chains(char **board, char piece);

#endif
