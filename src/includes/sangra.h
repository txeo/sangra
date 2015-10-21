#pragma once

#include <pebble.h>

#define N_ELEMENTS(array) (sizeof(array)/sizeof((array)[0])) 

// Primero ponemos aquí el objeto del programa:
// LAS YOGA TEA frases según me las voy encontrando.
char *yoga_tea_phrases[] = {
  "An attitude of gratitude brings opportunities", 
  "A relaxed mind is a creative mind", 
  "Soul never stops or forget", 
  "Now is the time -- The time is now", 
  "Give up your need for control", 
  "The greatest education man has to learn is the science of self",
  "Love took slow steps to your heart", 
  "The purpose of life is to enjoy every moment of life", 
  "One does not make friends. One recognizes them", 
  "Treat all things is if they were loaned", 
  "Empty yourself and let the universe fill you", 
  "How quickly do you what your soul wants?", 
  "When ego is lost, then universality exists", 
  "The moment you value yourself, the whole world values you", 
  "Protect yourself from your own thoughts",
  "Intelligence and intuition are two friends",
  "Compassion has no limit. Kindness has no enemy",
  "Every smile is a direct achievement",
  "Develop your power of listening",
  "Sing from your heart",
  "Where ther is love, there is no question",
  "Let your heart guide you",
  "Where there is love, there is no question",
  "Let your manners speak of you",
  "Life is a flow of love; your participation is requested",
  "Love is an infinite power"
};


  // ----------------- //
 // VERTICAL ALIGMENT //  
// ----------------- //

#define TOP_ALIGN 0
#define MIDDLE_ALIGN 1
#define BOTTOM_ALIGN 2

  // ------ //
 // COLORS //  
// ------ //

#define COLOUR_HEADER GColorRed
#define COLOUR_HEADER_TEXT GColorWhite
#define COLOUR_WINDOW GColorWhite
#define COLOUR_MENU_BACKGROUND GColorWhite
#define COLOUR_MENU_FOREGROUND GColorBlack
#define COLOUR_MENU_HIGHLIGHT_BACKGROUND GColorFromHEX(0xE31837)
#define COLOUR_MENU_HIGHLIGHT_FOREGROUND GColorWhite

#define COLOUR_BULLET GColorFromHEX(0xE31837)
#define COLOUR_LIMITED GColorChromeYellow
#define COLOUR_LOCAL GColorDarkGray
#define COLOUR_SHUTTLE GColorWhite

#define COLOUR_ROUTE_OUTLINE GColorClear
#define COLOUR_ROUTE_FILLED GColorDarkGray
#define COLOUR_ROUTE_EMPTY GColorLightGray


 // ------ //
 // FONTS //  
// ----- //


/*#define FONT_KEY_GOTHIC_14 
FONT_KEY_GOTHIC_14_BOLD FONT_KEY_GOTHIC_14 FONT_KEY_GOTHIC_14_BOLD_1
#define FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_GOTHIC_24 FONT_KEY_GOTHIC_24_BOLD FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_GOTHIC_28 FONT_KEY_GOTHIC_28_BOLD FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_30_BLACK FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_42_LIGHT FONT_KEY_BITHAM_42_BOLD FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_34_MEDIUM_NUMBERS FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_42_MEDIUM_NUMBERS FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_18_LIGHT_SUBSET FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_BITHAM_34_LIGHT_SUBSET FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD_1
#define FONT_KEY_ROBOTO_CONDENSED_21 FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD
#define FONT_KEY_ROBOTO_BOLD_SUBSET_49 FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD
#define FONT_KEY_DROID_SERIF_28_BOLD FONT_KEY_GOTHIC_18 FONT_KEY_GOTHIC_18_BOLD
*/