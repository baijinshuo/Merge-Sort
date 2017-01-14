#include<stdio.h>
#include<stdlib.h>
#define N  10
void sort(int input[N+1],int copy[N+1],int key);
int main()
{
     int i,input[N+1],copy[N+1];
     printf("please input ten elements :\n");
     for(i=1;i<=N;i++)
     scanf("%d",&input[i]);
     sort(input,copy,1);
     printf("After the sort the result is :");
     for(i=1;i<=N;i++)
     printf("%-3d",input[i]);
     printf("\n");

}
void sort(int input[N+1],int copy[N+1],int key)
{
     int i=1,j=1,k,m=1,o=1,p=1,n;
     input[0]=key;
     copy[0]=key;
     if(key<=N/2)
     {
       while(i<=N/(2*key))
       { o=1;
	 p=1;
	 for(k=0;k<2*key-1;k++)
	  {  if(input[(j-1)*key+o]<input[j*key+p])
	      {	copy[m++]=input[(j-1)*key+o];o++;}
	   else{ copy[m++]=input[j*key+p];p++;}
	   if(o>=key+1||p>=key+1) break;
	  }
	if(o<key+1)
	for(n=0;n<=key-o;n++) copy[m++]=input[(j-1)*key+o+n];
	else
	for(n=0;n<=key-p;n++) copy[m++]=input[j*key+p+n];
	j+=2;
	i++;
       }
     key=2*key;
     for(n=1;n<=N;n++)
     input[n]=copy[n];
     sort(input,copy,key);
     }
     
}
