#include <sys/sem.h>

int sys_semget(unsigned key){
    /*
	struct semaphore *s = FIRST_SEM;
	int semid = 0;

	while (s <= LAST_SEM && (!s->exists || s->key != key)) {
		semid++;
		s++;
	}

	if (s <= LAST_SEM) {
		return semid;
	}
  else{
		semid  = create(COUNT_INIT, key);
		return semid;
	}*/
    return (int)key;
}