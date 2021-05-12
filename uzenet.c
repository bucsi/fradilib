#include <stdio.h>      // printf
#include <stdlib.h>     // exit
#include <unistd.h>     // getpid
#include <sys/msg.h>    // msgsnd, msgrcv
#include <string.h>     // strlen

#include "uzenet.h"

int uzenetsor_letrehoz(key_t kulcs){
    int uzenetsor = msgget(kulcs, 0600 | IPC_CREAT);
    if (uzenetsor < 0){
        printf("Hiba az %d uzenetsor letrehozaskor", uzenetsor);
        exit(EXIT_FAILURE);
    }
    return uzenetsor;
}

void uzenet_kuld(int uzenetsor, const char message[1024]) { 
    struct uzenet uz;
    uz.mtype = 5,
    strcpy(uz.mtext, message);
    int status; 
    status = msgsnd( uzenetsor, &uz, strlen ( uz.mtext ) + 1 , 0 ); 
    if (status < 0){
        perror("msgsnd");
    }
}

void uzenet_fogad(int uzenetsor){ 
    struct uzenet uz; 
    int status; 
    status = msgrcv(uzenetsor, &uz, 1024, 5, 0 ); 
    if (status < 0){
        perror("msgsnd"); 
    }else{
        printf("%d folyamat %ld kódú üzenetet kapott: %s\n",getpid(), uz.mtype, uz.mtext);
    }
}
