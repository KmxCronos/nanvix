#include <sys/sem.h>
#include <nanvix/const.h>
#include <nanvix/hal.h>
#include <nanvix/pm.h>
#include <nanvix/klib.h>

/**
 * @brief Sempahore table.
 */
PUBLIC semaphore_t semtab[SEM_MAX];

PUBLIC int is_sem_valid(int semid){
    if(semid >= 0 && semid < SEM_MAX && semtab[semid].key != -1)
        return 1;
    return 0;
}

/**
 * @brief Initializes the semaphore system.
 */
PUBLIC void sem_init(void){
    semaphore_t * s;

    for(s = FIRST_SEM; s <= LAST_SEM; s++){
        s->key = -1;
    }
}

PUBLIC int create(unsigned key){
    int i = 0;
    semaphore_t * s;

    for(s = FIRST_SEM; s <= LAST_SEM; s++, i++){
        if(s->key == -1){
            s->value = 1;
            s->key = key;
            return i;
        }
    }
    return -1;
} 

//TODO check for invalid proc
PUBLIC int up(int semid){
    if(!is_sem_valid(semid))
        return -1;

    disable_interrupts();

    semtab[semid].value++;
    //We now have a ressource, let's wakeup the proc that have been waiting for the longest
    if(semtab[semid].value > 0 && semtab[semid].queue != NULL){
        wakeup(&semtab[semid].queue);
    }

    enable_interrupts();
    return 0;
}

PUBLIC int down(int semid){
    if(!is_sem_valid(semid))
        return -1;

    disable_interrupts();

    if(semtab[semid].value > 0){
        semtab[semid].value--;
    }
    //Ressource is not free we have to put asleep the proc
    else{
        sleep(&semtab[semid].queue, PRIO_SEM);
    }

    enable_interrupts();
    return 0;
}

PUBLIC int destroy(int semid){
    if(!is_sem_valid(semid))
        return -1;

    semtab[semid].key = -1;
    semtab[semid].value = 0;

    return 0;
}