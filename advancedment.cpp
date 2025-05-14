#include<iostream>
#include<cstdlib>
using namespace std;
void findunion(char A[],char B[], int m, int n)   
{
	char U[40];
	int k=0, flag,i,j,DA_count;
	
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
    int length_AUB = k;  // -> AUB = n(A)+n(B)-n(AnB)
	cout<<"The union of Set A and B are:"<<endl;
    cout<<"AUB = {";
    for(i = 0;i<length_AUB;i++){
        cout<<U[i];
        if(i<length_AUB-1){
            cout<<", ";
        }
        else{
            cout<<"}";
        }
    }
}
void intersection(char A[],char B[], int m, int n)
{
	char I[20];
	int i,j,k=0,flag;
	for(i=0;i<m;i++)
	{
		
		for(j=0;j<n;j++)
		{  flag=1;
			if(A[i]==B[j])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			I[k]=A[i];
			k++;
		}
	}
    int intersection_count = k;
	 cout<<"The intersection of Set A and B are:"<<endl;
    cout<<"AnB = {";
    for(i = 0;i<intersection_count;i++){
        cout<<I[i];
        if(i<intersection_count-1){
            cout<<", ";
        }
        else{
            cout<<"}";
        }
    }   
}
void difference(char A[],char B[], int m, int n)
{
	char  DA[20], DB[20], choice;
	int k=0, flag,i,j,p,DA_count,DB_count;
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
	DA_count=k;
	for(i=0;i<DA_count;i++)            
	{
		cout<<DA[i];
        if(i<DA_count-1){
            cout<<", ";
        }
        else{
            cout<<"}";
        }
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
    DB_count=k;
	for(i=0;i<DB_count;i++)
	{
		cout<<DB[i];
        if(i<DB_count-1){
            cout<<", ";
        }
        else{
            cout<<"}";
        }
	}
	break;
    default:
		cout<<"Wrong choice!!!";
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
		cout<<"a [ "<<i+1<<" ]: "; //yo line le k gareko ho data kasari leko yesari haina yo data kun set ko vanera pani vana na ani like label a[1], here a is label:
		cin>>A[i];
	}
	cout<<"How many elements for set B?";
	cin>>n;
	cout<<"Enter the elements of set B:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"b [ "<<i+1<<" ]: ";//same here for data input
		cin>>B[i];
	}
	int choose;
	cout<<"Choose any one of the given below: "<<endl;
    cout<<"1. Union"<<endl
        <<"2. Intersection"<<endl
        <<"3. Difference"<<endl
        <<"Choose (1-3) = ";
    cin>>choose;
        switch(choose)
        {
            case 1:
            findunion(A,B,m,n);
            break;
            case 2:
            intersection(A,B,m,n);
            break;
            case 3:
            difference(A,B,m,n);
            default:
            cout<<"Invalid Input!!!";
        }
        return 0;
}
