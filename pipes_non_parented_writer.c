#include <stdlib.h>
#include <fcntl.h>
//#include <sys/mode.h>
#include <stdio.h>
int main ()
{
    int descr, longmens, i;
    short mensaje[1024];
    for(i=0; i<1024; i++)
    {
      mensaje[i] = i;
    }

    do
    {
      descr = open ("tuberia", O_WRONLY);
      if (descr == -1) sleep (1);
    }
    while (descr == -1);
    for (i=0; i<1; i++)
    {
      write (descr, mensaje, 1024*2);
      sleep (1);
    }
    close (descr);
    printf("Fin del escritor %d\n", getpid ());
}
