#include <stdio.h>
#include "player.h"
#include <stdlib.h>

void init_player(player *p)
{
    p->nbmove = 0;
    p->moves = (int *)malloc(sizeof(int) * 5);
    p->symbole="X";
}

void free_player(player *p)
{
    free(p->moves);
    p->moves = NULL;
    p->nbmove = 0;
}

void player_move(player *p, player *op)
{
    int move = 0;
    printf("Where do you want to play ? (Choose a number) ");
    scanf("%d",&move);
    int free = 0;
    while (!free)
    {
        free=1;
        for (int i = 0; i < p->nbmove; i++)
        {
            if (p->moves[i] == move)
            {
                free=0;
                break;
            }
        }
        for (int j=0; j<op->nbmove;j++){
            if (op->moves[j] == move)
            {
                free=0;
                break;
            }
        }
        if (!free){
            printf("Incorrect number please choose another ? (Choose a number) ");
            scanf("%d",&move);
        }
    }
    add_player_case(p,move);
}

void add_player_case(player* p, int move){
    p->moves[p->nbmove]=move;
    p->nbmove++;
}


int check_end_condition (player* a, player* b){
    // Check if either player has won
    if (has_won(a) || has_won(b)) {
        return 1;
    }
    // Check for draw (all 9 squares filled)
    if (a->nbmove + b->nbmove >= 9) {
        return 1;
    }
    return 0;
}

int has_won(player* p) {
    if (p->nbmove < 3){return 0;} // Need at least 3 moves to win
    
    // Check all winning combinations for 3x3 grid
    int winning_combinations[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // columns
        {1, 5, 9}, {3, 5, 7}             // diagonals
    };
    
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < p->nbmove; k++) {
                if (p->moves[k] == winning_combinations[i][j]) {
                    count++;
                    break;
                }
            }
        }
        if (count == 3){return 1;} // Found a winning combination
    }
    return 0;
}

