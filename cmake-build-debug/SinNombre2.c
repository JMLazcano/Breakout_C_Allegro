#include <stdio.h>
#define N 35
int main()
{
int i, j, c, d;
FILE *fp;
float a[N];
float swap;
fp=fopen("UserScores.txt", "r");
{
 for(i=0; i<N; i++)
  fscanf(fp,"%f", &a[i]);
}
 for(c=0; c<(N-1); c++)
 {
  for(d=0; d<(N-c-1); d++)
  {
   if(a[d]>a[d+1])
   {
    swap=a[d];
    a[d]=a[d+1];
    a[d+1]=swap;
   }
  }
 } 
  for(c=0; c<N; c++)
  printf("%8.2f \n", a[c]);
  
fclose(fp);
return 0;
}
