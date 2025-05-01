// Karl Pearson and Rank
#include<iostream>
#include<cmath>
using namespace std;
class dis_math{
   static const int n=6;
    public:
    void karl()
    {
        float a[n],deno,nume;
        float res;
        for(int i=0;i<n;i++){
            if(i==0){
            cout<<"(Total number of data) n = ";
            cin>>a[i];
            }
            else if(i==1){
                cout<<"(Sum of x)Ex = ";
                cin>>a[i];
            }
            else if(i==2){
                cout<<"(Sum of y) Ey = ";
                cin>>a[i];
            }
            else if(i==3){
                cout<<"(Sum of x and y) E(xy)= ";
                cin>>a[i];
            }
            else if(i==4){
            cout<<"(Sum of X squared) E(x^2) = ";
            cin>>a[i];
            }
            else{
            cout<<"(Sum of Y squared) E(y^2) = ";
            cin>>a[i];
            }
        
        }
        nume = (a[0]*a[3])-(a[1]*a[2]);  // n*E(xy) - Ex*Ey
        deno = sqrt((a[0]*a[4])-(a[1]*a[1]))*sqrt((a[0]*a[5])-(a[2]*a[2])); 
        res=nume/deno;
        cout<<"The Karl Pearson Coefficient is "<<res;
        if(res<0)
        {
            cout<<" Which is less Than 0, So They have negative correlation\n";
        }
        else if(res>0){
            cout<<" Which is greater than 0, So They have Positive correlation\n";
        }
        else{
            cout<<" Which is 0, So No Relation";
        }

    }
    void rank()
    {
        float n,d,res;
        cout<<"(Total no. of rank) n = ";
        cin>>n;
        cout<<"(Sum of sqaured d), E(d^2) = ";
        cin>>d;
        res = 1-((6*d)/(pow(n,3)-n));
        cout<<"The Rank Correlation is "<<res;
        if(res<0)
        {
            cout<<" Which is less Than 0, So They have negative correlation\n";
        }
        else if(res>0){
            cout<<" Which is greater than 0, So They have Positive correlation\n";
        }
        else{
            cout<<" Which is 0, So No Relation";
        }


    }
};
int main()
{
    dis_math s;
    int ans;
    cout<<"This is a program that can calculate the following\n";
    cout<<"1.Karl Pearson Method\n"<<"2. Spearman's Rank Correlation\n";
    cin>>ans;
    switch(ans)
    {
        case 1: 
        cout<<"Enter the details to be intepreted below (Karl Pearson Method)\n";
        s.karl();
        break;
        case 2:
        cout<<"Enter the details to be intepreted below (Spearman's Rank Correlation)\n";
        s.rank();
        break;
        default:
        cout<<"Invalid Number!! Try Again!!";
    }
    return 0;
}