#include <stdio.h>
#include <stdlib.h>
#define N 7
#define M 3

int main(){
 int found, flag;
 int l, i, j, k = 1, sum = 0;
 int p[100][100], c[100][100], m[100], r[100], a[100], temp[100];

 FILE *input = fopen("input_ok.txt", "r");
 FILE *output = fopen("output_ok.txt", "w");

 //Total resources vector
 for(i = 1; i <= M; i++){
   fscanf(input, "%d", &r[i]);
 }

 //Available resource vector
 for(i = 1;i <= M; i++){
  fscanf(input, "%d", &a[i]);
  temp[i] = a[i];
 }

 //Allocation Matrix
 for(i = 1; i <= N; i++){
   for(j = 1; j <= M; j++)
    fscanf(input, "%d", &p[i][j]);
 }

 //Request Matrix
 for(i = 1; i <= N; i++){
   for(j = 1; j <= M; j++)
    fscanf(input, "%d", &c[i][j]);
 }

 for(i = 1; i <= N; i++){
   sum = 0;
   for(j = 1; j <= M; j++){
     sum += p[i][j];
   }
   if(sum == 0){
     m[k] = i;
     k++;
   }
 }

 for(i = 1; i <= N; i++){
   for(l = 1; l < k; l++)
   if(i != m[l]){
     flag = 1;
     for(j = 1; j <= M; j++)
      if(c[i][j] < temp[j]){
        flag = 0;
        break;
      }
  }

  if(flag == 1){
    m[k] = i;
    k++;
    for(j = 1; j <= M; j++)
      temp[j] += p[i][j];
  }
 }

 int count = 0;
 for(j = 1; j <= N; j++){
   found = 0;
   for(i = 1; i < k; i++){
     if(j == m[i])
      found = 1;
   }
   if(found == 0) {
     ++count;
     fprintf(output,"%d ",j);
   }
 }

 if(count == 0) {
   fprintf(output, "No deadlock is detected\n");
 }

 fclose(input);
 fclose(output);
 return 0;
}


/*
#include<stdio.h>
static int mark[20];
int i,j,np,nr;

int main()
{
int alloc[10][10],request[10][10],avail[10],r[10],w[10];

printf("\nEnter the no of process: ");
scanf("%d",&np);
printf("\nEnter the no of resources: ");
scanf("%d",&nr);
for(i=0;i<nr;i++)
{
printf("\nTotal Amount of the Resource R%d: ",i+1);
scanf("%d",&r[i]);
}




printf("\nEnter the request matrix:");

for(i=0;i<np;i++)
for(j=0;j<nr;j++)
scanf("%d",&request[i][j]);

printf("\nEnter the allocation matrix:");
for(i=0;i<np;i++)
for(j=0;j<nr;j++)
scanf("%d",&alloc[i][j]);
//Available Resource calculation
for(j=0;j<nr;j++)
{
avail[j]=r[j];
for(i=0;i<np;i++)
{
avail[j]-=alloc[i][j];

}
}

//marking processes with zero allocation

for(i=0;i<np;i++)
{
int count=0;
 for(j=0;j<nr;j++)
   {
      if(alloc[i][j]==0)
        count++;
      else
        break;
    }
 if(count==nr)
 mark[i]=1;
}
// initialize W with avail

for(j=0;j<nr;j++)
    w[j]=avail[j];

//mark processes with request less than or equal to W
for(i=0;i<np;i++)
{
int canbeprocessed=0;
 if(mark[i]!=1)
{
   for(j=0;j<nr;j++)
    {
      if(request[i][j]<=w[j])
        canbeprocessed=1;
      else
         {
         canbeprocessed=0;
         break;
          }
     }
if(canbeprocessed)
{
mark[i]=1;

for(j=0;j<nr;j++)
w[j]+=alloc[i][j];
}
}
}

//checking for unmarked processes
int deadlock=0;
for(i=0;i<np;i++)
if(mark[i]!=1)
deadlock=1;


if(deadlock)
printf("\n Deadlock detected");
else
printf("\n No Deadlock possible");
}
*/
