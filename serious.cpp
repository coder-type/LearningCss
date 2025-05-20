#include<iostream>
#include<iomanip>
using namespace std;
namespace set{
    void helper(int* arr, int* brr, int na, int nb, int& count) {
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < nb; j++) {
                if (arr[i] == brr[j]) {
                    count++;
                    break;
                }
            }
        }
    }
class _union {
public:
    int flag;
    void calc(int* arr, int* brr, int na, int nb) {
        int count = 0;
        helper(arr, brr, na, nb, count);

        int size = na + nb - count;
        int* uptr = new int[size];

        int index = 0;
        // Copy all from arr[]
        for (int i = 0; i < na; i++) {
            uptr[index++] = arr[i];
        }

        // Copy from brr[] only if not in arr[]
        for (int i = 0; i < nb; i++) {
            flag = 0;
            for (int j = 0; j < na; j++) {
                if (brr[i] == arr[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                uptr[index++] = brr[i];
            }
        }

        // Print the union set
        cout << "Union = { ";
        for (int i = 0; i < index; i++) {
            cout << uptr[i];
            if (i < index - 1) cout << ", ";
        }
        cout << "}" << endl;

        delete[] uptr; // avoid memory leak
    }
};

    class _intersec{
        public:
            void calc(int* arr, int* brr, int na, int nb)
            {
                int flag,index=0;
                int count=0;
                helper(arr,brr,na,nb,count);
                int *iptr;
                iptr = new int[count];
                for(int i=0;i<na;i++)
                {
                    for(int j= 0;j<nb;j++){
                        flag =1;
                        if(arr[i]==brr[j]){
                           flag =0;
                           break; 
                        }
                    }
                    if(flag==0){
                        iptr[index++] = arr[i];
                    }
                }
                cout<<"Intersection = {";
                for (int i = 0; i < index; i++) {
            cout << iptr[i];
            if (i < index - 1) cout << ", ";
        }
        cout << " }" << endl;

        delete[] iptr;
    }
    };
    class _diff{
       public:
       int flag;
       void calc(int* arr, int* brr, int na, int nb){
        int count=0,index=0;
        helper(arr,brr,na,nb,count);
        int size = na-count;
        int *aptr;
        aptr = new int[size];
        for(int i = 0;i<na;i++){
            flag =0;
            for(int j=0;j<nb;j++){
                if(arr[i] == brr[j]){
                    flag =1;
                    break;
                }
            }
            if(flag == 0){
                aptr[index++] = arr[i];
            }
        }
        cout<<"Difference (A-B) = {";
                for (int i = 0; i < index; i++) {
            cout << aptr[i];
            if (i < index - 1) cout << ", ";
        }
        cout << " }" << endl;

        delete[] aptr;
       }
       void _calc(int* arr, int* brr, int na, int nb){
        int count=0,index=0;
        helper(arr,brr,na,nb,count);
        int size = nb-count;
        int *bptr;
        bptr = new int[size];
        for(int i = 0;i<nb;i++){
            flag =0;
            for(int j=0;j<na;j++){
                if(brr[i] == arr[j]){
                    flag =1;
                    break;
                }
            }
            if(flag == 0){
                bptr[index++] = brr[i];
            }
        }
        cout<<"Difference (B-A) = {";
                for (int i = 0; i < index; i++) {
            cout << bptr[i];
            if (i < index - 1) cout << ", ";
        }
        cout << "}" << endl;

        delete[] bptr;

       }
    };
}
int main(){
    int na,nb,*a=nullptr,*b=nullptr,choose,sub_choice;
    set::_union u;
    set::_intersec i;
    set::_diff d;
    while(1)
    {
        if(a)delete[] a;
        if(b)delete[] b;
        cout<<"-----Calculate SETS----"<<endl;
        cout<<"For example it calculates union, intersection and difference"<<endl;
        cout<<"How many elements do you want to input in set A = ";
        if(!(cin>>na)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        a = new int[na];
        cout<<"Enter the elements of set A: "<<endl;
        for(int i =0;i<na;i++){
        cout<<"a[ "<<i+1<<" ] = ";
        cin>>a[i];
    }
    cout<<"How many elements do you want to input in Set B = ";
    if(!(cin>>nb)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    b = new int[nb];
    cout<<"Enter the elements of set B: "<<endl;
    for(int i = 0; i<nb;i++){
        cout<<"b[ "<<i+1<<" ] = ";
        cin>>b[i];
    }
    while(1){
        cout<<"What do you want to do with the data you gave me"<<endl;
        cout<<"Choose either one:\n"
            <<"1. UNION\n"
            <<"2. INTERSECTION\n"
            <<"3. DIFFERENCE\n"
            <<"4. RESTART\n"
            <<"5. EXIT\n";
        cout<<"Choose (1-5) = ";
            if(!(cin>>choose)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            switch(choose){
                case 1:
                u.calc(a,b,na,nb);
                break;
                case 2:
                i.calc(a,b,na,nb);
                break;
                case 3:
                P:cout<<"Choose:'\n"
                    <<"1. A-B \n"
                    <<"2. B-A \n";
                cout<<"Your Answer(1/2) = ";
                    if(!(cin>>sub_choice)){
                        cout<<"INVALID INPUT!!";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        goto P;
                    }
                    if(sub_choice==1){
                        d.calc(a,b,na,nb);
                        
                    }
                    else{
                        d._calc(a,b,na,nb);
                        
                    }
                    break;
                    case 4:
                    cout<<"RESTARTING...."<<endl;
                    goto restart;
                    case 5:
                    cout<<"EXITING..."<<endl;
                    delete[] a;
                    delete [] b;
                    return 0;
                    default: 
                    cout<<"INVALID CASE, PLEASE TRY AGAIN!!!"<<endl;
            }
    }
    restart:;
        
    }
}