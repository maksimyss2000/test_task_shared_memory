#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_BUF 1000
#define ERROR_KEY -1
#define ERROR_GET_SEGMENT -2 
#define ERROR_ATTACH_SEGMENT -3
#define ERROR_DELETE_SEGMENT -4

int  delete_segment(int shmid);
int get_segment(key_t key, int mask);
void* attach_segment(int shmid);
