#include <sys/sem.h>

int sys_semctl(int semid, int cmd, int val){
	/*int valReturn;
	struct semaphore *s;
	s = (&semtab[semid]);

	switch(cmd){
		case GETVAL:
			if(s->exists){
				valReturn = s->counter;
			} else {
				valReturn = -1;
			}
			break;
		case SETVAL:
			if(s->exists){
				s->counter = val;
				valReturn = 0;
			} else {
				valReturn = -1;
			}
			break;
		case IPC_RMID:
			valReturn = destroy(semid);
			break;
		default:
			valReturn = -1;
			break;
	}
	return valReturn;*/
    return semid + cmd+val;
}