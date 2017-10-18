#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
void printedge( char[],int,int);
void ge();
void printanime(int,int,int,int);
int main()
{
int x,y,f;static int length=60,height=30;
double vx,vy,fspeed;
double cachex=0,cachey=0;
printf("input the x and y:"); scanf("%d,%d",&x,&y);
printf("input the vx and vy:"); scanf("%lf,%lf",&vx,&vy);
printf("input the framespeed:");  scanf("%lf",&fspeed);
	for (f=0;;f++)
	{
	printanime(x,y,length,height);
	cachex=cachex+vx/fspeed;
	cachey=cachey+vy/fspeed;
	vy=vy-15/fspeed;//重力加速度
	if(y==1) {if(vx>0) vx=vx-2.5/fspeed; else vx=vx+2.5/fspeed;}//滑动摩擦
	if((y==1&&vy<0)||(y==height&&vy>0)) vy=-0.6*vy;
	if((x==2*length-16&vx>0)||(x==1&&vx<0)) vx=-0.6*vx;
	if (fabs(cachex)>1) {if (cachex>0) {cachex--;x++;}
			     else {cachex++;x--;}}
	if (fabs(cachey)>1) {if (cachey>0) {cachey--;y++;}
			     else {cachey++;y--;}}
	if (fabs(vx)<0.1) break;
	usleep(1000000/fspeed);
	}
return 0;
}

void printanime(int x,int y,int length,int height)
{
int i,j;
        for (i=0;i<60;i++) printf("\n");for(j=0;j<length;j++) printf("口");printf("\n");
        for(i=0;i<height-y;i++)  
	{printf("口");for(j=0;j<length*2-4;j++) printf(" ");printf("口\n");}
                        char yi[]= "  ********  ";printedge(yi,x,length);
			char er[]= " *L  P   J* ";printedge(er,x,length);
                        char san[]="*          *";printedge(san,x,length);
			char si[]= "* workroom *";printedge(si,x,length);
			char wu[]= " *        * ";printedge(wu,x,length);
			char liu[]="  ********";printedge(liu,x,length);
	for(i=1;i<y;i++)   
	{printf("口");for(j=0;j<length*2-4;j++) printf(" ");printf("口\n");}
                        for(j=0;j<length;j++) printf("口");
                        printf("\n");
return;
}

void   printedge(char draw[],int x,int length)
{
int i;
ge();
for (i=1;i<x;i++) printf(" ");
printf("%s",draw);
for (i=x+strlen(draw);i<length*2-3;i++)  printf(" ");
ge();
printf("\n");
}
                                                                               
void ge()
{
printf("口");
}
