#include "common.h"

int delete_segment(int shmid){
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        fprintf(stderr, "failed to attach segment\n");
        perror("shmctl");
        return ERROR_DELETE_SEGMENT;
    }
    return 0;
}

int get_segment(key_t key, int mask){
    int shmid = shmget(key, SIZE_BUF, mask);
    if (shmid < 0) {
        fprintf(stderr, "failed to get segment\n");
        perror("shmget");
        return ERROR_GET_SEGMENT;
    }
    return shmid;
}

void* attach_segment(int shmid){    
    void* addr = shmat(shmid, NULL, 0);
    if (addr == (void *) -1) {
        fprintf(stderr, "failed to attach segment\n");
        perror("shmat");
        delete_segment(shmid);
        return NULL;
    }
    return addr;
}
