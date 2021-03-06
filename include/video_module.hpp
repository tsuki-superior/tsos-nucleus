//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_VIDEO_MODULE__
#define __TSOS_NUCLEUS_VIDEO_MODULE__

#include "driver.hpp"
#include "module.hpp"
#include "types.hpp"
#include "video_driver.hpp"
#include "video_color.hpp"
#include "video_font.hpp"
#include "video_modes.hpp"
#include "current_config.hpp"

// The main class controlling video
class Video : public Module<Video_driver>
{
public:
  // Constructor
  Video(void);

  // Destructor
  ~Video();

  // Initialize the video system
  void reset(void);

  // Put a character
  void putchar(uint16_t posx, uint16_t posy, char c);

  // Put a string on the screen
  void putstring(uint16_t posx, uint16_t posy, char *str);

  // Get the width of the screen
  uint16_t getscreenwidth(void);

  // Get the current height of the screen
  uint16_t getscreenheight(void);

  // Set the font to be used in the screen
  void setfont(Font f);

  // Clear the screen
  void clear(void);

  // Set text background color
  void settextbackgroundcolor(uint8_t red, uint8_t green, uint8_t blue);

  // Set text foreground color
  void settextforegroundcolor(uint8_t red, uint8_t green, uint8_t blue);

  uint16_t scroll;

private:
  // Current font
  Font font;

  // The current text background color
  Color backgroundcolor;

  // The current text foreground color
  Color foregroundcolor;
};

#endif
