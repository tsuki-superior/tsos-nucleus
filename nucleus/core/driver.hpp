//By Tsuki Superior
#ifndef __TSOS_DRIVER_CORE__
#define __TSOS_DRIVER_CORE__

// The class for drivers
class Driver
{
public:
  // Constructor
  Driver(void);

  // Destructor
  ~Driver(void);

  // A function called to determine if a driver should be used.
  virtual bool detectsystem(void) = 0;

  // The name of said module
  char *name;
};

#endif
