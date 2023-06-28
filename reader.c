#include "common.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

key_t get_key(){
    key_t key;
    scanf("%d", &key);
    if (key == ERROR_KEY) {
        fprintf(stderr, "get error key");
        exit(ERROR_KEY);
    }
    return key;
}

int main(){
    key_t key = get_key();
    int read_mask = 0;
    int shmid = get_segment(key, read_mask);    
    if (shmid == ERROR_GET_SEGMENT) {
        return(ERROR_GET_SEGMENT);
    }
    char* data = (char*)attach_segment(shmid);
    if (data == NULL) {
        return(ERROR_ATTACH_SEGMENT);
    }
    printf("message:%s\n", data);
    delete_segment(shmid);
    return 0;
}