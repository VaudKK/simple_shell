#ifndef SHELL_FUNCTIONS
#define SHELL_FUNCTIONS
#include <sys/stat.h>
int file_exists(char *file_path, struct stat *st);
#endif
