/*Write a C++ program to input 10 numbers from the user and print:

The total number of even numbers.

The total number of odd numbers.

The sum of all numbers greater than 50.*/

#include<iostream>
using namespace std;
class number{
   public:
    float *num;
    number(int n){
        num = new float[n];
    }
    void state(int n){
        int e_count=0,o_count=0,sum=0;
        for(int i=0;i<n;i++){
            if(int(num[i]%2)==0){
                e_count++;
                cout<<num[i]<<"\t";
            }
            else if(num[i]>50){
                cout<<num[i]<<"\t";
                sum+=num[i];
            }
            else {
                cout<<num[i]<<"\t";
                o_count++;
            }
        }
        delete[] num;
    }
}   
int main(){
    int n;
    cout<<"Enter how many numbers do you want to give"<<endl;
    cin>>n;
    number s(n);
    cout<<"Enter the array content here"<<endl;
    for(int i =0;i<n;i++){
        cout<<"a [ "<<i+1<<" ] = ";
        cin>>s.num[i];
    }
    s.state(n);
    return 0;
    
}