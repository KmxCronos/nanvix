#include <sys/sem.h>
#include <nanvix/const.h>

/**
 * @brief Creates a semaphore.
 */
PUBLIC int sys_semget(unsigned key){
	semaphore_t * s;
	int i = 0;

	//We find an already existing semaphore with this key
	for(s = FIRST_SEM; s <= LAST_SEM; s++, i++){
		if(s->key == (int)key)
			return i;
    }

	//Else we return a new one
	return create(key);
}