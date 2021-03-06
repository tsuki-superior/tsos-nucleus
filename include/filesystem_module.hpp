// By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM_MODULE__
#define __TSOS_NUCLEUS_FILESYSTEM_MODULE__

#include "module.hpp"
#include "types.hpp"
#include "filesystem_driver.hpp"
#include "filesystem_file.hpp"
#include "filesystem_permissions.hpp"
#include "current_config.hpp"

extern "C" int strcmp(const char *p1, const char *p2);

//The main class controlling the filesystem
class Filesystem : public Module<Filesystem_driver>
{
public:
  //Constructor
  Filesystem(void);

  //Destructor
  ~Filesystem();

  //Read the contents of a directory
  char **readdir(char *path);

  //Rename a file or folder
  void rename(char *path, char *newPath);

  //Open a file
  File open(char *path);

  //Close a file
  void close(File file);

  //Read from a file
  uint8_t *read(File file, uint32_t length);

  //Write to a file
  void write(File file, uint8_t data[]);

  //Read all from a file
  uint8_t *readfile(char *path);

  //Write all to a file
  void writefile(char *path, uint8_t data[]);

  //Append to a file
  void appendfile(char *path, uint8_t data[]);

  //Detect if a file or folder exists
  bool exists(char *path);

  //Create a directory
  void mkdir(char *path, Permissions f);

  //Remove a directory
  void rmdir(char *path);

  //Checks if the user has permissions for the file
  void access(char *path);

private:
  //The current directory
  char *current_directory;

  //The files currently opened
  File open_files[128];
};

#endif