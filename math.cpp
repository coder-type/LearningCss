// Karl Pearson and Rank
#include<iostream>
#include<iomanip>
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
    void regression()
    {
        float a[n],deno,nume;
        float res_a,res_b,mean_y,mean_x;
        int ans;
        cout<<"Choose either one of the regression coefficient"<<endl<<"1. X on Y"<<endl<<"2. Y on X"<<endl;
        cin>>ans;
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
        mean_x = a[1]/n;
        mean_y = a[2]/n;
        if(ans == 1){
        deno =  (a[0]*a[5])-(a[2]*a[2]); 
        cout<<"So for calculating X on Y we consider a linear equation in terms of X"<<endl<<"Which means that X is considered as dependent variable and Y is considered as independent variable"<<endl;
        cout<<"So, the linear equation is:"<<endl<<"X = a + bY"<<endl<<"Where a and b are the parameters of regression coefficient"<<endl;
        cout<<"So calculating a and b and giving the result or the final equation"<<endl;
        res_b = nume/deno;
        res_a = mean_x - (res_b*mean_y);
        cout<<"Now, the final equation is:"<<endl<<"X = "<<res_a<<" + "<<res_b<<" Y "<<endl;
    }
    else {
        deno = (a[0]*a[4])-(a[1]*a[1]);
        cout<<"So for calculating Y on X we consider a linear equation in terms of Y"<<endl<<"Which means that Y is considered as dependent variable and X is considered as independent variable"<<endl;
        cout<<"So, the linear equation is:"<<endl<<"Y = a + bX"<<endl<<"Where a and b are the parameters of regression coefficient"<<endl;
        cout<<"So calculating a and b and giving the result or the final equation"<<endl;
        res_b = nume/deno;
        res_a = mean_y - (res_b*mean_x);
        cout<<"Now, the final equation is:"<<endl<<"Y = "<<res_a<<" + "<<res_b<<" X "<<endl;
    }
    
    }
};
int main()
{
    dis_math s;
    int ans;
    cout<<"This is a program that can calculate the following\n";
    cout << "========== MENU ==========" << endl;
    cout << "1.Karl Pearson Method" << endl 
         << "2. Spearman's Rank Correlation" << endl 
         << "3. Regression Coefficient" << endl;
    cout << "==========================" << endl;
    cin>>ans;
    switch(ans)
    {
        case 1: 
        cout<<"Enter the details to be intepreted below (Karl Pearson Method)"<<endl;
        s.karl();
        break;
        case 2:
        cout<<"Enter the details to be interpreted below (Spearman's Rank Correlation)"<<endl;
        s.rank();
        break;
        case 3:
        cout<<"Enter the details to be interpreted below (Regression Coefficient)"<<endl;
        s.regression();
        break;
        default:
        cout<<"Invalid Number!! Try Again!!";
    }
    return 0;
}
