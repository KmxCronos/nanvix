/*
 * Copyright(C) 2011-2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * This file is part of Nanvix.
 * 
 * Nanvix is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Nanvix is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Nanvix. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SEM_H_
#define SEM_H_
	#include <nanvix/pm.h>

	/**
	 * @brief Comand values for semaphores.
	 */
	/**@{*/
	#define GETVAL   0 /**< Returns the value of a semaphore. */
	#define SETVAL   1 /**< Sets the value of a semaphore.    */
	#define IPC_RMID 3 /**< Destroys a semaphore.            */
	/**@}*/

	/**
	 * @name Semaphore table boundaries
	 */
	/**@{*/
	#define FIRST_SEM ((&semtab[0]))           /**< First process. */
	#define LAST_SEM ((&semtab[SEM_MAX - 1])) /**< Last process.  */
	/**@}*/

	#define IS_SEM_VALID(semid) (if(semid >= 0 && semid < SEM_MAX && semtab[semid].key != -1) TRUE ? FALSE)

	#define SEM_MAX 100

	typedef struct{
		int key;
		int value;
		struct process * queue;
	} semaphore_t;

	/* Forward definitions. */
	extern int semget(unsigned);
	extern int semctl(int, int, int);
	extern int semop(int, int);

	extern int is_sem_valid(int semid);
	extern void sem_init(void);
	extern int create(unsigned);
	extern int up(int);
	extern int down(int);
	extern int destroy(int);

	extern semaphore_t semtab[SEM_MAX];
#endif /* SEM_H_ */
