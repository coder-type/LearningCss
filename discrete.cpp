#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
// Forward declarations
int _intersec(int arr[], int brr[], int na, int nb);
void intersec(int arr[], int brr[], int na, int nb);
void diff(int arr[], int brr[], int na, int nb);
void _union(int arr[],int brr[],int na,int nb);

void _union(int arr[],int brr[],int na,int nb){
  int  c; 
  c = _intersec(arr,brr,na,nb);
    int u;
     u = na + nb-c;
    int *u_set;
    u_set = new int[u];
    for(int i = 0; i < na; i++)
    {
        u_set[i] = arr[i];//copying elements of a into union set;

    }
    int put = na;
    for(int i=0; i<nb;i++){ // putting elements of b that aren't in a;
        bool found = false;
        for(int j=0;j<na;j++){
        if(brr[i] == arr[j]){
            found = true;
            break;
        }
    }
        if(!found){
            u_set[put++] = brr[i]; 
        }
    }

    
        cout<<"Union of Set A and Set B."<<endl;
        for(int i=0;i<u;i++){
            cout<<u_set[i]<<"\t";
        }
        delete[] u_set;
    }
int _intersec(int arr[],int brr[],int na,int nb){
    int count=0;
    for(int i=0;i<na;i++)
    {
        for(int j=0;j<nb;j++)
    {
            if(arr[i]==brr[j]){
                count++;
                break;

            }
    }
    
}

return count;
    }
    void intersec(int arr[],int brr[],int na,int nb){
        int *p_intersec;
        int c;
        c = _intersec(arr,brr,na,nb);
        p_intersec = new int[c];
        for(int i=0;i<na;i++)
        {
            for(int j=0;j<nb;j++)
        {
                if(arr[i]==brr[j]){
                    p_intersec[i] = arr[i];
                    break;
                }
        }
        
    }
    cout<<"(AnB) = { ";
    for(int i=0;i<c-1; i++){
        
        cout<<p_intersec[i]<<", ";
    }
    
    cout<<p_intersec[i];
    cout<<"}"<<endl;
    delete[] p_intersec;
}
    void diff(int arr[],int brr[],int na,int nb){
        int count=-1;
        for(int i = 0;i<na;i++){
            for(int j =0;j<nb;j++){
                if(arr[i]==brr[j]){
                count++;
                break;
            }
            }
        }
        int dy_a = na-count;
        int *p;
        int index=0;
        p = new int[dy_a];
        for(int i = 0;i<na;i++){
            bool found = false;
            for(int j=0;j<nb;j++){
                if(arr[i]==brr[j]){
                    found = true;
                    break;
                }
            }
            if(!found){
                p[index++] = arr[i];
            }
        }
        cout<<"(A-B) = {";
        for(i=0;i<dy_a-1;i++){
            cout<<p[i]<<", ";
        }
        cout<<p[i]<<"}"<<endl;
        delete[] p;
}
int main(){
    int *a,n,choice;
    cout<<"Enter the no. of elements of set A"<<endl;
    cin>>n;
    a = new int[n];
    for(int i =0;i<n;i++){
        cout<<"A [ "<<i+1<<" ]  = ";
        cin>>a[i];
    }
    int *b,n1;
    cout<<"Enter the no. of elements of set B"<<endl;
    cin>>n1;
    b = new int[n1];
    for(int i =0;i<n1;i++){
        cout<<"B [ "<<i+1<<" ]  = ";
        cin>>b[i];
    }
   while(1) {cout<<"Enter the choice"<<endl<<"1. Union"<<endl<<"2. Intersection"<<endl<<"3. Difference"<<endl<<"4. Exit"<<endl;
            cout<<"Enter(1-4) = ";
            cin>>choice;
    switch(choice){
        case 1:
     _union(a,b,n,n1);
     break;
     case 2:
     intersec(a,b,n,n1);
     break;
     case 3:
    diff(a,b,n,n1);
     break;
     case 4:
     delete[] a;
     delete[] b;
     return 0;
     default:
     cout<<"Invalid Number Please try again!"<<endl;
    }
   }
   
}