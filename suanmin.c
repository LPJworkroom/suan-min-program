#include<stdio.h>
int yushu(int x , int y );
int main()
{
	char a,b,c,d,e,f,g,h;/*保存首字母*/
	int A,B,posibility;
	printf("请用小写字母输入一方姓名首字母,只支持2到4位：");
	scanf("%c%c%c%c",&a,&b,&c,&d);
	if (c=' ')
	{
	A=yushu(a,b);       /*即2个字*/
	}
	else if (d=' ')
	{
	A=yushu(yushu(a,b),c);/*即3个字*/
	}
	else 
	{
	A=yushu(yushu(a,b),yushu(c,d));/*即4个字*/
	}

	/*以上为第一方*/
   
	printf("请用小写字母输入另一方姓名首字母，只支持2到4位：");
        scanf("%c%c%c%c",&e,&f,&g,&h);
        if (g=' ')
        {
        B=yushu(e,f);       /*即2个字*/
        }
        else if (h=' ')
        {
        B=yushu(yushu(e,f),g);/*即3个字*/
        }
        else 
        {
        B=yushu(yushu(e,f),yushu(g,h));/*即4个字*/
        }

	/*以上为第二方*/

	posibility=yushu(A,B);
	printf("成功的可能性是：%d%%\n",posibility);
	if (posibility>70)
	printf("恭喜！成功率很大！\n");
	else if (posibility>40)
	printf("你们还需要努力，不要放弃希望！\n");
	else 
	printf("人定胜天，不要被机器的计算吓到！\n");
}
int yushu(int x , int y)    /*用来求百位后数字的程序*/
{	int z;
	z=x+y-((x+y)/100)*100;
	return z;
}
