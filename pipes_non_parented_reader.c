/* lector_fifo.c - Tuberia con nombre usando mkfifo */
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/mode.h>
#include <stdio.h>
int linea (int df, char *cad);

int main ()
{
  int descr, i;
  short cadena[1024];

  unlink ("tuberia");
  sleep(1);
  mkfifo ("tuberia", 0);
  chmod ("tuberia", 0777);  //777 en octal
  descr = open ("tuberia", O_RDONLY);
	read (descr, cadena, 1024*2);
	for(i=0; i<1024; i++)
  {
    printf("%hi ", cadena[i]); fflush(stdout);
  }
  close (descr);
  printf ("Fin del lector.\n");
}

