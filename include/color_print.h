#ifndef COLOR_PRINT_H_
#define COLOR_PRINT_H_

#include <iostream>

enum COLOR_LETTERS_T
{
    BLACK      = 30,
    RED        = 31,
    GREEN      = 32,
    YELLOW     = 33,
    BLUE       = 34,
    PURPLE     = 35,
    WHITE_BLUE = 36,
    WHITE      = 37
};

enum COLOR_BACKGROUND_T
{
    BLACK_B      = 40,
    RED_B        = 41,
    GREEN_B      = 42,
    YELLOW_B     = 43,
    BLUE_B       = 44,
    PURPLE_B     = 45,
    WHITE_BLUE_B = 46,
    WHITE_B      = 47
};

enum WORD_STYLE_T
{
    NORMAL     = 0, 
    BOLD       = 1,
    UNDERLINED = 4,
    BLINK      = 5,
    INVERSION  = 7,
    INVISIBLE  = 8
};

#ifdef DARK_THEME_ 
    const unsigned int NORMAL_LETTER_COLOR = (unsigned int) BLACK;
#else  //LIGHT_THEME
    const unsigned int NORMAL_LETTER_COLOR = (unsigned int) WHITE;
#endif

void set_color (COLOR_LETTERS_T color_letter, WORD_STYLE_T word_style, COLOR_BACKGROUND_T color_background);
void set_color (COLOR_LETTERS_T color_letter, WORD_STYLE_T word_style);
void set_color (COLOR_LETTERS_T color_letter);
void set_color ();

inline void print_line ()
{
    set_color (WHITE, BOLD);

    std::cout << "\n\n//------------------------------------------------------------------------------------\n\n";

    set_color ();
}

#endif