#include <stdio.h>
#include <stdlib.h>

#include "player.h"

int display_grid(player *x, player *o)
{
    printf("\n\n\n\n");
    int played = 0; // false
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            for (int cross = 0; cross < x->nbmove; cross++)
            {
                if (i * 3 + j == x->moves[cross])
                {
                    printf("\t%s\t", x->symbole);
                    played = 1;
                }
            }
            for (int circle = 0; circle < o->nbmove; circle++)
            {
                if (i * 3 + j == o->moves[circle])
                {
                    printf("\t%s\t", o->symbole);
                    played = 1;
                }
            }
            if (!played)
            {
                printf("\t%d\t", i * 3 + j);
            }
            played=0;
            if (j!=3){printf("|");}
        }
        printf("\n");
        if(i!=2){printf("\n-------------------------------------------------\n\n");}
    }
    printf("\n");
    return EXIT_SUCCESS;
}
