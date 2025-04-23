#include <iostream>
using namespace std;

class classname{

};
int main() {
    int num,deno,result;
    cout<<"Enter values for Numerator and Denominator"<<endl;
    cin>>num>>deno;
    try{
        if(deno == 0){
            throw(deno);
        }
        result = num / deno;
    }
    catch(int ex){
        cout<<"Exception: Denomintor can not be 0"<<endl;
        result = 0;
    }
    
    cout<<"Result is : "<<result<<endl;

    return 0;
}
