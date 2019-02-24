#include <sys/sem.h>
#include <nanvix/klib.h>

//TODO check for invalid semaphore
int sys_semctl(int semid, int cmd, int val){
    if(!is_sem_valid(semid))
        return -1;
		
	switch(cmd){
		case GETVAL:
			return semtab[semid].value;
		break;

		case SETVAL:
			semtab[semid].value = val;
			return 0;
		break;

		case IPC_RMID:
			return destroy(semid);
		break;
	}
	return -1;
}