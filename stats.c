#include <sys/stat.h>
#include <sys/types.h>


/**
 * file_exists - check if a file exists
 * @file_path: the path to the file
 * @st: the statbuffer
 *
 * Return: 1 if successful otherwise failed
 */
int file_exists(char *file_path, struct stat *st)
{
	return (stat(file_path, st));
}
