#include <iostream>
using namespace std;

void add_str(string a, string b, string c){
    string x;
    if(c=="M"){
        c = "Mr.";
    }
    else{
        c = "Ms.";
    }
    cout << "Pleased to meet you: " << c+ " " + a + " " + b << endl;
}

int main(){
    string fname, lname, gender;
    cout << "Enter you first name: ";
    cin >> fname;

    cout << "Enter you last name: ";
    cin >> lname;

    cout << "Enter you gender(M/F): ";
    cin >> gender;
    
    add_str(fname, lname, gender);
    return 0;
}