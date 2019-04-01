#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>


int main()
{
    pid_t pid;
    key_t key=1234;
    int shmId;
    float a,b,c, *ap;
    int status, cpid, r;
    
    shmId = shmget(key, 3*sizeof(float), 0666|IPC_CREAT);
    if(shmId < 0){
        perror("Error en shmget");
        exit(-1);
    }
    ap = (float *)shmat(shmId, 0, 0);
    *ap = 3.1416;
    pid = fork();
    //handle errors
    if(pid == 0)
    { //hijo
        *(ap+1) = 0.707;
    }else
    { //padre
        if (wait(&status) == pid){
            printf("\n %f   %f ", *ap, *(ap+1));
        }
    }
    r = shmdt(ap);
    if(r < 0){
      perror("error shmdt ");
      exit(-1);
    }
}
