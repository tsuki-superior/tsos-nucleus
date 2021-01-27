//By Tsuki Superior
#include "./sfs.hpp"

SFS_driver::SFS_driver(void)
{
    name = "Simple File System";
}

bool SFS_driver::detectsystem(void)
{
    uint8_t diskfsname[] = tsos.disk.getbytes(0x4f, 0x03);
    char *fsname = "SFS";
    for (uint8_t x = 0; x < 0x3; x++)
    {
        if ((uint8_t)fsname[x] != diskfsname[x])
        {
            return false;
        }
    }
    return true;
}

char ** SFS_driver::readdir(char *path) {
}

void SFS_driver::rename(char *path, char *newPath)
{
}

Tsos_file SFS_driver::open(char *path)
{
}

void SFS_driver::close(Tsos_file file)
{
}

char *SFS_driver::read(Tsos_file file)
{
}

void SFS_driver::write(Tsos_file file, char *data)
{
}

char *SFS_driver::readfile(char *path)
{
}

void SFS_driver::writefile(char *path, char *data)
{
}

void SFS_driver::appendfile(char *path, char *data)
{
}

bool SFS_driver::exists(char *path)
{
}