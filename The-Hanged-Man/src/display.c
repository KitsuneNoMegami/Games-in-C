#include "display.h"
#include <stdio.h>

void display_man( int score){
    switch(score){
        case 1:
            printf("\n%s",BASE);
            break;
        case 2:
            printf("\n%s",WOOD);
            break;
        case 3:
            printf("\n%s", HEAD);
            break;
        case 4:
            printf("\n%s", BODY);
            break;
        case 5:
            printf("\n%s",ARM1);
            break;            
        case 6:
            printf("\n%s",ARMS);
            break;
        case 7:
            printf("\n%s",LEG1);
            break;
        case 8:
            printf("\n%s",DEAD);
            break;
        default:
            printf("\nAAAAAAAAAAAAAA ");
    }
}