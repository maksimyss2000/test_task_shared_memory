#include "common.h"

#include <string.h>

#define PATH "/tmp"
#define CREATE_KEY_ID 'a'
#define MESSAGE "Hello world!"

void print_key(key_t key){ 
    printf("%d", key);
}

key_t generate_key(){
    key_t key = ftok(PATH, CREATE_KEY_ID);
    if (key < 0) {
        fprintf(stderr, "failed to generate key\n");
        perror("ftok");
        return ERROR_KEY;
    }
    return key;
}

int main(){
    key_t key = generate_key();
    if (key == ERROR_KEY) {
        print_key(ERROR_KEY);
        return(ERROR_KEY);
    }
    int shmid = get_segment(key, IPC_CREAT | 0660);    
    if (shmid == ERROR_GET_SEGMENT) {
        print_key(ERROR_KEY);
        return(ERROR_GET_SEGMENT);
    }
    char* data = (char*)attach_segment(shmid);
    if (data == NULL) {
        print_key(ERROR_KEY);
        return(ERROR_ATTACH_SEGMENT);
    }
    strcpy(data, MESSAGE);
    print_key(key);
    return 0;
}