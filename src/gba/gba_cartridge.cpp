//By Tsuki Superior
#include "gba_cartridge.hpp"

GBA_CARTRIDGE_driver::GBA_CARTRIDGE_driver(void)
{
    name = "Gameboy Advanced Cartridge";
}

GBA_CARTRIDGE_driver::~GBA_CARTRIDGE_driver()
{
}

bool GBA_CARTRIDGE_driver::detectsystem()
{
    return true;
}

void GBA_CARTRIDGE_driver::reset(void)
{
}

void GBA_CARTRIDGE_driver::getbytes(uint8_t *buffer, uint16_t offset, uint8_t len)
{
}

uint16_t GBA_CARTRIDGE_driver::getsectorsize(void)
{
    return 0;
}
