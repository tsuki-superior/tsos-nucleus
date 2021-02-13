//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_SOUND_DRIVER__
#define __TSOS_NUCLEUS_SOUND_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

class Sound_driver : public Driver
{
public:
  // Constructor
  Sound_driver(void);

  // Play a tone
  virtual void playtone(Tone tone) = 0;
};

#endif
