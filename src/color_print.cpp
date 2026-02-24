#include <iostream>

#include "color_print.h"

//\x1b[<STYLE>;<BACKGROUND>;<LETTERS>m


void set_color (COLOR_LETTERS_T color_letter, WORD_STYLE_T word_style, COLOR_BACKGROUND_T color_background)
{
    std::cout << "\x1b[" << (unsigned int) word_style << ";" << (unsigned int) color_background << ";" << (unsigned int) color_letter << "m";
}

void set_color (COLOR_LETTERS_T color_letter, WORD_STYLE_T word_style)
{
    std::cout << "\x1b[" << (unsigned int) word_style << ";" << (unsigned int) color_letter << "m";
}

void set_color (COLOR_LETTERS_T color_letter)
{
    std::cout << "\x1b[" << (unsigned int) color_letter << "m";
}

void set_color ()
{
    std::cout << "\x1b[" << NORMAL_LETTER_COLOR << ";" << (unsigned int) NORMAL << "m";
}