#include <iostream>
using namespace std;

template <typename T>
class Generic_Class{
    T a,b;
    public:
        Generic_Class(T x, T y){
            a = x;
            b = y;
        }
        T add(){
            return a+b;
        }
};
int main() {
    Generic_Class<int> gc1(4,5);
    cout<<gc1.add();
    Generic_Class<float> gc2(4.3,5.4);
    cout<<gc2.add();

    return 0;
}

#include <iostream>
using namespace std;


template <typename T> 
T add(T a, T b) { return a + b; }

int main() {
    cout << add(5, 10) << endl;      
    cout << add(5.5, 2.3) << endl;   
    return 0;
}
