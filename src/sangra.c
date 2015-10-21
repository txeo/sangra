#include "includes/sangra.h"
  // ---- //
 // VARS //  
// ---- //

static Window *window;
TextLayer *yoga_tea_layer;
TextLayer *time_layer;
StatusBarLayer *status_bar;

  // --------- //
 // FUNCTIONS //  
// --------- //

// 0. Clicks Config (Only for apps)
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Select");
}
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Up");
}
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Down");
}
static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

// 1. Time Subscriber & Tick Handlers (TIME!!!)  
static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffer
  static char buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M:%S", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M:%S", tick_time);
  }
  
  time_layer = text_layer_create(GRect(0, 12, 144, 50));
  text_layer_set_background_color(time_layer, GColorBlack);
  text_layer_set_text_color(time_layer, GColorWhite);
  text_layer_set_text(time_layer, "00:00:00");

  // Improve the layout to be more like a watchface
  text_layer_set_font(time_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
  text_layer_set_text_alignment(time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(time_layer));
  // Display this time on the TextLayer
 text_layer_set_text(time_layer, buffer);
 
}
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
 update_time();
}

// 1. Window Functions
static void main_window_unload(Window *window) {

}
static void main_window_load(Window *window) {

}
static void initialize_main_window () {
  
  // Create main Window element and assign to pointer
  window = window_create();

  // Configure Clics (Only for apps)
  window_set_click_config_provider(window, click_config_provider);

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Pa la barra de herramientas!
  window_set_background_color(window, GColorBlack);

	  // Show the Window on the watch, with animated=true
	// Push the window
	window_stack_push(window, true);

  // Make sure the time is displayed from the start
  update_time();
}

// 2. Text Functions
static void showText (char *text, char *font, GColor front_color, GColor background_color, int vertical_align, TextLayer *text_layer) {
  
  // Init init vars
  int y = 0;
  
  // Choosing vertical alignment
  switch (vertical_align) {
    case TOP_ALIGN: y = 0; break;    // TOP
    case MIDDLE_ALIGN: y = 60; break;   // CENTER
    case BOTTOM_ALIGN: y = 120; break;  // BOTTOM
    default: y=0;
  }
    
  // Creating text layer
	text_layer = text_layer_create(GRect(0, y, 144, 154));

	// Set the text, font, and text alignment
	text_layer_set_text(text_layer, text);
	text_layer_set_font(text_layer, fonts_get_system_font(font));
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(text_layer, front_color);
  text_layer_set_background_color(text_layer, background_color);
  
  
  // Add the text layer to the window
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
}
 
 
 static void init() {
 
  // Initialize Window
  initialize_main_window();
  
  
 //showText("Arriba", FONT_KEY_GOTHIC_18_BOLD, GColorBlack,GColorWhite,TOP_ALIGN,time_layer);
 
 char * yoga_tea_phrase = yoga_tea_phrases[( rand() % N_ELEMENTS(yoga_tea_phrases) )];
 
 if (strlen(yoga_tea_phrase) > 48) {
   showText(yoga_tea_phrase, FONT_KEY_GOTHIC_24_BOLD, GColorBlack,GColorWhite,MIDDLE_ALIGN,yoga_tea_layer);
 } else {
   showText(yoga_tea_phrase, FONT_KEY_GOTHIC_28, GColorClear,GColorWhite,MIDDLE_ALIGN,yoga_tea_layer);
 }
 
 /*if (strlen(yoga_tea_phrase) < 25) {
   showText(yoga_tea_phrase, FONT_KEY_GOTHIC_, GColorBlack,GColorWhite,MIDDLE_ALIGN,yoga_tea_layer);
 } */
 
 
 
 tick_timer_service_subscribe(SECOND_UNIT, tick_handler);

	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}
static void deinit() {
  
  // Destroy text layers
  text_layer_destroy (yoga_tea_layer);
  text_layer_destroy (time_layer);
  
  // Destroy Window
   window_destroy(window);
}
int main(void) {
  init();
  app_event_loop();
  deinit();
}

