#pragma once

extern const char* dico[];
enum result{FALSE,TRUE};
void choose_word();
char get_user_input ();
void compare_word(int* point,char* input);
int print_letter();