#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "game.h"

int main(){
    choose_word();
    int point=0;
    //printf("%s\n", dico[1]);
    while (point < 8 && !print_letter()){
    char letter=get_user_input();
    //printf("%c\n",letter);
    compare_word(&point,&letter);
    //printf("%d",point);
    display_man(point);
    }
    return EXIT_SUCCESS;
}