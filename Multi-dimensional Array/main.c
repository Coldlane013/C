#include<stdio.h>
int main()
{
	int i,j,k;
	int a[3][3];                                            //2D array declaration
	int b[3][3];
	printf("Enter the elements in array A: \n");            //entering elements in array 'a'
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Element at [%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nPrinting 2D array A\n");                      //printing elements of array 'a'
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the elements in array B: \n");               //entering elements in array 'b'
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Element at [%d][%d]: ",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nPrinting 2D array B\n");                 //printing elements of array 'b'
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	int arr[3][3][3];                                  //3D array declaration
	printf("\nCopying values in 3D array..... \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				if(i==0)
				{
					arr[i][j][k]=a[j][k];              //copying elements of 2D array into 3D array
				}
				else
				{
					arr[i][j][k]=b[j][k];
				}
			}
		}
	}
	printf("\nPrinting elements in 3D array: \n");    //printing elements of 3D array
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
			printf("%d ",arr[i][j][k]);
			if(k==2)
			{
			printf("\n");
			}
			}
		}
		printf("\n");
	}
	return 0;
}
