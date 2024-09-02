#include <iostream>
using namespace std;

int add_nums(int a, int b, int c){
    return a+b+c;
}

int main(){
    int a,b,c;
    cout << "Enter the first number: " << endl;
    cin >> a;

    cout << "Enter the second number: " << endl;
    cin >> b;
    
    cout << "Enter the third number: " << endl;
    cin >> c;

    cout << "The total of you numbers is: " << add_nums(a,b,c) << endl;
    return 0;
}