/*
 * Copyright(C) 2013 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * <dirent.h> - Format of directory entries.
 */

#ifndef DIRENT_H_
#define DIRENT_H_

	#include <sys/types.h>
	#include <limits.h>

	/* Size of dirent structure. */
	#define _SIZEOF_DIRENT (sizeof(struct dirent))

	/*
	 * Directory entry.
	 */
	struct dirent
	{
		ino_t d_ino;           /* File serial number. */
		char d_name[NAME_MAX]; /* Name of entry.      */
	};
	
	/* Directory stream buffer size. */
	#define _DIR_BUFSIZ (1024/_SIZEOF_DIRENT)

	/* Directory stream flags. */
	#define _DIR_VALID 001 /* Valid directory? */

	/*
	 * Directory stream.
	 */
	typedef struct
	{
		int fd;             /* Underlying file descriptor.       */
		int flags;          /* Flags (see above).                */
		int count;          /* Valid entries left in the buffer. */
		struct dirent *ptr; /* Next valid entry in the buffer.   */
		struct dirent *buf; /* Buffer of directory entries.      */
	} DIR;
	
	/*
	 * Closes a directory stream.
	 */
	extern int closedir(DIR *dirp);
	
	/*
	 * Opens a directory stream.
	 */
	extern DIR *opendir(const char *dirname);
	
	/*
	 * Reads a directory.
	 */
	extern struct dirent *readdir(DIR *dirp);
	
	/*
	 * Rewinds a directory stream.
	 */
	extern void rewinddir(DIR *dirp);

#endif /* DIRENT_H_ */
