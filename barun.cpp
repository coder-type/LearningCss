#include<iostream>
#include<cstdlib>
using namespace std;
void findunion(char A[20],char B[20], int m, int n)  //yo index khali pani rakhda hunxa
{
	char U[40];
	int k=0, flag,i,j;
	
	for(i=0;i<m;i++)
	{
		U[k]=A[i];
		k++;
	}
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<m;j++)
		{
			if(B[i]==A[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			U[k]=B[i];
			k++;
		}
	}
	cout<<"The union set of set A and B is:"<<endl;
	int p=k;
	for(k=0;k<p;k++)
	{
		cout<<"["<<k+1<<"]:"<<U[k]<<"\t";
	}
	cout<<"\n"<<k;  //to check how much union count has reached:::::! yo line le k vaneko
}
void intersection(char A[20],char B[20], int m, int n)
{
	char I[20];
	int i,j,k=0,flag;
	for(i=0;i<m;i++)
	{
		flag=1;                  //flag outside is wrong logic because when flag is zero then-it
		for(j=0;j<n;j++)         //-it can never be 1-and
		{
			if(A[i]==B[j])
			{
				flag=0;         
				break;
			}
		}
		if(flag==0)             //-and this is going to be true even if the set are equal due to flag;
		{                       //-being initiatate outside the loop    
			I[k]=A[i];
			k++;
		}
	}
	cout<<"The intersection set of set A and B is:"<<endl;
	int p=k;
	for(k=0;k<p;k++)
	{
		cout<<"["<<k+1<<"]:"<<I[k]<<"\t";
	}
	cout<<"\n"<<k;//to check how much intersection count has reached
}
void difference(char A[20],char B[20], int m, int n)
{
	char  DA[20], DB[20], choice;
	int k=0, flag,i,j,p;
	cout<<"Press a for A-B and b for B-A:";
	cin>>choice;
	switch(choice)
	{
	case 'a':
	for(i=0;i<m;i++)
	{
		flag=1;
		for(j=0;j<n;j++)
		{
			if(A[i]==B[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			DA[k]=A[i];
			k++;
		}
	}
	cout<<"The difference A-B is:"<<endl;
	p=k;
	for(k=0;k<p;k++)         // ya i pani chalauda hunxa kina k chalako k ta timele index ko lagi user gari sakeko xau;
	{
		cout<<"["<<k+1<<"]:"<<DA[k]<<"\t";
	}
	break;
	case 'b':
		k=0;
		for(i=0;i<n;i++)
	    {
		flag=1;
		for(j=0;j<m;j++)
		{
			if(B[i]==A[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			DB[k]=B[i];
			k++;
		}
	}
	cout<<"The difference B-A is:"<<endl;
     p=k;
	for(k=0;k<p;k++)
	{
		cout<<"["<<k+1<<"]:"<<DB[k]<<"\t";
	}
	break;
	default:
		cout<<"Wrong choice";
	}
}
int main()
{
	char A[20],B[20];
	int m,n,i,j;
	cout<<"How many elements for set A?";
	cin>>m;
	cout<<"Enter the elements of set A:"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"["<<i+1<<"]:";
		cin>>A[i];
	}
	cout<<"How many elements for set B?";
	cin>>n;
	cout<<"Enter the elements of set B:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"["<<i+1<<"]:";
		cin>>B[i];
	}
	char operation;
	cout<<"Press u for union, i for intersection and d for difference:";
	cin>>operation;
	switch(operation)
	{
		case 'u':
			findunion(A,B,m,n);          //yo vanda pani yesto gara na alik user lai pani sajilo-                                
			break;                       //-hunxa mero code hera ta
		case 'i':
		intersection(A,B,m,n);
		break;
		case 'd':
		difference(A,B,m,n);
		default:
		cout<<"Wrong choice.";	
	}
	return 0;
}
