#include<iostream>
using namespace std;
int main()
{
    int a[5],temp;
    cout<<"Enter the no. of elements of the array"<<endl;
    cout<<"This is for ascending order"<<endl;
      for(int i=0;i<5;i++){
        cout<<"a ["<<i+1<<"] = ";
        cin>>a[i];
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"The array after execution turn to this"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}