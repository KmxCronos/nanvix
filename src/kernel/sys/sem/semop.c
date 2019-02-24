#include <sys/sem.h>
#include <nanvix/klib.h>

int sys_semop(int semid, int op){
	if(op > 0){
		return up(semid);
	}
	else if(op < 0){
		return down(semid);
	}
	else{
		return -1;
	}
}