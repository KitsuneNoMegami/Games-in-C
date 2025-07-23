#include <stdlib.h>
#include <stdio.h>

#include "grid.h"
#include "player.h"

int main()
{
    player a, b;
    init_player(&a);
    init_player(&b);
    a.symbole="🐏";
    b.symbole="🪻";
    int end = 0;
    display_grid(&a, &b);
    while (!end)
    {
        for (int turn = 0; turn < 2; turn++)
        {
            turn == 0 ? player_move(&a, &b) : player_move(&b, &a);
            end = check_end_condition(&a, &b);
            display_grid(&a, &b);
            if (end)
            {
                turn == 0 ? printf("\nPlayer %s  won ! \n",a.symbole) : printf("\nPlayer %s  won ! \n",b.symbole);
                break;
            }
        }
    }

    free_player(&a);
    free_player(&b);
    return EXIT_SUCCESS;
}