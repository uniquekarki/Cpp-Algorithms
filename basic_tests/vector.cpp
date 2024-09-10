#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float distance(vector<int> x0, vector<int> x1){
    return sqrt(pow(x1[1] - x0[1], 2) + pow(x1[0] - x0[0], 2));
};


int main(){
    vector<int> pt_x0 = {1,2};
    vector<int> pt_x1 = {5,6};

    cout << "Vector 1: " << pt_x0[0] << ", " << pt_x0[1] << endl;
    cout << "Vector 2: " << pt_x1[0] << ", " << pt_x1[1] << endl;
    
    float dist = distance(pt_x0,pt_x1);
    cout << "Distance between vector 1 and 2 = " << dist << endl;
    return 0;
}