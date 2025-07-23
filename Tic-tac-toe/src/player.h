#pragma once

typedef struct player{
    int* moves; // cases played
    int nbmove; //The number of move played
    char* symbole;
} player;

void init_player(player* p);
void free_player(player* p);
void player_move(player* p, player* op);
void add_player_case(player* p, int move);
int check_end_condition(player* a, player* b);
int has_won(player* p);