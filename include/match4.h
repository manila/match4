#ifndef MATCH4_H
# define MATCH4_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct {
	char **board;
	int  game_over;
} Game;

Game		*create_game(void);
void		start_game(void);
void		draw_board(char **board);
void		insert_onto_stack(char **board, int col, char piece);
unsigned char	set_player_turn(unsigned char player);
unsigned char	get_player_turn(void);
unsigned char	get_next_player_turn(void);
char		get_player_piece(void);
char		**get_current_board(Game *game);
int		check_board_for_chains(char **board, char piece);

#endif
