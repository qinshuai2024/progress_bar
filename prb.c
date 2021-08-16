#include"prb.h"

void prb()
{
  char bar[NUM];
  memset(bar,'\0',sizeof(bar));
  int i=0;
  char *ar="|/-\\";
  while(i<=100)
  {
    printf("[%-100s][%-3d%%][%c]\r",bar,i,ar[i%4]);
    fflush(stdout);
    bar[i++]='#';
    usleep(500000);
  }
  printf("\n");
  //printf("hello prb!\n");
}
