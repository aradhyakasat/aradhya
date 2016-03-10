#include<iostream>
#include<stdlib.h>
using namespace std;
int n,k;
float a[10][10],id[10][10],inv[10][10],temp[10][10],e[10],eta[10],c[10];
void copytotemp()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			temp[i][j]=inv[i][j];
}

void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<inv[i][j]<<" ";
	}
}
void printid()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<id[i][j]<<" ";
	}
}
void mult()
{
	int i,j,l;
	float sum;
	if(k==0)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				temp[i][j]=id[i][j];
		//print();	
	}
	else
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				{
					sum=0;
					for(l=0;l<n;l++)
				{
					sum=sum+temp[i][l]*id[l][j];
				}
				inv[i][j]=sum;
			}
			//print();
		copytotemp();	
	}
	
}
void inverse()
{
	int i,j;
	for(i=0;i<n;i++)
		e[i]=0;
		if(k!=0)
		{
			for(i=0;i<n;i++)
			{
			c[i]=id[i][k];
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
				e[i]=e[i]+temp[i][j]*c[j];
				}
			}
			for(i=0;i<n;i++)
			{
				if(i!=k)
					eta[i]=-e[i]/e[k];
			}
			eta[k]=1/e[k];
			for(i=0;i<n;i++)
				id[i][k]=eta[i];
		}
			else
			{
				for(i=0;i<n;i++)
					if(i!=k)
						id[i][k]=-id[i][k]/id[k][k];

				id[k][k]=1/id[k][k];	
			}
		mult();
	

}


int copy()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			id[i][j]=a[i][j];
		}
}
int main()
{
	int i,j;
	cout<<"Enter order of matrix";
	cin>>n;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	copy();  //copies a to id
	k=0;
	printid();
	while(k<n)	
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j!=k)
				{
					if(j!=i)
						id[i][j]=0;
					else
						id[i][j]=1;	
				}
			}
		}
		if(id[k][k]==0)
		{cout<<"Inverse does not exist!";
			exit(0);
		}
		else
			{printid();
		inverse();
		copy();
		k++;
	}
	}
	print();
}