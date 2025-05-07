#include<iostream>
#include<iomanip>
using namespace std;
class problem{
    public:
    int x,y;
    problem(){
        cout<<"Default constructor called"<<endl;
    }
    problem(int a , int b){
        cout<<"problem to swap to numbers"<<endl;
        a = a-b;
        b = b+a;
        a = b-a;
        cout<<"The number after swapped is: "<<a<<" and "<<b<<endl;
    }
    ~problem(){
        cout<<"Destructor called"<<endl;
    }
};
int main()
{
    problem s1;
    cout<<"Enter two numbers"<<endl;
    cin>>s1.x>>s1.y;
    problem s2(s1.x,s1.y);
    return 0;
    
}