#include <stdio.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main(void) 
{
	int n,c,p[10],wt[10],i,w,v[10][10],l,x[10];
	
	printf("Enter no. of item: ");
	scanf("%d",&n);
	
	printf("Enter Capecity: ");
	scanf("%d",&c);
	l=c;
	
	printf("Enter weight array:\n");
	for(i=1;i<=n;i++)
	    scanf("%d",&wt[i]);
	   
	printf("Enter Profit array:\n");
	for(i=1;i<=n;i++)
	    scanf("%d",&p[i]);
	    
	for(i=0;i<=n;i++)
	{
	    v[i][0]=0;
	    v[0][i]=0;
	}
	
	for(i=1;i<=n;i++)
	{
	    for(w=1;w<=c;w++)
	    {
	        if(wt[i]>w)
	            v[i][w]=v[i-1][w];
	        else
	            v[i][w]=max(v[i-1][w],p[i]+v[i-1][w-wt[i]]);
	    }
	}
	
	for(i=n;i>0;i--)
	{
	    if(v[i-1][c] == v[i][c])
	        x[i]=0;
	    else
	    {
	        x[i]=1;
	        c=c-wt[i];
	    }
	}
	
	printf("0/1 Array is: ");
	for(i=1;i<=n;i++)
	    printf("%d ",x[i]);
	printf("\nMaximum Profit: %d\n",v[n][l]);
	return 0;
}

