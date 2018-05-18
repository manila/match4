#ifndef MATCH4_H
# define MATCH4_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>


typedef struct {
	char 	*player_piece;
	int	 board_count;
	uint64_t board[2];
	uint64_t bottom_mask;
	uint64_t col_mask;
	int	 game_over;
} Game;

Game		*init_game(void);
void		start_game(void);
void		print_board(Game *game);
void		insert_onto_stack(Game *game, int col, int player);
unsigned char	set_player_turn(unsigned char player);
unsigned char	get_player_turn(void);
unsigned char	get_next_player_turn(void);
char		get_player_piece(void);
char		**get_current_board(Game *game);
uint64_t	check_board_for_win(Game *game, int player);
void		print_board_debug(uint64_t board, char *board_type);

#endif
