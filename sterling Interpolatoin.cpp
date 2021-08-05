#include<stdio.h>
#include<math.h>
#include<conio.h>
main ()
{
	int n; // no. of terms.
	int i,j;
	float ax[10],ay[10];//storing x and y
	float x,y,h,p;
	float d[20][20];
	float y1,y2,y3,y4;
	printf("\n\n Enter the no. of terms\n ");
	scanf("%d",&n);
	printf("\n\n Enter the values of x\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&ax[i]);
	}
	printf("\n\n Enter the values oy y\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&ay[i]);
	}
	printf("\n\n Enter the value of x for which f(x) is required ");
	scanf("%f",&x);
	h=ax[1]-ax[0];
	for(i=0;i<n-1;i++)
	d[i][1]=ay[i+1]-ay[i];
	for(j=2;j<=4;j++)	
	for(i=0;i<n-j;i++)
	d[i][j]=d[i+1][j-1]-d[i][j-1];
	/*printf("\n Difference Table is\n");

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n-i;j++)
		printf("%8.6lf\t",d[i][j]);
		printf("\n");
		}*/
	i=0;
	do
	{
		i++;
	}
	while(ax[i]<x);
	i--;
	p=(x-ax[i])/h;
	y1=p*d[i][1];
	y2=p*(p-1)*(d[i][2]+d[i-1][2])/4;
	y3=p*(p-1)*(p-0.5)*d[i-1][3]/6;
	y4=(p+1)*p*(p-1)*(p-2)*(d[i-2][4]+d[i-1][4])/48;
	y=ay[i]+y1+y2+y3+y4;
	printf("\n at x = %6.2f , f(x)= %6.8f",x,y);
	}
