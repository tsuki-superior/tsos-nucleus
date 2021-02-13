//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_BOOT_DRIVER__
#define __TSOS_NUCLEUS_BOOT_DRIVER__

#include "../../core/driver.hpp"
#include "../../core/module.hpp"
#include "../../core/types.hpp"
#include "../../core/core.hpp"

class Boot_driver : public Driver
{
public:
    // Constructor
    Boot_driver(void);

    // Destructor
    ~Boot_driver();

    // Reboot the system
    virtual void reboot(void) = 0;

    // Shutdown the system
    virtual void shutdown(void) = 0;
};

#endif
