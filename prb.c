#include"prb.h"

void prb()
{
  //存放101个#号充当进度
  char bar[NUM];
  //初始化为'\0'
  memset(bar,'\0',sizeof(bar));
  int i=0;
  //定义用于旋转的字符
  char *ar="|/-\\";
  while(i<=100)
  {
    printf("[%-100s][%-3d%%][%c]\r",bar,i,ar[i%4]);
    //刷新缓冲区
    fflush(stdout);
    bar[i++]='#';
    //每次停留时间
    usleep(500000);
  }
  printf("\n");
  //printf("hello prb!\n");
}
