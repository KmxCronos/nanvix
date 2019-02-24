#include <sys/sem.h>

int sys_semop(int semid, int op){
    /*
	int valReturn;

	if (op < 0) {
		for (int i = 0; i < -op; i++){valReturn = down(semid);}
	}
  else if (op > 0) {
		for (int i = 0; i < op; i++){valReturn = up(semid);}
	}
	else {
		valReturn = -1;
	}

	return valReturn;*/
    return semid + op;
}