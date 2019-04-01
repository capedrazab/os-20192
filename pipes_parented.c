#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int r;
    int pipefd[2];
    char buf[11];
    
    r = pipe(pipefd);
    if(pipefd < NULL){ 
        perror("Error pipe() "); 
        exit(-1);
    }
    pid = fork();
    //handle errors
    if(pid == 0){
      //hijo escribe pipe - pipefd[1]
      close(pipefd[0]);
      // ssize_t write(int fd, const void *buf, size_t count);
      write(pipefd[1], "hola", 4);
      //handle errors
      close(pipefd[1]);
      exit(0);    
    }else
    { 
      //padre lee pipe - pipefd[0]
      close(pipefd[1]);
      //ssize_t read(int fd, void *buf, size_t count);
      r = read(pipefd[0], buf, 10);
      buf[r] = 0;
      //handle errors
      close(pipefd[0]);
      printf("\nMensaje del hijo: %s \n", buf);
    }
} 

